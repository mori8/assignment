#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 10
#define NORMAL 0
#define EDGE 1
#define START 2
#define CENTER 3

typedef struct node {
    int type;   // 0: NORMAL, 1: EDGE, 2: START, 3: CENTER
    int x;      // 노드의 말판 상 x좌표
    int y;      // 노드의 말판 상 y좌표
    struct node* prev;          // 이전 노드
    struct node* next;          // 다음 노드
    struct node* fast_next;     // 지름길로 이어진 다음 노드
    struct node* fast_prev;     // 지름길로 이어진 이전 노드
} Node;

typedef Node* n_ptr;
n_ptr head = NULL;
n_ptr start = NULL;
n_ptr first_edge = NULL;
n_ptr second_edge = NULL;
n_ptr third_edge = NULL;
n_ptr center_node = NULL;
n_ptr end_node = NULL;
n_ptr dump_node = NULL;

typedef struct player {
    n_ptr mal1;         // 첫번째 말(노드) 포인터
    n_ptr mal2;         // 두번째 말(노드) 포인터
    n_ptr mal3;         // 세번째 말(노드) 포인터
    int ended_mal;      // 끝난 말 개수
    int playing_mal;    // 끝나지 않은 말 개수
} Player;

typedef Player* p_ptr;

p_ptr p1;
p_ptr p2;

void init_player() { // 플레이어 구조체 초기화
    p1 = (p_ptr)malloc(sizeof(Player));
    p1->mal1 = start;
    p1->mal2 = start;
    p1->mal3 = start;
    p1->ended_mal = 0;
    p1->playing_mal = 3;

    p2 = (p_ptr)malloc(sizeof(Player));
    p2->mal1 = start;
    p2->mal2 = start;
    p2->mal3 = start;
    p2->ended_mal = 0;
    p2->playing_mal = 3;
}

n_ptr* player_mal(p_ptr p, int n) { // 플레이어, 이동할 말의 번호를 입력하면 해당하는 말의 주소를 리턴하는 함수
    dump_node = (n_ptr)malloc(sizeof(Node)); // 에러 방지를 위해 1, 2, 3 외의 값이 들어왔을 때 임의의 노드를 생성해 리턴하게 한다
    switch (n) {
    case 1: return &(p->mal1);
    case 2: return &(p->mal2);
    case 3: return &(p->mal3);
    default: return &dump_node;
    }
}

void init_node() { // 말판을 초기화하는 함수
    head = (n_ptr)malloc(sizeof(Node));
    end_node = (n_ptr)malloc(sizeof(Node)); // 종료 노드
    start = (n_ptr)malloc(sizeof(Node));
    start->type = START;
    n_ptr n = (n_ptr)malloc(sizeof(Node));
    start->next = n;
    n->prev = start;
    n->type = NORMAL;

    for (int i = 0; i < 19; i++) { // 판의 테두리 말 초기화
        if (i == 18) {
            n->type = NORMAL;
            n->next = start;
            start->prev = n;
        } else {
            n_ptr tmp = (n_ptr)malloc(sizeof(Node));
            n->next = tmp;
            tmp->prev = n;
            if (i % 5 == 4) {
                n->type = EDGE;
                switch (i) {
                case 4: first_edge = n; break;
                case 9: second_edge = n; break;
                case 14: third_edge = n; break;
                default: break;
                }
            } else {
                n->type = NORMAL;
            }
            n = n->next;
        }
    }
    // 좌측 하단 모서리에서 우측 상단 모서리 노드 초기화
    n_ptr tmp = (n_ptr)malloc(sizeof(Node));
    first_edge->fast_next = tmp;
    tmp->type = NORMAL;
    tmp->prev = first_edge;
    n_ptr tmp2 = (n_ptr)malloc(sizeof(Node));
    tmp->next = tmp2;
    tmp2->type = NORMAL;
    tmp2->prev = tmp;
    center_node = (n_ptr)malloc(sizeof(Node));
    tmp2->next = center_node;
    center_node->type = CENTER;
    center_node->fast_prev = tmp2;
    n_ptr tmp4 = (n_ptr)malloc(sizeof(Node));
    center_node->next = tmp4;
    tmp4->type = NORMAL;
    tmp4->prev = center_node;
    n_ptr tmp5 = (n_ptr)malloc(sizeof(Node));
    tmp4->next = tmp5;
    tmp5->type = NORMAL;
    tmp5->prev = tmp4;
    tmp5->next = third_edge;
    third_edge->fast_prev = tmp5;
    // 우측 하단 모서리에서 좌측 상단 모서리 노드 초기화
    n_ptr tmp6 = (n_ptr)malloc(sizeof(Node));
    second_edge->fast_next = tmp6;
    tmp6->type = NORMAL;
    tmp6->prev = second_edge;
    n_ptr tmp7 = (n_ptr)malloc(sizeof(Node));
    tmp6->next = tmp7;
    tmp7->type = NORMAL;
    tmp7->prev = tmp6;
    tmp7->next = center_node;
    center_node->prev = tmp7;
    n_ptr tmp8 = (n_ptr)malloc(sizeof(Node));
    center_node->fast_next = tmp8;
    tmp8->type = NORMAL;
    tmp8->prev = center_node;
    n_ptr tmp9 = (n_ptr)malloc(sizeof(Node));
    tmp8->next = tmp9;
    tmp9->type = NORMAL;
    tmp9->prev = tmp8;
    tmp9->next = start;
    start->fast_prev = tmp9;

    head->next = start;
    head->prev = head->prev;
    head->fast_prev = head->fast_prev;
    start->fast_prev->next = head;
    start->fast_prev = NULL;
    start->prev->next = head;
    start->prev = head;
}


void init_xy() { // 말판을 구성하는 각 노드의 말판 상 x, y 좌표 설정
    n_ptr p = start;
    int x = 1;
    int y = 0;
    for (int i = 0; i < 5; i++) {
        p->x = x; p->y = y;
        if (y == 2) { y += 2; }
        else { y++; }
        p = p->next;
    }
    for (int i = 0; i < 5; i++) {
        p->x = x; p->y = y;
        x += 3;
        p = p->next;
    }
    for (int i = 0; i < 5; i++) {
        p->x = x; p->y = y;
        if (y == 4) { y -= 2; }
        else { y--; }
        p = p->next;
    }
    for (int i = 0; i < 5; i++) {
        p->x = x; p->y = y;
        x -= 3;
        p = p->next;
    }
    // 안쪽 노드 좌표 부여
    p = second_edge->fast_next;
    x = 13; y = 5;
    for (int i = 0; i < 5; i++) {
        if (p == center_node) {
            p->x = 8; p->y = 3;
            y--;
            p = p->fast_next;
        } else {
            p->x = x; p->y = y;
            p = p->next;
            x -= 3; y--;
        }
    }
    p = first_edge->fast_next;
    x = 4; y = 5;
    for (int i = 0; i < 5; i++) {
        if (p == center_node) {
            p = p->next; y--;
        } else {
            p->x = x; p->y = y;
            p = p->next;
            x += 3; y--;
        }
    }
    end_node->x = start->x; end_node->y = start->y;
}

char* itokor(int i) {  // throw_yoot에서 생성한 난수를 한글로 바꿔주는 함수
    switch (i) {
    case -1: return "백도"; break;
    case 1: return "도"; break;
    case 2: return "개"; break;
    case 3: return "걸"; break;
    case 4: return "윷"; break;
    case 5: return "모"; break;
    default: return " "; break;
    }
}

int throw_yoot() { // -1 ~ 5 사이의 난수값을 생성하는 함수
    int yoot = rand() % 6 + 1;
    if (yoot == 6) { // 백도
        printf("%s! ", itokor(-1));
        return -1;
    }
    printf("%s! ", itokor(yoot));
    return yoot;
}

void show_score() { // 각 플레이어의 통과한 말, 남은 말의 개수를 보여주는 함수
    printf("-----------------------------------------------------------\n");
    printf("* 플레이어 1의 통과한 말의 수/남은 말의 수: %d/%d\n", p1->ended_mal, p1->playing_mal);
    printf("* 플레이어 2의 통과한 말의 수/남은 말의 수: %d/%d\n", p2->ended_mal, p2->playing_mal);
    printf("-----------------------------------------------------------\n");
}

void show_board() { // 말판을 출력하는 함수
    char board[8][19] = {
        { " O  O  O  O  O  O \n" },
        { " O  O        O  O \n" },
        { " O     O  O     O \n" },
        { "        O         \n" },
        { " O     O  O     O \n" },
        { " O  O        O  O \n" },
        { " O  O  O  O  O  O \n" }
    };
    // Player 1 말 위치 설정
    if (p1->mal1 == p1->mal2 && p1->mal1 == p1->mal3) { // 말 3개가 업힌 경우
        board[p1->mal1->y][p1->mal1->x - 1] = 'A';
        board[p1->mal1->y][p1->mal1->x] = 'B';
        board[p1->mal1->y][p1->mal1->x + 1] = 'C';
    } else if (p1->mal1 == p1->mal2) {                  // A와 B가 업힌 경우
        board[p1->mal1->y][p1->mal1->x] = 'A';
        board[p1->mal1->y][p1->mal1->x + 1] = 'B';
        board[p1->mal3->y][p1->mal3->x] = 'C';
    } else if (p1->mal1 == p1->mal3) {                  // A와 C가 업힌 경우
        board[p1->mal1->y][p1->mal1->x] = 'A';
        board[p1->mal2->y][p1->mal2->x] = 'B';
        board[p1->mal1->y][p1->mal1->x + 1] = 'C';
    } else if (p1->mal2 == p1->mal3) {                  // B와 C가 업힌 경우
        board[p1->mal1->y][p1->mal1->x] = 'A';
        board[p1->mal2->y][p1->mal2->x] = 'B';
        board[p1->mal2->y][p1->mal2->x + 1] = 'C';
    } else {
        board[p1->mal1->y][p1->mal1->x] = 'A';
        board[p1->mal2->y][p1->mal2->x] = 'B';
        board[p1->mal3->y][p1->mal3->x] = 'C';
    }
    // Player 2 말 위치 설정
    if (p2->mal1 == p2->mal2 && p2->mal1 == p2->mal3) { // 말 3개가 업힌 경우
        board[p2->mal1->y][p2->mal1->x - 1] = 'X';
        board[p2->mal1->y][p2->mal1->x] = 'Y';
        board[p2->mal1->y][p2->mal1->x + 1] = 'Z';
    } else if (p2->mal1 == p2->mal2) {                  // A와 B가 업힌 경우
        board[p2->mal1->y][p2->mal1->x] = 'X';
        board[p2->mal1->y][p2->mal1->x + 1] = 'Y';
        board[p2->mal3->y][p2->mal3->x] = 'Z';
    } else if (p2->mal1 == p2->mal3) {                  // A와 C가 업힌 경우
        board[p2->mal1->y][p2->mal1->x] = 'X';
        board[p2->mal2->y][p2->mal2->x] = 'Y';
        board[p2->mal1->y][p2->mal1->x + 1] = 'Z';
    } else if (p2->mal2 == p2->mal3) {                  // B와 C가 업힌 경우
        board[p2->mal1->y][p2->mal1->x] = 'X';
        board[p2->mal2->y][p2->mal2->x] = 'Y';
        board[p2->mal2->y][p2->mal2->x + 1] = 'Z';
    } else {
        board[p2->mal1->y][p2->mal1->x] = 'X';
        board[p2->mal2->y][p2->mal2->x] = 'Y';
        board[p2->mal3->y][p2->mal3->x] = 'Z';
    }
    // 말이 start에 있는 경우 보드에 표시하지 않음
    board[0][0] = ' ';
    board[0][1] = 'O';
    board[0][2] = ' ';

    printf("↓ start\n");
    printf("%s\n", board);
}

// movement : 말을 움직이는 함수
// return value -1: 백도가 나왔는데 판 위에 놓인 말이 없는 경우
// return value 1: 말 한 개가 종료 노드에 도착한 경우
// return value 0: 별다른 이벤트 없이 말이 이동을 마친 경우
// return value 2: 세 말 모두 종료 노드에 도착한 경우
// return value 3 ~ 5: 말들이 업힌 채로 종료 노드에 도착한 경우
// return value 6: 상대방 말을 잡은 경우
int movement(p_ptr p, n_ptr *mal, int m, int flag) {
    // 플레이어, 이동할 말, 이동할 칸 수, flag: 윷, 모만큼 이동해야 할 때와 윷, 모가 나왔을 때 반복해서 윷 던저야 할 때를 분리하기 위한 변수.
    // flag == 0 : 백도 ~ 걸만큼 이동해야 하거나, 윷이나 모가 나와서 반복해서 윷을 던져야 할 때
    // flag == 1 : 윷, 모만큼 이동해야 할 때
    p_ptr otherp = NULL;
    if (p == p1) otherp = p2;
    else if (p == p2) otherp = p1;

    if (m == -1) {  // 백도
        if (p->mal1 == start && p->mal2 == start && p->mal3 == start) // 판 위에 놓인 말이 없는 경우
            return -1;
        if (*mal == start || *mal == end_node) { // 놓이지 않은 말을 뒤로 이동시키려 하는 경우
            while (*mal == start || *mal == end_node) {
                printf("그 말은 뒤로 이동할 수 없습니다. 이동할 말을 다시 입력해 주세요. :");
                int tmp;
                scanf("%d", &tmp);
                mal = player_mal(p, tmp);
            }
        }
        if ((*mal != start) && (*mal == p->mal1 && *mal == p->mal2 && *mal == p->mal3)) {      // 말 3개가 업힌 경우
            p->mal1 = p->mal1->prev;
            p->mal2 = p->mal2->prev;
            p->mal3 = p->mal3->prev;
        } else if ((*mal != start) && (*mal == p->mal1 && *mal == p->mal2)) {                  // 1과 2가 업힌 경우
            p->mal1 = p->mal1->prev;
            p->mal2 = p->mal2->prev;
        } else if ((*mal != start) && (*mal == p->mal1 && *mal == p->mal3)) {                  // 1과 3이 업힌 경우
            p->mal1 = p->mal1->prev;
            p->mal3 = p->mal3->prev;
        } else if ((*mal != start) && (*mal == p->mal2 && *mal == p->mal3)) {                  // 2와 3이 업힌 경우
            p->mal2 = p->mal2->prev;
            p->mal3 = p->mal3->prev;
        } else {
            *mal = (*mal)->prev;
        }
    }
    else if (flag == 0 && (m == 4 || m == 5)) { // 윷, 모가 나와서 반복해서 윷을 던져야 하는 경우
        if (*mal == end_node) { // 종료 노드에 도착한 말을 이동시키려 할 때 종료 노드에 도착하지 않은 다른 말을 입력받도록 함
            while (*mal == end_node) {
                printf("그 말은 이미 종료 노드에 도착했기 때문에 이동할 수 없습니다. 이동할 말을 다시 입력해 주세요. :");
                int tmp;
                scanf("%d", &tmp);
                mal = player_mal(p, tmp);
            }
        }
        int buff[MAX_LENGTH] = { 0, }; // 던진 윷값을 저장할 배열
        buff[0] = m;
        int i = 0;  // buff의 크기
        int tmp = 0;
        int yoot = 0;
        do { // 윷이나 모가 아닌 윷이 나올 때까지 윷을 던지고 buff 배열에 저장한다.
            tmp = throw_yoot();
            buff[++i] = tmp;
        } while (tmp == 4 || tmp == 5);

        for (int j = 0; j < i + 1; j++) {
            printf("\n이동할 칸 수를 입력하세요. 이동 가능한 칸 수 (");
            for (int k = 0; k < i + 1; k++) {
                if (buff[k] != 0) {
                    printf("%d ", buff[k]);
                }
            }
            printf(") : ");

            while (1) {
                scanf("%d", &yoot);
                int k = 0;
                for (k = 0; k < i + 1; k++) {  // 던진 윷값 중 입력받은 윷값이 있는지 확인
                    if (buff[k] == yoot)
                        break;
                }
                if (yoot == -1 && (p->mal1 == start || p->mal1 == end_node) && (p->mal2 == start || p->mal2 == end_node) && (p->mal3 == start || p->mal3 == end_node)) {
                    return -1; // 백도가 나왔는데 말판에 놓인 말이 없는 경우 -1을 리턴하고 함수 종료
                }
                if (k > i) { // 던진 윷값 중 입력받은 윷값이 없는 경우 다시 입력받도록 함
                    printf("그렇게는 이동할 수 없습니다. 이동할 칸 수를 다시 입력하세요. 이동 가능한 칸 수 (");
                    for (int k = 0; k < i + 1; k++) {
                        if (buff[k] != 0) {
                            printf("%d ", buff[k]);
                        }
                    }
                    printf(") : ");
                }
                else break;
            }
            int num;
            printf("움직일 말의 번호를 입력하세요. 현재 움직일 수 있는 말 (");
            if (yoot == -1) {
                if (p->mal1 != end_node && p->mal1 != start) printf("1 ");
                if (p->mal2 != end_node && p->mal2 != start) printf("2 ");
                if (p->mal3 != end_node && p->mal3 != start) printf("3 ");
            }
            else {
                if (p->mal1 != end_node) printf("1 ");
                if (p->mal2 != end_node) printf("2 ");
                if (p->mal3 != end_node) printf("3 ");
            }
            printf(") : ");
            scanf("%d", &num);

            n_ptr* pmal = player_mal(p, num);

            if (yoot == -1 && *mal == start) { // 놓이지 않은 말을 뒤로 이동시키려 하는 경우 다시 입력받오록 함
                while (*mal == start || *mal == end_node) {
                    printf("그 말은 뒤로 이동할 수 없습니다. 이동할 말을 다시 입력해 주세요. : ");
                    int tmp;
                    scanf("%d", &tmp);
                    *mal = *player_mal(p, tmp);
                }
            }

            int index = 0;
            for (index = 0; index < i; index++) {
                if (yoot == buff[index])
                    break;
            }
            int dump = movement(p, pmal, yoot, 1);
            if (dump >= 1 && dump <= 6) {
                dump_node = start;
                if (dump == 2) {                         // 말 3개가 업힌 경우
                    p->mal1 = p->mal2 = p->mal3 = end_node;
                    p->ended_mal += 3;
                    p->playing_mal -= 3;
                } else if (dump == 3) {                  // 1과 2가 업힌 경우
                    p->mal1 = p->mal2 = end_node;
                    p->ended_mal += 2;
                    p->playing_mal -= 2;
                    printf("            ** 1, 2번째 말 종료 노드 도착! **\n");
                } else if (dump == 4) {                  // 1과 3이 업힌 경우
                    p->mal1 = p->mal3 = end_node;
                    p->ended_mal += 2;
                    p->playing_mal -= 2;
                    printf("            ** 1, 3번째 말 종료 노드 도착! **\n");
                } else if (dump == 5) {                  // 2와 3이 업힌 경우
                    p->mal2 = p->mal3 = end_node;
                    p->ended_mal += 2;
                    p->playing_mal -= 2;
                    printf("            ** 2, 3번째 말 종료 노드 도착! **\n");
                } else if (dump == 1) {
                    *pmal = end_node;
                    p->ended_mal += 1;
                    p->playing_mal -= 1;
                    printf("              ** %d번째 말 종료 노드 도착! **\n", num);
                } else if (dump == 6) {
                    printf("              ** 상대방의 말을 잡았습니다. **\n");
                }
                show_score();
            }
            else if (dump == -1) return -1;
            if (p->mal1 == end_node && p->mal2 == end_node && p->mal3 == end_node)
                return 2;
            buff[index] = 0;  // 이동한 윷값은 0으로 바꿔줌으로써 이동했다는 것을 기록
        }
    }
    else { // flag == 1 or 1 <= m =< 3, 말 이동
        if (*mal == end_node) {
            while (*mal == end_node) {
                printf("그 말은 이미 종료 노드에 도착했기 때문에 이동할 수 없습니다. 이동할 말을 다시 입력해 주세요. :");
                int tmp;
                scanf("%d", &tmp);
                mal = player_mal(p, tmp);
            }
        }
        if ((*mal != start) && (*mal == p->mal1 && *mal == p->mal2 && *mal == p->mal3)) { // 말 3개가 업힌 경우
            if (((*mal)->type == EDGE && *mal != third_edge) || (*mal)->type == CENTER) *mal = (*mal)->fast_next; // 모서리 노드에서 출발하는 경우 -> 지름길로
            else *mal = (*mal)->next; // 일반 노드에서 출발하는 경우
            for (int i = 0; i < m; i++) {
                p->mal1 = p->mal2 = p->mal3 = *mal;
                if (*mal == head) return 2;   // 종료 노드에 도착한 경우 movement() 종료
                if (i == m - 1) break;        // 마지막 반복에서 한 번 더 이동하는 것을 막기 위해 break로 빠져나옴
                if (*mal == center_node->prev && (m > 1 && i < m - 2)) { // 오른쪽 아래 모서리에서 왼쪽 위 모서리로 이동하기 위한 예외처리
                    *mal = center_node->fast_next; i++;
                } else {
                    *mal = (*mal)->next;
                }
            }
        }
        else if ((*mal != start) && (*mal == p->mal1 && *mal == p->mal2)) {                  // 1과 2가 업힌 경우
            if (((*mal)->type == EDGE && *mal != third_edge) || (*mal)->type == CENTER) *mal = (*mal)->fast_next;
            else *mal = (*mal)->next;
            for (int i = 0; i < m; i++) {
                p->mal1 = p->mal2 = *mal;
                if (*mal == head) return 3;
                if (i == m - 1) break;
                if (*mal == center_node->prev && (m > 1 && i < m - 2)) {
                    *mal = center_node->fast_next; i++;
                } else {
                    *mal = (*mal)->next;
                }
            }
        }
        else if ((*mal != start) && (*mal == p->mal1 && *mal == p->mal3)) {                  // 1과 3이 업힌 경우
            if (((*mal)->type == EDGE && *mal != third_edge) || (*mal)->type == CENTER) *mal = (*mal)->fast_next;
            else *mal = (*mal)->next;
            for (int i = 0; i < m; i++) {
                p->mal1 = p->mal3 = *mal;
                if (*mal == head) return 4;
                if (i == m - 1) break;
                if (*mal == center_node->prev && (m > 1 && i < m - 2)) {
                    *mal = center_node->fast_next; i++;
                } else {
                    *mal = (*mal)->next;
                }
            }
        }
        else if ((*mal != start) && (*mal == p->mal2 && *mal == p->mal3)) {                  // 2와 3이 업힌 경우
            if (((*mal)->type == EDGE && *mal != third_edge) || (*mal)->type == CENTER) *mal = (*mal)->fast_next;
            else *mal = (*mal)->next;
            for (int i = 0; i < m; i++) {
                p->mal2 = p->mal3 = *mal;
                if (*mal == head) return 5;
                if (i == m - 1) break;
                if (*mal == center_node->prev && (m > 1 && i < m - 2)) {
                    *mal = center_node->fast_next; i++;
                } else {
                    *mal = (*mal)->next;
                }
            }
        }
        else {
            if (((*mal)->type == EDGE && *mal != third_edge) || (*mal)->type == CENTER) *mal = (*mal)->fast_next;
            else *mal = (*mal)->next;
            for (int i = 0; i < m; i++) {
                if (*mal == head) return 1;
                if (i == m - 1) break;
                if (*mal == center_node->prev && (m > 1 && i < m - 2)) {
                    *mal = center_node->fast_next; i++;
                } else {
                    *mal = (*mal)->next;
                }
            }
        }
    }
    // 말 잡기
    if (*mal != start && *mal != end_node) {
        if (*mal == otherp->mal1 && *mal == otherp->mal2 && *mal == otherp->mal3) { // 말 3개가 업힌 경우
            otherp->mal1 = otherp->mal2 = otherp->mal3 = start; show_board(); return 6;
        } else if (*mal == otherp->mal1 && *mal == otherp->mal2) {                  // 1과 2가 업힌 경우
            otherp->mal1 = otherp->mal2 = start; show_board(); return 6;
        } else if (*mal == otherp->mal1 && *mal == otherp->mal3) {                  // 1과 3이 업힌 경우
            otherp->mal1 = otherp->mal3 = start; show_board(); return 6;
        } else if (*mal == otherp->mal2 && *mal == otherp->mal3) {                  // 2와 3이 업힌 경우
            otherp->mal2 = otherp->mal3 = start; show_board(); return 6;
        } else {
            if (*mal == otherp->mal1) { otherp->mal1 = start; show_board(); return 6; }
            else if (*mal == otherp->mal2) { otherp->mal2 = start; show_board(); return 6; }
            else if (*mal == otherp->mal3) { otherp->mal3 = start; show_board(); return 6; }
        }
    }
    if (flag == 1 || ((1 <= m && m <= 3) || m == -1)) { // 점수판, 말판 중복 출력을 막기 위한 조건
        show_score(); // 점수판 출력
        show_board(); // 말판 출력
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL)); // 규칙성 없는 난수 생성을 위해 srand() 설정
    init_node();
    init_player();
    init_xy();

    printf("__   __               _    _____\n");
    printf("\\ \\ / /              | |  |  __ \\\n");
    printf(" \\ V /   ___    ___  | |_ | |  \\/  __ _  _ __ ___    ___\n");
    printf("  \\ /   / _ \\  / _ \\ | __|| | __  / _` || '_ ` _ \\  / _ \\\n");
    printf("  | |  | (_) || (_) || |_ | |_\\ \\| (_| || | | | | ||  __/\n");
    printf("  \\_/   \\___/  \\___/  \\__| \\____/ \\__,_||_| |_| |_| \\___|\n");
    printf("===================================================================\n");
    printf("윷놀이를 시작합니다.                             made by Suyeon Nam.\n");
    printf("===================================================================\n\n");
    p_ptr now_p = p1;
    while (1) {
        p_ptr other_p;
        if (now_p == p1) {
            printf("플레이어 1이 윷을 던집니다. : ");
            other_p = p2;
        } else {
            printf("플레이어 2가 윷을 던집니다. : ");
            other_p = p1;
        }
        int m = throw_yoot(); // 윷 던지기
        int num = 0;  // 움직일 말의 번호

        if (m != -1 && m < 4) {
            printf("\n움직일 말의 번호를 입력하세요. 현재 움직일 수 있는 말 (");
            if (now_p->mal1 != end_node) printf("1 ");
            if (now_p->mal2 != end_node) printf("2 ");
            if (now_p->mal3 != end_node) printf("3 ");
            printf(") : ");
            scanf("%d", &num);
        } else if (m == -1) {
            if ((now_p->mal1 == start || now_p->mal1 == end_node) && (now_p->mal2 == start || now_p->mal2 == end_node) && (now_p->mal3 == start || now_p->mal3 == end_node)) { // 백도가 나왔는데 움직일 수 있는 말이 없는 경우
                printf("\n움직일 수 있는 말이 없습니다. 다음 플레이어의 순서로 넘어갑니다.\n");
                printf("===========================================================\n");
                now_p = other_p;
                continue;
            }
            printf("\n움직일 말의 번호를 입력하세요. 현재 움직일 수 있는 말 (");
            if (now_p->mal1 != end_node && now_p->mal1 != start) printf("1 ");
            if (now_p->mal2 != end_node && now_p->mal2 != start) printf("2 ");
            if (now_p->mal3 != end_node && now_p->mal3 != start) printf("3 ");
            printf(") : ");
            scanf("%d", &num);
        }
        n_ptr* mal = player_mal(now_p, num);
        int check = movement(now_p, mal, m, 0);
        if (check == -1) {
            printf("움직일 수 있는 말이 없습니다. 다음 플레이어의 순서로 넘어갑니다.\n");
            printf("===========================================================\n");
            now_p = other_p;
            continue;
        }
        if (check >= 1 && check <= 6) {
            dump_node = start;
            if (check == 2) {               // 말 3개가 업혀서 종료 노드에 도착한 경우
                now_p->mal1 = now_p->mal2 = now_p->mal3 = end_node;
                if (now_p->ended_mal == 0 && now_p->playing_mal == 3) {
                    now_p->ended_mal += 3;
                    now_p->playing_mal -= 3;
                }
                printf("          ** 1, 2, 3번째 말 종료 노드 도착! **\n");
            } else if (check == 3) {        // 1과 2가 업혀서 종료 노드에 도착한 경우
                now_p->mal1 = now_p->mal2 = end_node;
                if (now_p->ended_mal <= 1 && now_p->playing_mal >= 2) {
                    now_p->ended_mal += 2;
                    now_p->playing_mal -= 2;
                }
                printf("            ** 1, 2번째 말 종료 노드 도착! **\n");
            } else if (check == 4) {        // 1과 3가 업혀서 종료 노드에 도착한 경우
                now_p->mal1 = now_p->mal3 = end_node;
                if (now_p->ended_mal <= 1 && now_p->playing_mal >= 2) {
                    now_p->ended_mal += 2;
                    now_p->playing_mal -= 2;
                }
                printf("            ** 1, 3번째 말 종료 노드 도착! **\n");
            } else if (check == 5) {        // 2과 3가 업혀서 종료 노드에 도착한 경우
                now_p->mal2 = now_p->mal3 = end_node;
                if (now_p->ended_mal <= 1 && now_p->playing_mal >= 2) {
                    now_p->ended_mal += 2;
                    now_p->playing_mal -= 2;
                }
                printf("            ** 2, 3번째 말 종료 노드 도착! **\n");
            } else if (num != 0 && check == 1) {
                *mal = end_node;
                if (now_p->ended_mal <= 2 && now_p->playing_mal >= 1) {
                    now_p->ended_mal += 1;
                    now_p->playing_mal -= 1;
                }
                printf("              ** %d번째 말 종료 노드 도착! **\n", num);
            }
            if (check == 6) {
                printf("      ** 상대방의 말을 잡았습니다. 윷을 다시 던집니다. **\n");
                continue;
            }
            // 게임 종료 조건 - 모든 말이 종료 노드를 통과했을 때
            if (((now_p->mal1 == end_node) && (now_p->mal2 == end_node) && (now_p->mal3 == end_node)) || check == 2) {
                printf("=========================최종 점수==========================\n");
                show_score();
                printf("===========================================================\n");

                if (now_p == p1) printf("플레이어 1의 승리! 축하드립니다.\n");
                else if (now_p == p2) printf("플레이어 2의 승리! 축하드립니다.\n");
                break;
            }
        } else if (check == -1) {
            printf("현재 놓인 말이 없습니다.");
        }
        printf("다음 플레이어의 순서로 넘어갑니다.\n");
        printf("=====================================================\n");
        now_p = other_p;
    }
    system("pause");
    return 0;
}
