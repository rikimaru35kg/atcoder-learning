import sys
def in_int():
    return int(input())
def in_ints():
    return list(map(int, input().split()))
def in_mat(h):
    return [list(map(int, input().split())) for _ in range(h)]
def in_vec():
    return list(map(int, input().split()))

N = in_int()
cnt = [0]*3
tot = 0
digit = 0
while (N > 0):
    d = N % 10
    cnt[d%3] += 1
    tot += d; tot %= 3
    digit += 1
    N //= 10

print(digit, tot)
print(cnt)
if (tot == 0):
    print(0)
    sys.exit()
else:
    if (cnt[tot] >= 1 and digit > 1):
        print(1)
    elif (cnt[3-tot] >= 2 and digit > 2):
        print(2)
    else:
        print(-1)
