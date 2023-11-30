import sys
def in_int():
    return int(input())
def in_ints():
    return list(map(int, input().split()))
def in_mat(h):
    return [list(map(int, input().split())) for _ in range(h)]
def in_vec():
    return list(map(int, input().split()))

N, W = in_ints()
S = [0]*N
T = [0]*N
P = [0]*N
for i in range(N):
    S[i], T[i], P[i] = in_ints()

imos = [0]*(int(2e5)+1)
for i in range(N):
    imos[S[i]] += P[i]
    imos[T[i]] -= P[i]
for i in range(len(imos)-1):
    imos[i+1] += imos[i]

ok = True
for x in imos:
    ok &= (x <= W)
if (ok): print("Yes")
else: print("No")
