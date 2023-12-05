import sys
def in_int():
    return int(input())
def in_ints():
    return list(map(int, input().split()))
def in_mat(h):
    return [list(map(int, input().split())) for _ in range(h)]
def in_vec():
    return list(map(int, input().split()))
def make_list2(n, m, init=0):
    return [[init]*m for _ in range(n)]
def make_list3(n, m, l, init=0):
    return [[[init]*l for _ in range(m)] for _ in range(n)]
def eprint(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)  # 提出時はコメントアウト
    pass

def main():
    N = int(input())
    AB = []
    aoki = 0
    for _ in range(N):
        a, b = in_ints()
        AB.append([a, b])
        aoki += a
    AB.sort(key=lambda x:2*x[0]+x[1])
    taka = 0
    ans = 0
    while (taka <= aoki):
        ans += 1
        ballot = AB[-1]
        AB.pop()
        aoki -= ballot[0]
        taka += ballot[0] + ballot[1]
    print(ans)

    


    
if __name__ == '__main__':
    main()