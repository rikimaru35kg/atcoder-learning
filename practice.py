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
    import sys
    print(*args, **kwargs, file=sys.stderr)  # 提出時はコメントアウト
    pass
INF = int(3e18)

def main():
    N = inint()
    st = set()
    for a in range(2, N+1):
        if (a*a>N): break
        for b in range(2, N+1):
            x = pow(a, b)
            if (x > N): break
            st.add(x)
    ans = N - len(st)
    print(ans)

    
if __name__ == '__main__':
    main()