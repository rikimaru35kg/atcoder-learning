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

from collections import deque

import math

def main():
    gr1 = [1,3,5,7,8,10,12]
    gr2 = [4,6,9,11]
    gr3 = [2]
    x,y = inints()
    if(x in gr1 and y in gr1): print("Yes")
    elif(x in gr2 and y in gr2): print("Yes")
    elif(x in gr3 and y in gr3): print("Yes")
    else: print("No")
    


if __name__ == '__main__':
    main()