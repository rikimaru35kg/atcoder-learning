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
rnd.seed(123)


def gen_rnd(mn, mx):
    return rnd.randint(mn, mx)


def N_An(N):
    MIN = 1; MAX = 20
    A = [gen_rnd(MIN,MAX) for _ in range(N)]
    print(N)
    print(*A)


def NM_An(N):
    MIN = 1; MAX = 50
    A = [gen_rnd(MIN,MAX) for _ in range(N)]
    M = gen_rnd(2, N)
    print(N, M)
    print(*A)


def N_An_Bn(N, vertical=False):
    MIN = 1; MAX = 10
    A = [gen_rnd(MIN,MAX) for _ in range(N)]
    B = [gen_rnd(MIN,MAX) for _ in range(N)]
    combined = [A, B]

    print(N)
    if(vertical): combined = zip(*combined)
    for t in combined:
        print(*t)


def H_W_Matrix(H, W):
    MIN = 1; MAX = 4 
    mat = [ [gen_rnd(MIN,MAX) for _ in range(W)]
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
    edge = []
    st = set()
    for a,b in edge_cand:
        if((a,b) in st): continue
        st.add((a,b))
        if(directed and gen_rnd(0,1)%2): a,b=b,a
        edge.append([a+1,b+1])
        if(len(edge)==M): break
    print(N, M)
    for t in edge:
        print(*t)


def N_M_graph(N, M, directed=False, weighted=False):
    WMIN=1; WMAX=5
    edge_cand = []
    for b in range(N):
        for a in range(b):
            edge_cand.append([a,b])
    rnd.shuffle(edge_cand)
    edge = []
    st = set()
    for a,b in edge_cand:
        if((a,b) in st): continue
        st.add((a,b))
        if(directed and rnd.randint(0,1)%2==1): a,b=b,a
        e = [a+1,b+1]
        if weighted: e.append(gen_rnd(WMIN,WMAX))
        edge.append(e)
        if(len(edge)==M): break
    print(N, M)
    for t in edge:
        print(*t)


def tree_graph(N):
    edge_cand = []
    for b in range(N):
        for a in range(b):
            edge_cand.append([a,b])
    rnd.shuffle(edge_cand)
    edge = []
    uf = UnionFind(N)
    for a,b in edge_cand:
        if(uf.same(a,b)): continue
        uf.merge(a,b)
        edge.append([a+1,b+1])
    print(N)
    for t in edge:
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
    # PLEASE SPECIFY MIN MAX VALUE IN EACH FUNCTION!!
    # print("---N An------------")
    N_An(200000)
    # print("---N-M An----------")
    # NM_An(10)
    # print("---N An Bn---------")
    # N_An_Bn(5, vertical=False)
    # print("---H W A[i,j]------")
    # H_W_Matrix(4, 3)
    # print("---N M graph-------")
    # N_M_graph(5, 7, directed=False, weighted=False)
    # print("---N tree graph----")
    # tree_graph(10)
    # print("---N*N field-------")
    # field(20)

