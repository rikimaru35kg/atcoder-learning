import sys
sys.setrecursionlimit(10**8)
def inint():
    return int(input())
def inints():
    return list(map(int, input().split()))
def inmat(h):
    return [list(map(int, input().split())) for _ in range(h)]
def instrvec(h):
    return [input() for _ in range(h)]
def invec():
    return list(map(int, input().split()))
def invecvertical(n):
    v = [list(map(int, input().split())) for _ in range(n)]
    v = list(map(list, zip(*v)))
    return v
def makelist2(n, m, init=0):
    return [[init]*m for _ in range(n)]
def makelist3(n, m, l, init=0):
    return [[[init]*l for _ in range(m)] for _ in range(n)]
def de(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)  # 提出時はコメントアウト
    pass
INF = int(3e18)

def f(k, N):
    if (k==0): return 0
    return f(k-1, N) + N/k

def main():
    N = inint()
    print(f(N-1, N))

    
if __name__ == '__main__':
    main()