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

from collections import deque

def main():
    N = inint()
    A = []
    dct = {}
    for i in range(N):
        a = inint()
        A.append(a)
        if(a in dct.keys()): dct[a] += 1
        else: dct[a] = 1
    import itertools as itt
    ans = 0
    for i,j in itt.product(range(N),range(N)):
        b = A[i] * A[j]
        if(b not in dct.keys()): continue
        ans += dct[b]
    print(ans)



if __name__ == '__main__':
    main()