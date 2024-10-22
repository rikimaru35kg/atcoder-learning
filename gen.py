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
    edge_cand = []
    for b in range(N):
        for a in range(b):
            edge_cand.append([a,b])
    rnd.shuffle(edge_cand)
    frm = []
    st = set()
    for a,b in edge_cand:
        if((a,b) in st): continue
        st.add((a,b))
        if(directed and rnd.randint(0,1)%2==1): a,b=b,a
        frm.append([a+1,b+1])
        if(len(frm)==M): break
    print(N, M)
    for t in frm:
        print(*t)
def tree_graph(N):
    edge_cand = []
    for b in range(N):
        for a in range(b):
            edge_cand.append([a,b])
    rnd.shuffle(edge_cand)
    frm = []
    uf = UnionFind(N)
    for a,b in edge_cand:
        if(uf.same(a,b)): continue
        uf.merge(a,b)
        frm.append([a+1,b+1])
    print(N)
    for t in frm:
        print(*t)
def field(N):
    print(N)
    lst = ['.']*100 + ['X'] + ['G']
    f = [[rnd.choice(lst) for i in range(N)] for j in range(N)]
    a = rnd.randint(0,N-1); b = rnd.randint(0,N-1)
    f[a][b] = 'S'
    for i in range(N):
        tmp = ""
        for j in range(N):
            tmp += f[i][j]
        print(tmp)


if __name__ == '__main__':
    # N_An(100000)
    # print("-------------------")
    # N_An_Bn(5, True)
    # print("-------------------")
    # H_W_Matrix(4, 3)
    # print("-------------------")
    N_M_graph(10, 9, True)
    # print("-------------------")
    # tree_graph(10)
    # print("-------------------")
    # field(20)

