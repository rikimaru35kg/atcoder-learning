from random import randint as randi


def f_NAB(N, A_MAX, B_MAX, lat=True):
    a = [randi(1, A_MAX) for _ in range(N)]
    b = [randi(1, B_MAX) for _ in range(N)]

    print(N)
    if lat:
        print(*a)
        print(*b)
    else:
        for i in range(N):
            print(a[i], b[i])
