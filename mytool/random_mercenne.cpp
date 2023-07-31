#include <bits/stdc++.h>
using namespace std;

long long get_rand_range( long long min_val, long long max_val ) {
    // 乱数生成器（メルセンヌツイスタ）
    static std::mt19937_64 mt64(0);

    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    std::uniform_int_distribution<long long> get_rand_uni_int( min_val, max_val );

    // 乱数を生成
    return get_rand_uni_int(mt64);
}

int main () {
    cout << get_rand_range(0, (1LL<<60)) << endl;
    cout << get_rand_range(0, (1ULL<<63)-1) << endl;
    cout << get_rand_range(0, (1ULL<<63)-1) << endl;
    cout << get_rand_range(0, (1ULL<<63)-1) << endl;
}
