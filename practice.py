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
def eprint(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)  # 提出時はコメントアウト
    pass

def main():
    N, X = in_ints()
    VP = in_mat(N)
    sum = 0
    for i in range(N):
        sum += VP[i][0]*VP[i][1]
        if (sum > X*100):
            print(i+1)
            return
    print(-1)


    
if __name__ == '__main__':
    main()