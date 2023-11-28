import sys
input = sys.stdin.readline
def in_int():
    return int(input().rstrip())
def in_mat(h):
    return [list(map(int, input().rstrip().split())) for _ in range(h)]
def in_vec():
    return list(map(int, input().rstrip().split()))

N = in_int()

ans = 0
for a in range(1, N+1):
    for b in range(1, N+1):
        if (a*b >= N): break
        c = N - (a*b)
        ans += 1

print(ans)