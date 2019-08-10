def mean(x) :
    return sum(x) / len(x)


def median(x) :
    n = len(x)
    x.sort()
    mid = n // 2

    if n % 2 == 1 :
        return x[mid]
    else :
        return (x[mid - 1] + x[mid]) / 2
