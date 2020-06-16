#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAME 10
#define STRIKE 0
#define SPARE 1
#define NONE 2

struct frame {
    int first;
    int second;
    int result;
    int score;
    int total;
    struct frame *next;
};

typedef struct frame * f_ptr;
f_ptr head = NULL;

void createFrameNode() {
    f_ptr p = (f_ptr)malloc(sizeof(struct frame));
    if (head->next == NULL) {
        head->next = p;
        p->next = NULL;
    } else {
        p->next = head->next;
        head->next = p;
    }
    p->first = -1;
    p->second = -1;
    p->result = -1;
    p->score = 0;
    p->total = 0;
}

void initFrameNode() {
    head = (f_ptr)malloc(sizeof(struct frame));
    head->next = NULL;
    for (int i = 0; i < MAX_FRAME+1; i++)
        createFrameNode();
}

int score_calc(f_ptr p) {
    if (p->result == NONE) {
        return p->score;
    } else if (p->result == STRIKE) {
        if (p->next->result == STRIKE) {
            if (p->next->next->first != -1)
                return p->score;
        } else {
            if (p->next->first != -1 && p->next->second != -1)
                return p->score;
        }
        return -1;
    } else { // SPARE
        if (p->next->first != -1)
            return p->score;
        return -1;
    }
    return 0;
}

int main() {
    initFrameNode();
    f_ptr pprev_ptr = head;
    f_ptr prev_ptr = head;
    f_ptr ptr = head->next;
    
    printf("______                   _  _\n");
    printf("| ___ \\                 | |(_)\n");
    printf("| |_/ /  ___  __      __| | _  _ __    __ _\n");
    printf("| ___ \\ / _ \\ \\ \\ /\\ / /| || || '_ \\  / _` |\n");
    printf("| |_/ /| (_) | \\ V  V / | || || | | || (_| |\n");
    printf("\\____/  \\___/   \\_/\\_/  |_||_||_| |_| \\__, |\n");
    printf("=========================================/ |\n");
    printf("made by Suyeon Nam                    |___/\n");
    
    for (int i = 0; i < MAX_FRAME+1; i++) {
        if (ptr != head->next)
            ptr->total += prev_ptr->total;
        if (i != MAX_FRAME) {
            printf("Enter frame %d's score(example : 7 3): ", i+1);
        } else {
            printf("Enter bonus frame's score: ");
        }
        scanf("%d %d", &ptr->first, &ptr->second);
        
        if (i != MAX_FRAME) {
            ptr->score = ptr->first + ptr->second;
            ptr->total += ptr->score;
        }
        if (i != 0 && prev_ptr->result == STRIKE) { // 전 프레임에서 스트라이크를 친 경우 전 프레임의 점수에 현 프레임의 first, second 점수를 더해줌
            prev_ptr->score += ptr->first + ptr->second;
            prev_ptr->total += ptr->first + ptr->second;
            ptr->total += ptr->first + ptr->second;
            if (i != 1 && pprev_ptr->result == STRIKE) { // 전전 프레임과 전 프레임에서 연속으로 스트라이크를 친 경우(double) 전전 프레임의 점수에 현 프레임의 first 점수를 더해줌
                pprev_ptr->score += ptr->first;
                pprev_ptr->total += ptr->first;
                prev_ptr->total += ptr->first;
                ptr->total += ptr->first;
            }
        } else if (i != 0 && prev_ptr->result == SPARE) { // 전 프레임에서 스페어를 친 경우 전 프레임의 점수에 현 프레임의 first 점수를 더해줌
            prev_ptr->score += ptr->first;
            prev_ptr->total += ptr->first;
            ptr->total += ptr->first;
        }
        if (i != MAX_FRAME){
            if (ptr->first == 10) {
                ptr->result = STRIKE;
                printf("STRIKE!\n");
            } else if ((ptr->first + ptr->second) == 10) {
                ptr->result = SPARE;
                printf("SPARE!\n");
            } else {
                ptr->result = NONE;
            }
        }
        printf("===================== SCORE BOARD ======================\n");
        f_ptr p = head->next;
        int cnt = 1;
        while (p && p->first != -1) {
            if (cnt != 11) { // 일반 프레임
                printf("FRAME %d : %d / %d\t\t%s| SCORE : ", cnt, p->first, p->second, (p->result == STRIKE) ? "STRIKE" : (p->result == SPARE) ? "\tSPARE " : (cnt == 10) ? "\t  " : "\t\t  ");
                if (score_calc(p) != -1) {
                    printf("%2d | TOTAL : %d\n", score_calc(p), p->total);
                } else { // 계산에 필요한 값이 모두 입력되지 않은 경우 점수 대신 '-' 출력
                    printf(" - | TOTAL : - \n");
                }
            } else { // 보너스 프레임
                printf("BONUS FRAME : %d / %d\n", p->first, p->second);
            }
            p = p->next;
            cnt++;
        }
        printf("========================================================\n");
        // 프레임 10에서 스트라이크나 스페어를 치지 못한 경우 보너스 프레임 없음
        if (i == MAX_FRAME-1 && (ptr->result != STRIKE && ptr->result != SPARE))
            break;
        pprev_ptr = prev_ptr;
        prev_ptr = ptr;
        ptr = ptr->next;
    }
    f_ptr p = head->next;
    while (p->next->total != 0)
        p = p->next;
    printf("===================== TOTAL : %4d =====================\n", p->total);
    return 0;
}
