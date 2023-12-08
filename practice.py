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
def makelist2(n, m, init=0):
    return [[init]*m for _ in range(n)]
def makelist3(n, m, l, init=0):
    return [[[init]*l for _ in range(m)] for _ in range(n)]
def de(*args, **kwargs):
    import sys
    print(*args, **kwargs, file=sys.stderr)  # 提出時はコメントアウト
    pass

import heapq
from heapq import heappush as push
from heapq import heappop as pop

def main():
    N,M,X,Y = inints()
    X -= 1; Y -= 1
    frm = [[] for _ in range(N)]
    for _ in range(M):
        a, b, t, k = inints()
        a -= 1; b -= 1
        frm[a].append([b, t, k])
        frm[b].append([a, t, k])
    dist = [int(3e18)]*N
    dist[X] = 0
    # pque = heapq.heapify([])
    pque = []
    push(pque, [0, X])
    while (len(pque) > 0):
        d, v = pop(pque)
        if (dist[v] != d): continue
        for nv, t, k in frm[v]:
            tdep = (d + k - 1) // k * k
            nd = tdep + t
            if (nd < dist[nv]):
                push(pque, [nd, nv])
                dist[nv] = nd
    ans = dist[Y]
    if (ans == int(3e18)): ans = -1
    print(ans)
    
if __name__ == '__main__':
    main()