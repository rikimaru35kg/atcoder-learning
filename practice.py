import sys
def inint():
    return int(input())
def inints():
    return list(map(int, input().split()))
def inmat(h):
    return [list(map(int, input().split())) for _ in range(h)]
def invec():
    return list(map(int, input().split()))
def makelist2(n, m, init=0):
    return [[init]*m for _ in range(n)]
def makelist3(n, m, l, init=0):
    return [[[init]*l for _ in range(m)] for _ in range(n)]
def eprint(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)  # 提出時はコメントアウト
    pass

def main():
    N = int(input())
    ans = 0
    for A in range(1, 2*N+1):
        if (A*A > 2*N): break
        if ((2*N) % A == 0):
            B = 2*N // A
            if ((A+B)%2 == 1): ans += 2
    print(ans)

    
if __name__ == '__main__':
    main()