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

from datetime import timedelta,datetime

def main():
    S = instr()
    dt = datetime.strptime(S, "%Y/%m/%d")

    while True:
        y = f"{dt.year:04d}"
        m = f"{dt.month:02d}"
        d = f"{dt.day:02d}"
        st = set()
        for c in y: st.add(c)
        for c in m: st.add(c)
        for c in d: st.add(c)
        if len(st)<=2:
            print(f"{y}/{m}/{d}")
            return 0
        dt += timedelta(days=1)





if __name__ == '__main__':
    main()