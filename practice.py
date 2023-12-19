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


def main():
    A,B,C = inints()
    if (A == B): print('=');return
    # if (0<=A<B): print('<');return
    # if (0<=B<A): print('>');return
    if (C%2==0):
        if (abs(A) == abs(B)): print('=');return
        if (abs(A) < abs(B)): print('<');return
        print('>'); return
    else:
        if(A<B): print('<')
        else:print('>')


if __name__ == '__main__':
    main()