import sys
sys.setrecursionlimit(10**9)
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

def main():
    from itertools import product
    dis = [0,0,1,-1]
    djs = [1,-1,0,0]
    N,M=inints()
    S = instrvec(N)
    ans = [[0]*M for _ in range(N)]
    for i in range(N):
        for j in range(M):
            cnt = 0
            for di,dj in product(range(-1,2),range(-1,2)):
                ni = i+di; nj = j+dj
                if(ni<0 or nj<0 or ni>=N or nj>=M): continue
                if(S[ni][nj]=='#'): cnt += 1
            ans[i][j] = cnt

    for i in range(N):
        x = ""
        for j in range(M):
            x += str(ans[i][j])
        print(x)


if __name__ == '__main__':
    main()