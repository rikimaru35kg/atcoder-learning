class UnionFind:
    p = []; sz = []
    def __init__(self, N):
        self.p = [-1]*N; self.sz = [1]*N
    def find(self, x):
        if(self.p[x]==-1): return x
        tmp = self.find(self.p[x])
        self.p[x] = tmp
        return self.p[x]
    def merge(self, x, y):
        if(self.same(x,y)): return False
        x = self.find(x); y = self.find(y)
        if(self.sz[x]>self.sz[y]): x,y = y,x
        self.p[x] = y
        self.sz[y] += self.sz[x]
        return True
    def same(self, x, y):
        if(self.find(x)==self.find(y)): return True
        else: return False
    def size(self, x):
        return self.sz[self.find(x)]


import random as rnd
# rnd.seed(123)

MIN_VAL = 1
MAX_VAL = 10

def gen_rnd():
    return rnd.randint(MIN_VAL, MAX_VAL+1)

def N_An(N):
    A = [gen_rnd() for _ in range(N)]
    print(N)
    print(*A)

def N_An_Bn(N, vertical=False):
    A = [gen_rnd() for _ in range(N)]
    B = [gen_rnd() for _ in range(N)]
    combined = [A, B]

    print(N)
    if(vertical): combined = zip(*combined)
    for t in combined:
        print(*t)

def H_W_Matrix(H, W):
    mat = [ [gen_rnd() for _ in range(W)]
            for _ in range(H) ]
    print(H, W)
    for t in mat:
        print(*t)
def N_M_graph(N, M, directed=False):
    frm = []
    st = set()
    while(len(frm)<M):
        a = gen_rnd()
        b = gen_rnd()
        if(a>N or b>N): continue  # invalid
        if(a==b): continue  # no self-loop
        if(not directed and a>b): a,b = b,a  # undirected -> a<b
        if((a,b) in st): continue
        frm.append([a,b])
        st.add((a,b))
    print(N, M)
    for t in frm:
        print(*t)
def tree_graph(N):
    uf = UnionFind(N+1)
    frm = []
    while(uf.size(1)<N):
        a = gen_rnd()
        b = gen_rnd()
        if(a>N or b>N): continue  # invalid
        if(a==b): continue  # no self-loop
        if(uf.same(a,b)): continue
        uf.merge(a,b)
        frm.append([a,b])
    print(N)
    for t in frm:
        print(*t)

if __name__ == '__main__':
    N_An(100000)
    # print("-------------------")
    # N_An_Bn(5, True)
    # print("-------------------")
    # H_W_Matrix(4, 3)
    # print("-------------------")
    # N_M_graph(10, 9, True)
    # print("-------------------")
    # tree_graph(10)

