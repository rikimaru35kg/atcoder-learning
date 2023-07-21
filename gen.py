import gen_funcs as funcs


def main():
    # funcs.f_NAB(5, (1,1e2), (1,25), lat=False)
    # funcs.f_grid(6)
    import random
    N = 3
    M = 4
    A = [random.randint(1, 11) for _ in range(N)]
    B = [random.randint(1, 11) for _ in range(N)]
    C = [random.randint(1, 11) for _ in range(M)]
    D = [random.randint(1, 11) for _ in range(M)]
    print (N, M)
    print(*A)
    print(*B)
    print(*C)
    print(*D)


if __name__ == '__main__':
    main()
