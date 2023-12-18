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

def mymap(c):
    if (c == '6'): return '9'
    if (c == '9'): return '6'
    return c

def main():
    N, K = inints()
    friends = []
    for _ in range(N):
        friends.append(inints())
    friends.sort()
    now = 0
    for a, b in friends:
        if (a - now > K):
            print(now + K)
            return
        K += b
        K -= (a - now)
        now = a
    print(now + K)

if __name__ == '__main__':
    main()