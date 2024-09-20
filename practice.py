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

digit = [\
"###..#..###.###.#.#.###.###.###.###.###.",
"#.#.##....#...#.#.#.#...#.....#.#.#.#.#.",
"#.#..#..###.###.###.###.###...#.###.###.",
"#.#..#..#.....#...#...#.#.#...#.#.#...#.",
"###.###.###.###...#.###.###...#.###.###."
]

def main():
    N = inint()
    S = instrvec(5)

    for x in range(10):
        de(digit[0:5][x*4:x*4+3])

    ans = str()
    for i in range(N):
        for x in range(10):
            if(S[:][i*4:i*4+3]==digit[:][x*4:x*4+3]):
                ans += str(x)
                break
    print(ans)



if __name__ == '__main__':
    main()