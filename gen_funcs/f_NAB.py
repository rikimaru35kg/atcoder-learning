from random import randint as randi


def f_NAB(N:int, A_RNG:tuple, B_RNG:tuple, lat:bool=True):
    a = [randi(A_RNG[0], A_RNG[1]) for _ in range(N)]
    b = [randi(B_RNG[0], B_RNG[1]) for _ in range(N)]

    print(N)
    if lat:
        print(*a)
        print(*b)
    else:
        for _a, _b in zip(a, b):
            print(_a, _b)
