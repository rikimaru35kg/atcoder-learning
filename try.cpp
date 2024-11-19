#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<P, P> Q;
#define INF (1LL << 61)
map<Q, Int> table;
Int n, k, x[1050], y[1050], nm[1050];
char c;

Int num(char c){
	if(c == 'J')return 0;
	if(c == 'O')return 1;
	if(c == 'I')return 2;
}

Int solve(Int tx, Int ty, Int level, Int type = 3){
	Int range = 1 << level;
	Q tmp = Q(P(tx, ty), P(level, type));
	if(table.count(tmp))return table[tmp];
	Int &res = table[tmp];
	Int cnt[] = {0, 0, 0};
	for(Int i = 0;i < n;i++){
		if(tx <= x[i] && x[i] < tx + range && ty <= y[i] && y[i] < ty + range){
			cnt[nm[i]]++;
		}
	}
    if(cnt[0] + cnt[1] + cnt[2] == 0)return res = 0;
	if(type != 3){
		return res = cnt[0] + cnt[1] + cnt[2] - cnt[type];	
	}
	if(level == 0)return 0;
	Int xmid = tx + range / 2, ymid = ty + range / 2;
	res = INF;  
	Int nums[] = {0, 1, 2, 3};
	do{
		Int pp = 0;
		pp += solve(tx, ty, level - 1, nums[0]);
		pp += solve(xmid, ty, level - 1, nums[1]);
		pp += solve(tx, ymid, level - 1, nums[2]);
		pp += solve(xmid, ymid, level - 1, nums[3]);
		res = min(res, pp);
	}while(next_permutation(nums, nums + 4));
	return res;
}

int main(){
	cin >> k >> n;
	for(Int i = 0;i < n;i++){
		cin >> x[i] >> y[i] >> c;
		x[i]--,y[i]--;
		nm[i] = num(c);
	}
	cout << solve(0, 0, k) << endl;
	return 0;
}
