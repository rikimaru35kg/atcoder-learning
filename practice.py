import sys
sys.setrecursionlimit(10**8)
def instr():
    return input().rstrip()
def instrs():
    return input().rstrip().split()
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
    print(*args, **kwargs, file=sys.stderr)  #!! Comment out when submitted
    pass
INF = int(3e18)

cnt = 0
def dfs(v, frm, visited):
    global cnt
    cnt += 1
    visited[v] = True
    for nv in frm[v]:
        if visited[nv]: continue
        dfs(nv, frm, visited)

def main():
    global cnt
    N, M = inints()
    frm = [[] for _ in range(N)]
    for _ in range(M):
        a, b = inints(); a-=1; b-=1
        frm[a].append(b)
    ans = 0
    for i in range(N):
        cnt = 0
        visited = [False]*N
        dfs(i, frm, visited)
        ans += cnt
    print(ans)



if __name__ == '__main__':
    main()