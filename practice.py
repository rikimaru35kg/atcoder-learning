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
    N = in_int()
    A = in_vec()
    A.sort()
    S = [0]*(len(A)+1)
    M = len(A)
    for i in range(M): S[i+1] = S[i] + A[i]
    sum = 0
    for i, x in enumerate(A):
        sum += S[M] - S[i+1] - x*(M-1-i)
        sum += x*(i) - S[i]
    sum >>= 1
    print(sum)
    
if __name__ == '__main__':
    main()