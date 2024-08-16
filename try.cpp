#include <bits/stdc++.h>
using namespace std;

const int MAX = 150000;
char D[MAX], F[MAX], ans[MAX];
vector<int> TP[MAX];

int main(){
    int N, M, Q;
    string S;
    cin >> N >> S >> M;
    for(int i=0; i<M; i++) cin >> D[i] >> F[i];
    cin >> Q;
    for(int i=0; i<Q; i++){
        int t, p;
        cin >> t >> p;
        TP[i] = {t-1, p-1, i};
    }
    sort(TP, TP+Q);

    bool leftB = (S[0] == 'B'), rightB = (S.back() == 'B');
    deque<int> deq;
    for(int i=0; i<N-1; i++) if(S[i] != S[i+1]) deq.push_back(i);

    int q = 0, addL = 0, addR = 0;
    for(int i=0; i<M; i++){
        if(D[i] == 'L'){
            addL++;
            if(leftB == (F[i] == 'W')){
                leftB = !leftB;
                if(deq.size()){
                    deq.pop_front();
                }else{
                    deq.push_front(-addL);
                }
            }
        }else{
            addR++;
            if(rightB == (F[i] == 'W')){
                rightB = !rightB;
                if(deq.size()){
                    deq.pop_back();
                }else{
                    deq.push_back(N-2 + addR);
                }
            }
        }
        while(q<Q && TP[q][0] == i){
            int pos = TP[q][1] - addL;
            int change = lower_bound(deq.begin(), deq.end(), pos) - deq.begin();
            if(leftB == (change%2 == 0)){
                ans[TP[q][2]] = 'B';
            }else{
                ans[TP[q][2]] = 'W';
            }
            q++;
        }
    }
    for(int i=0; i<Q; i++) cout << ans[i] << endl;
    return 0;
}