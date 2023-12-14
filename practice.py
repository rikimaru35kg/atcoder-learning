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
    print(*args, **kwargs, file=sys.stderr)  # 提出時はコメントアウト
    pass
INF = int(3e18)

def main():
    N = inint()
    A = invec()
    stck = [0]*200
    ans = 0
    for a in A:
        ans += stck[a%200]
        stck[a%200] += 1
    # ans = 0
    # for x in stck:
    #     if (x <= 1): continue
    #     ans += x*(x-1)//2
    print(ans)



if __name__ == '__main__':
    main()