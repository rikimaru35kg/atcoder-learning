import sys
def in_int():
    return int(input())
def in_ints():
    return list(map(int, input().split()))
def in_mat(h):
    return [list(map(int, input().split())) for _ in range(h)]
def in_vec():
    return list(map(int, input().split()))
def make_list2(n, m, init=0):
    return [[init]*m for _ in range(n)]
def make_list3(n, m, l, init=0):
    return [[[init]*l for _ in range(m)] for _ in range(n)]


from itertools import product as pd
def main():
    di = []
    dj = []
    for i, j in pd(range(-1, 2), range(-1, 2)):
        if (i == j == 0): continue
        di.append(i)
        dj.append(j)
    print(di)
    print(dj)



if __name__ == '__main__':
    main()