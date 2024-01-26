# はじめに
このページでは、競プロでこれまでに学んだ内容（教訓）を端的に箇条書きします。

# 数や文字の扱い

## 文字列操作
- S.substr(開始位置, 長さ)で部分文字列を取得可能
- regex_match(S, regex("正規表現"))で一致性を確認可能
- ただし正規表現は遅い。計算量がシビアな問題ではなるべく使わない
- S.find(s)は文字列sの含まれる最初の位置を出力。存在しない場合はnposを出力（sは文字でも可）
- S.rfind(s)は文字列sが最後に含まれる位置を出力。存在しない場合はnposを出力
- charをintに直すには'5'-'0'などとする
- 文字列が連続している場合はランレングス圧縮が有効。余事象との組み合わせで、異なる文字が含まれる区間の場合の数も求められる
- tolower(c)、toupper(c)で小文字、大文字変換が可能
- scanf/sprintfに入力する為にはstringではなくchar[文字数+1]を定義する必要がある。+1はnull終端文字らしい。+1を忘れるとbuffer overflowとなるので要注意
- 文字コードを扱うときは一旦開始文字（eg A, a）からの差分値とし、最後に開始文字からの差分値で求める。('C' + 20) % 26などとすると空白文字となってしまうので要注意！
### 例題
- [B - ROT N](https://atcoder.jp/contests/abc146/tasks/abc146_b)

## ランレングス圧縮（Run Length Encoding）
- 連続する文字が何個あるかという情報に書き換える事をランレングス圧縮という
### 例題
- 交互列を塊と見て圧縮する場合もある 良問 [1 - 電飾 (Illumination)](https://atcoder.jp/contests/joi2013ho/tasks/joi2013ho1)

## ビット操作
- &や|等のビット演算子は==よりも優先順位が低いことに注意。ビットシフトも含め、ビット操作はとにかく括弧で囲め！
- ビット操作にはビット列bitsetが便利
- 部分集合の判定にbitsetを使用可能。A⊂BならA & B == A
- 部分集合の全列挙には、i = Nとしておいて、i = (i-1)&Nで更新していけば全列挙できる（iを2進数とみなした場合）
- 集合の一致判定にはハッシュとXORを用いたzobrist hashingが有効（衝突の可能性もある…）
- 決められた位置のみ一括で反転したい場合は、排他的論理和を使うと楽
- andはマスク処理とみなす事ができる
- x + y = (x xor y) + 2 * (x & y)が成り立つ（両方1の桁だけ繰り上がりがあり、他の桁は一致するため）
- ~0とすると1111111...111（intなら32桁）となる
- ビット演算は桁ごとに独立

## XOR
- XORは繰り上がりなし足し算。その為、交換法則、結合法則が成り立つ（ANDが混ざっていたら不可）
- XORは反転処理ともみなす事ができる
- XORはビット毎に独立して考えると見通しが良くなることがある
- XORの累積和はmod4で考えると良い（0:n, 1:1, 2:n^1, 3:0）。例えば、0から4*n-1までのXORは必ず0となる
- 木の任意の二頂点間のXORは、根からのXORをそれぞれ求めておき、それのXORを取れば求まる（共通部分のXORは消える為）
### 例題
- 基本 [E - Red Scarf](https://atcoder.jp/contests/abc171/tasks/abc171_e)
- !要復習 構築系問題 [F - XOR Matching](https://atcoder.jp/contests/abc126/tasks/abc126_f)
- !要復習 木XOR [E - Xor Distances](https://atcoder.jp/contests/abc201/tasks/abc201_e)

## K進数
- 2進数を用いると、N桁で2^Nの情報量を表せる
### 例題
- !要復習 2進数情報量を利用 [E - Bad Juice](https://atcoder.jp/contests/abc337/tasks/abc337_e)

## 整数
- 約数と素因数分解は似て非なるもの。約数を列挙したいのか、素因数を列挙したいのか、よく考える
- a, b, cが自然数の時、a*b<=c とa<=floor(c/b)は同値（必要十分条件）
- a, b, cが自然数の時、a*b>c とa>floor(c/b)は同値（必要十分条件）
- c++では負の数の割り算の挙動に注意。a/bはabs(a)/abs(b)に符号を付けたもので、a%bはa=(a/b)*b + a%bが成り立つ値となる（余りが負になる事がある）
- 負の数を割ったときの余りを0以上b未満にしたい場合、余りが負の場合は+bすれば良い
- べき乗はpow(x, n)というSTLがあるが、戻り値がdouble型なので要注意！素直に自作pow関数を使うべき（2のn乗なら1LL<<nで十分）

## 余り
- c++は余りがマイナスとなる事があるので注意（余りがマイナスなら割る数を足してやると良い）
- 分数形式A/Bで表現された整数をMで割った余りは(A % B*M) / Bで求まる
- A/B = q*M + rであり、A = q*B*M + r*Bなので、M>rである事に注意するとAをB*Mで割った余りはr*Bとなり、Bで割ればrが求まる

## 1000000007関連問題
- 掛け算や足し算してMODを上回る可能性がある場合はその都度MODで剰余を取る（最後出力するときにも油断してMOD取るのを忘れないように！！）
- ただし、累積和にMODを取ると途中で減ってしまうので注意！区間和を求める際、MODを取るとマイナスになる事があったり、単純に絶対値を付けられなかったりする
- 繰り返し2乗法により、累乗のmodを高速に計算可能（modpowとしてツール化）
- MODの割り算は逆元を求めれば良く、modpow(x, MOD-2, MOD)で求まる。MODが素数で使えるフェルマーの小定理を利用したもの
- ちなみにMODが素数でない場合の逆元は拡張ユークリッドの互除法により求まる
- なお、ACLを用いれば素数かどうか気にする事無く逆元が求まる（普通に割る記号でもいけるし、inv()を使っても良い）
- xとMODが互いに素でないと逆元は存在しないので注意！（最大公約数でお互いに割ってから考察する事が多い）

## ユークリッドの互除法
- gcd(a, b) = gcd(b, r) = ... = gcd(b', 0) = b'という古典的アルゴリズム
- 再帰関数で簡潔に書ける
- 拡張ユークリッドの互除法も再帰関数で簡潔に書ける（ax+by=gcd(a,b)のx, y, gcd(a,b)を求める問題）
- 拡張ユークリッドの互除法は、ax≡b(mod M)を解くのと本質的に同じ。g=gcd(a,M)、ax+My=gを解き、bがgの倍数であれば両辺k(=b/g)倍してa(kx)+M(ky)=bとなるので、kxが答えとなる。なお、bがgの倍数でないときは解なしとなる
### 例題
- !復習価値高 snuke氏の拡張ユークリッド解説動画が神 [E - Throne](https://atcoder.jp/contests/abc186/tasks/abc186_e)

## 最大公約数と最小公倍数
- 最大公約数は、各素因数の最小指数を選んだもの、最小公倍数は最大指数を選んだものとなる
- 最小公倍数はオーバーフローに注意（1e9以下同士であれば大丈夫だが、それ以上の場合はgcdを求めてオーバーフロー判定する必要あり）
- (a, b, c)のGCDとLCMはそれぞれ、gcd(gcd(a, b), c)、lcm(lcm(a, b), c)と書ける。理由は素因数分解から明らか
- 素因数の指数部が同じであるかどうかの判定は、LCM/GCDを素因数で割り切れるかどうか調べればよい（例えばLCM/GCDが3で割り切れなければ、3の指数部は同じ数。理由は素因数分解から明らか）
- 0, a, 2a, ..., (N-1)aはaとNが互いに素のときMOD Nで全て異なる
- より一般には、0,a,2a,...はg=gcd(a,N)とすると0,g,2g,3g,...(MOD N)を埋めつくす（順番はいろいろ）
### 例題
- !復習価値高 半公倍数 [D - Semi Common Multiple](https://atcoder.jp/contests/abc150/tasks/abc150_d)

## 約数全列挙
- 約数を全列挙するのは、2から順番に割り切れるか確かめ、割り切れたらその数と割られた数を保存していく
- 元の数をMとすると、計算量はO(sqrt(M))
- 複数の数の約数を同時に全列挙するには、bool配列を用意しておき、最初に調べたい数のところを全てtrueにする
- 次に、この配列の2の倍数の位置を全て調べ、trueがあったら2は約数という事で2のところをtrueにする
- 続けて3, 4と調べていく。計算量は約数最大値をMとすると、O(M logM)になる（M/2 + M/3 + M/4 + ... + M/M回調べる為）

## 約数の個数全列挙
- N以下の約数の個数を全列挙するには、a=1~N、b=1~N/aとすればO(NlogN)で全列挙可能
- なお、約数の個数は非常に小さいので、約数全列挙できるならば、全約数のループを回す事は容易
- 約数の個数がそれ以下のどの自然数よりも多いものを高度合成数というが、10^9以下で1344個、10^18で約10^5個の約数を持つ
- オーダーではO(N^(1/(loglogN)))らしく、O(sqrt(N))よりは小さいがO(logN)よりは大きい
### 例題
- !復習価値中 [C - Four Variables](https://atcoder.jp/contests/abc292/tasks/abc292_c)
- !復習価値高 約数の個数が少ないが故に解ける問題 [F - Division or Subtraction](https://atcoder.jp/contests/abc161/tasks/abc161_f)

## 積分解（約数類似系）
- M<=abとなるなるべく小さいabに分解するには、aが固定された場合はb=roundup(M/a)となる
- a<=bを仮定すると、a <= roundup(M/a) < M/a + 1よりa^2-a < Mの範囲でaを試せばよい（O(sqrt(M))）
### 例題
- !要復習 [D - M<=ab](https://atcoder.jp/contests/abc296/tasks/abc296_d)

## 素数判定
- sqrt(N)まで試して割れなければ素数である
- 素数関連では最も簡単（素因数分解や素数全列挙と比較して）

## 素因数分解
- 2からsqrt(N)まで試して、割り切れる回数が指数となる
- sqrt(N)まで試して、割り切った数が1でない場合は、その数も素数であるので忘れないように
- ライブラリprime_factorizationとして保存した
- 当たり前だが、その数自身も素数になる可能性があるので、N!の中に素数は最大N個程度ある（sqrt(N)ではないので要注意）
- エラトステネスの篩に真偽ではなく最初に消されたときの数値を記録しておけば、素因数分解を繰り返すときに高速素因数分解できる。ただし篩を作るのにO(NloglogN)かかるので、素因数分解が数個しかない場合は遅くなるので注意
### 例題
- !復習価値中（ルジャンドルの定理） [D - Factorial and Multiple](https://atcoder.jp/contests/abc280/tasks/abc280_d)
- !復習価値低 素因数分解というよりnが大きいときのnCrの求め方が肝 [D - Factorization](https://atcoder.jp/contests/abc110/tasks/abc110_d)
- !復習価値高 考察は易 実装工夫すると楽 [D - 756](https://atcoder.jp/contests/abc114/tasks/abc114_d)
- LCMがオーバーフローするときどうするか問題 [E - Flatten](https://atcoder.jp/contests/abc152/tasks/abc152_e)

## 素数全列挙
- エラトステネスの篩を用いると計算量はO(Nlog(logN))
- 2から順番に調べていき、素数でなければcontinue、素数ならその倍数を消していく（falseにしていく）
- 消す倍数はp^2以上の数でOK（i=p*pからスタートしてi+=pしてループを回す）
### 例題
- 篩を使わなくてもぎりぎりTLEはしないが… [D - 2017-like Number](https://atcoder.jp/contests/abc084/tasks/abc084_d)

## 互いに素でない数字組合せの個数数え上げ
- L<=(x,y)<=Rの二つの数字であり、xもyもkの倍数である組合せの数をg(k)とするとg(k)は簡単に求まるが、最大公約数がkという訳ではない
- xとyの最大公約数がkである組合せの数をf(k)とすると、f(k)はg(k)をベースに考えると良い
- g(k)はxとyが2k, 3k, 4k, ...の倍数である組合せもカウントしている
- よって、g(k)からf(2k), f(3k), f(4k), ...を引けば最大公約数がkとなる組合せが数えられる
- その為、f(k)=g(k)-Σf(i*g) (i>=2)とすると重複なく数えられる
- この時、f(k)はkの降順で求めていけば順次求まる
- 計算量は調和級数になるのでO(NlogN)
- メビウス関数を使うと引き算Σの部分を係数化できるが、発展的な話題で現在理解不可能
### 例題
- !要復習 [E - Divide Both](https://atcoder.jp/contests/abc206/tasks/abc206_e)

## 剰余埋めつくし系
- DとMが互いに素の場合、0<=i<j<Mにおいて、iDとjDは合同にならない。つまり0からM-1まではD倍したときの余りがかぶらず、全てのMパターンの余りを埋めつくす
- gcd(D, M)=gでD=gd、M=gmの場合、0<=i<j<mにおいて、iDとjDは必ずgの倍数であり、合同にならない。つまり0からm-1まではD倍したときの余りがかぶらず、gの倍数となる全ての余りmパターンを埋めつくす
### 例題
- !復習価値中 埋めつくし計算式を理解していれば解ける良問 [D - Marking](https://atcoder.jp/contests/abc290/tasks/abc290_d)
- !要復習 最大公約数埋めつくしを考えさせられる良問 解説動画の前半は問題勘違いなので注意 [E - Ring MST](https://atcoder.jp/contests/abc210/tasks/abc210_e)

## 中国剰余定理（CRT: Chinese Remainder Theorem）
- t≡a (mod C)かつt≡b (mod D)となる最小のtを求める問題
- 式変形により拡張ユークリッドの互除法で解ける
- ACLにcrt関数があり、auto [t, s] = crt({a,b}, {C,D});で求まる
- s==0の場合は解なし
### 例題
- !復習価値中 CRTを思い出すのに役立つ [E - Oversleeping](https://atcoder.jp/contests/abc193/tasks/abc193_e)

## 平方数
- 素因数分解したときの指数がすべて偶数なら平方数
- 平方数を考えるときは指数をMOD 2で考える（つまり0か1のみで、0の場合は無いのと同じなので指数が1の素因数の積になる）
- 指数をMOD 2した場合、2数の積が平方数となるのは、同じ数との積のみ
- 指数をMOD 2するには、素因数分解までは不要で、平方数で割れるだけ割ればよい
### 例題
- !復習価値中 平方数判定の本質が分ければ解ける [D - Together Square](https://atcoder.jp/contests/abc254/tasks/abc254_d)

## 小数
- 小数点を出力する際はcout << fixed << setprecision(10) << x << endl;などとしないと小数点以下の桁が6桁ぐらいまでしか出力されない（printf("%.10f\n", x)の方が簡単）
- 小数点の計算は誤差がある為、厳密な大小判定には使えない。整数型に直せれば厳密な判定が可能。
- 小数を整数に入力したい場合、scnaf("%d.%d", &x)で整数、小数を分離して入力可能

## 方程式
- 係数を保存しておくことで文字式を表すことができる。例えばax+bを保存したい場合、aとbを保存しておく
- 文字式を保存できれば、方程式を解くこともできる。ax+bが保存されていれば、ax+b=cが解ける（x=(c-b)/a）
### 例題
- !復習価値中 基本 [E - Lucky Numbers](https://atcoder.jp/contests/abc255/tasks/abc255_e)

## MEX（Minimum Excluded value）
- K個の数のMEXは必ずK以下
- 長さKの配列を持ち、順番に数が存在するか見ていけば良い
### 例題
- 基本 [C - Max MEX](https://atcoder.jp/contests/abc290/tasks/abc290_c)

# 確率と期待値

## 期待値
- 期待値にも確率と同様に漸化式が成立する（dpで解ける問題があるという事）
- 期待値DPの場合、何を状態として持つべきか良く考える事（表を書いてみると良い）
- あくまで感覚だが、ポイント的なもの（出目の総和など）を状態にもつカエル型DPが多い気がする
- 考察の結果は必ずしも配るDPにはならないので、くどいが良く考える事
### 例題
- !要復習 期待値としてもDPとしても良問 [E - Roulettes（青diff）](https://atcoder.jp/contests/abc314/tasks/abc314_e)

# ソート

## STLのソート
- lower_bound関数で、配列中のどこの間に入るかわかる（戻り値がイテレータである事に注意）
- 上手く規格が合わずソートできない場合は、無理やり規格を合わせてごちゃ混ぜソートすると解ける場合あり（e.g. 1分でB点、2分でA点取れる場合、1分でB点取り、更に1分でA-B点取れると考えるなど）
- sort()関数の第3引数に自作関数compを渡すことが可能。ただしcomp(a,a)==falseとなる事が必要。compの第1引数を左に並べたい場合にtrueを返せばよい

## 転倒数
- バブルソートするのに必要な回数であるが、より本質的にはai>ajとなるペアの組合せの数と等しい（ソートにはこれ以上の回数が必要な事は自明だし、ソートが終わっていない時このような隣り合うペアが存在するので）
- 全探索するとO(N^2)だが、BIT木を使えばO(NlogN)で可能。
### 例題
- !要復習（考え方OKだが実装できず） 基本+α [F - Sorting Color Balls](https://atcoder.jp/contests/abc261/tasks/abc261_f)
- !要復習 転倒数と結びつけるのが難しい [F - Merge Sets](https://atcoder.jp/contests/abc306/tasks/abc306_f)

## 要素積のmaxを最小化
- 集合Aと集合B（サイズは同じ）の要素積のmaxを最小化したい場合、Aの降順、Bの昇順を組み合わせると良い
- 割と自明とみなされているようだが、ここの理解に苦しんだ
- Aの降順、Bの昇順を並べて組み合わせを考える場合、もしクロスしている組み合わせがあれば、組み合わせを逆にすることでかならずmax値は減少する
- 上記をクロスがなくなるまで操作すれば最適な組み合わせとなり、すなわちそれは最初に述べた組み合わせである
### 例題
- !要復習（考え方OKだが実装ミス） [E - Gluttony](https://atcoder.jp/contests/abc144/tasks/abc144_e)

# 座標圧縮
- 簡単に実装するなら、圧縮前の座標をmap[x]=0 (for all x)で用意しておき、int i=0; for (auto [k, _]: map) {map[k] = i++;}でOK
- 以下はmapの定数倍の遅さを解決したい場合の手法（あまり使う事はないかもしれない）
- 重複要素削除はソート後にvec.erase(unique(all(vec)), vec.end())で可能。uniqueは隣接の重複しか削除しないので事前ソート必須。また、uniqueはベクター長を変えないので、eraseで末尾のゴミを削除しておくこと
- 後は求めたい数字が上記ベクターの何番目にあるか調べれば良い。lower_boundを用いる
- IMOS法用に座標圧縮する場合は、-1を入れるための箱を用意する事（例：3~5の累積を取りたいとき、座標としては3と6とすべきで、5でないことに注意）

# 全探索

## 多重ループ全探索
- ループの数を減らせないか工夫してみる
- ループの数を減らした場合、自動的に決まった変数に矛盾がある場合はcontinueせよ
- 途中までループして後は二分探索などすると、O(N^4)がO(N^2 logN^2)となってACできる場合あり
- 途中からループに意味がなくなる場合breakする事で探索量を減らせる。特にi*j<=Kでのみループを回す必要があるのであれば、計算量はO(KlogK)となり、i*j*k<=Kの3重ループならO(Klog^2K)となる
### 例題
- !復習価値低 ループ探索計算量を考察する良問（chokudai氏の解説動画あり） [D - Cake 123](https://atcoder.jp/contests/abc123/tasks/abc123_d)

## 順列全探索
- 制約数が少なければ全探索を考える
- 後述のBFSやDFSも全探索だが、こちらの方が実装が簡単なので、可能なら順列全探索
- nCrの全探索にも応用可能（bitsetのpattern.count()==rだけ実行する）。この時、trueビット以外の項目をスルーして良いかどうか要確認！（NからK個を選らんでビルが全部見える高さを考える場合、N-K個の選ばれていないビルの高さに影響されてしまう等）
- next_permutationは辞書順に検索できる。しかも重複があってもそれをスキップして探索してくれるので超便利
- next_permutationは使用前にsortが必要！辞書順最後に到達した時点でnextがなくなる為
- 10!は約360万であるので、O(11!)ぐらいまではループで回せる
- 10P5が必要だったとしても、next_permutationで10!回して、先頭の5つを取り出せば10P5の全列挙ができる（計算量が間に合うので）。nPr<=1e8かつn!>1e9のような場合には素直に再帰関数で実装するしかないと思われる
### 例題
- 基本+実装少し工夫 [D - Send More Money](https://atcoder.jp/contests/abc198/tasks/abc198_d)

## bit全探索
- 各要素を選ぶ選ばないを2進数と考えループ
### 例題
- bit全探索基本 [C - Coverage](https://atcoder.jp/contests/abc289/tasks/abc289_c)
- bit全探索基本 [C - HonestOrUnkind2](https://atcoder.jp/contests/abc147/tasks/abc147_c)

## 再帰全探索
- 次に探索する状態へ再帰でつなぐ。自分自身で終了する事も忘れずに
- 再帰しながら全探索するのではなく、先にオイラーツアーして順番を決めてから再度再帰して全探索する方が良い場合あり
- 例えば連結無向グラフ（ループあり）の終端処理をしたい場合、終端判定がそもそも難しいので、先にオイラーツアーしておけばその順序で処理をかける事ができる
### 例題
- !要復習 DFSの訓練に良い [D - RGB Coloring 2](https://atcoder.jp/contests/abc199/tasks/abc199_d)
- !復習価値低 ポリオミオ（Polyomio）の種類数が少ないから解ける [E - Red Polyomino](https://atcoder.jp/contests/abc211/tasks/abc211_e)

# 工夫した探索

## 二分探索法
- lower_boundやupper_boundは二分探索で計算量はO(logN)
- lower_boundの第4引数にgreater<ll>()を指定すると降順ソート列のx以下となるイテレータを返すようになる（upperはx未満）
- 最小値の最大化を二分探索で求められる事が多いのは、最小値（正確には下界）=Xが成立となるかどうかを貪欲法で求められる事が多いから
- 全組合せは膨大すぎて調べられない場合、目的の値（得点など）を二分探索するとO(logN)になる。N=1e18でもlogNは60程度
- 最短経路問題でsum(bi)/sum(ci)（bi,ciは各辺に割りつけられた価値とコスト）を最大化せよという問題の場合、コストが単純でないので普通に解けない。こんな時に答えXを決め打ちし、それ以上になるかどうかという問題に置き換えると、sum(bi-X*ci)>=0と変形できるので二分探索を使うことができる（なお、この問題は平均最大化という有名テクニック）
- 二分探索で最小値を求める問題の場合、f(l)=false、f(r)=trueとなる関数を用いて最終的な答えはr。この時f(x)は答えをx以下（正確にはxを上界）にできるかを返す関数であり、頭が混乱するので注意（Yokan Partyはこの逆）
### 例題
- !復習価値中 二分探索の基本 [001 - Yokan Party（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_a)
- !復習価値高 二分探索良問 [D - 射撃王](https://atcoder.jp/contests/abc023/tasks/abc023_d)
- !要復習 判定部分が難しい [E - Erasing Vertices 2](https://atcoder.jp/contests/abc267/tasks/abc267_e)
- [D - 250-like Number](https://atcoder.jp/contests/abc250/tasks/abc250_d)
- 二分探索で解ける事に辿り着けるかどうかが勝負 [E - Logs](https://atcoder.jp/contests/abc174/tasks/abc174_e)
- [F - Beautiful Path](https://atcoder.jp/contests/abc324/tasks/abc324_f)
- 答え自体の二分探索でない為難しいが良問 [E - Handshake](https://atcoder.jp/contests/abc149/tasks/abc149_e)
- 二分探索に用いる関数で頭が混乱するが二分探索の本質を考えさせられる良問 [D - Pond](https://atcoder.jp/contests/abc203/tasks/abc203_d)
- [087 - Chokudai's Demand（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_ci)

## 三分探索法
- 狭義に下に凸の区間における最小値を求めるときに使える。
- 幅が2になるまでwhileループさせる
- 最後はleftからrightまでの最小値を求めれば良い
- 最小包含円のようにxy平面で凸な関数となる場合は二重に三分探索すれば良い
- double型の三分探索はr-lの幅ではなく回数を決め打ちすると良いが、収束が意外に遅いので注意。(2/3)^100でも1e-17ぐらいなので、場合によっては100回では足りない
### 例題
- [D - Freefall](https://atcoder.jp/contests/abc279/tasks/abc279_d)
- 最小包含円 [F - Enclose All](https://atcoder.jp/contests/abc151/tasks/abc151_f)
- double型の三分探索 [B - ムーアの法則](https://atcoder.jp/contests/arc054/tasks/arc054_b)

## 尺取り法
- 単調性があるときに使用可能
- 区間の長さ1（left=right）の時にOK、NGの両方ありうる場合は半開区間で考える（[l,r)）というか基本は半開区間
- rightをNGになるまでwhile分で進める際、NGになった瞬間のrightでwhile分の中を計算しないこと！
- 尺取り法は半開区間なので、rを進めた後にA[r]を参照する事はもうないという事に注意
- もしA[r]を参照したいなら、rを進めた後にr>0なら--rする（例えば例題のImpartial Gift）
- 尺の中にある要素をmapやsetで持つのが典型（！？）
### 例題
- 基本 [076 - Cake Cut（★3）](https://atcoder.jp/contests/typical90/tasks/typical90_bx)
- 基本 [C - 列](https://atcoder.jp/contests/abc032/tasks/abc032_c)
- 本番では尺取りを使わなかったが… [C - Minimize Abs 2](https://atcoder.jp/contests/abc330/tasks/abc330_c)
- [D - Impartial Gift](https://atcoder.jp/contests/abc302/tasks/abc302_d)

## 半分全列挙
- N=40程度のとき、2^NはTLEするが2^(N/2)であればTLEしない事を利用
- 数列を半分に分け、それぞれで全探索する
- その後、問題に応じて上手く組み合わせる事ができるのであれば使えるアルゴリズムである
- N=10^12程度のとき、10^6に分けるとうまくいくような問題もある（数列の二乗など）
### 例題
- [051 - Typical Shop（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_ay)
- 全探索でN=10^12程度 [C - ダーツ](https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c)

# 区間和

## 累積和
- 区間和を高速に求める事ができる
- 元の配列に仕切りをいれて、図示するとイメージしやすい（区間和は半開区間で求めるイメージ）
- 累積和の添え字は、元の数列で何個選んだかと言い換えることもできる
- 例えばA[l]～A[r]の和はS[r+1]-S[l]だが、これはr+1個からl個を除いたものとも解釈できる（元の数列が0-indexedなので、A[l]はl+1個目である事に注意）
- 元の数列が非負なら累積和は必ず広義単調増加、非正なら必ず広義単調減少となる
- 逆向きに累積和と取れば単調減少（単調増加）となる
- 和だけでなく、累積XORや累積GCDも考えられる（要するにnow=f(now,x)みたいな形で更新できる演算であれば何でも累積できる。区間を求められるかは別問題だが・・・）
### 例題
- [D - Non-decreasing](https://atcoder.jp/contests/abc081/tasks/arc086_b)
- [D - Xor Sum 2](https://atcoder.jp/contests/abc098/tasks/arc098_b)
- [C - GCD on Blackboard](https://atcoder.jp/contests/abc125/tasks/abc125_c)

## 2次元累積和
- 累積和は2次元でも取れる
- 包除原理的な考え方で累積和を取る
- 区間和を取るときも包除原理的な考え方でやる
### 例題
- 基本 [A - 惑星探査 (Planetary Exploration)](https://atcoder.jp/contests/joi2011ho/tasks/joi2011ho1)
- [D - Checker](https://atcoder.jp/contests/abc086/tasks/arc089_b) なお、この問題は何も考えずにlong longを使いすぎるとMLEする
- [D - AtCoder Express 2](https://atcoder.jp/contests/abc106/tasks/abc106_d)

## BIT木（Fenwick tree）
- 元の配列が動的に変わるときの要素iまでの累積和を高速（logN）で求める事ができる
- 個数を保存しておけば、ある値以下の個数を求める事にも使える
- 累積和のlower_boundも実装する事ができるので、ある値以下に何個存在するかも求める事ができる
### 例題
- [E - Least Elements](https://atcoder.jp/contests/abc281/tasks/abc281_e)

## 連続部分列問題
- キーワード：連続部分列は累積和！（もしくは尺取り法）
- 和がKとなる連続部分列が存在するかどうかは、累積和をsetに入れておけば判定可能。S[i]+KとなるS[j]が存在するのであれば、[i,j)の和はKという事
- 連続部分列の和がある値Kとなる個数を求めるには、Sr-Sl=Kとなれば良いので、Slをmap[Sl]=（Slとなる個数）としておけば高速に求められる
- 数列の連続部分列[L,R]の中で値がKに一致する個数を求める場合、事前にK毎にvectorを用意しておき、そのvectorにKとなる要素番号を格納しておく。後は[L,R]となる個数をupper_boundで調べれば良い
- Kと一致ではなくK以上の個数などとなる場合はmapで累積和を保存しても個数が求められないので尺取り法か二分探索
- 累積和のMODが部分列の長さと一致するという問題でも応用可能。具体的には最初に1ずつ引いた数列にしておけば、累積和を取った時に長さ分の考慮が不要となる
- 0-9で構成された連続部分文字列がMOD Pで0になる個数を求める問題は、右から見ていくと良い（左から見ると単純に足していけない、もちろん累積和も、ので）
### 例題
- [D - Candy Distribution](https://atcoder.jp/contests/abc105/tasks/abc105_d)
- [D - Three Days Ago](https://atcoder.jp/contests/abc295/tasks/abc295_d)
- [D - Range Count Query](https://atcoder.jp/contests/abc248/tasks/abc248_d)
- K以上となる個数問題（尺取りでも二分探索でも） [D - Enough Array](https://atcoder.jp/contests/abc130/tasks/abc130_d)
- 累積和MOD部分列の長さと一致 [E - Rem of Sum is Num](https://atcoder.jp/contests/abc146/tasks/abc146_e)
- 連続部分文字列がMOD Pで0になる個数 [E - Divisible Substring](https://atcoder.jp/contests/abc158/tasks/abc158_e)
- 連続部分文字列がMOD Pで0になる個数 その2 [D - Multiple of 2019](https://atcoder.jp/contests/abc164/tasks/abc164_d)

## 区間和がxの倍数
- 区間和がxの倍数になるとは、[l,r)の累積和Sr-Sl≡0（mod x）、つまりSr≡Slなので、累積和（mod x）が等しければ良い
- 累積和が等しい場合の数を全て加算しておけば、貰うDPで一括で足しこめる
### 例題
- 非常に難しく頭が混乱。DPに慣れた頃に再度解きたい問題 [E - Mod i](https://atcoder.jp/contests/abc207/tasks/abc207_e)

## 区間max値の総和
- 全区間を試すとO(N^2)なので、ある数が何回出現するかを高速にカウントすれば、O(N)（本当はO(NlogN)）で求められる
- 大きい順に見るループを作り、まず自分自身のインデックスをsetに突っ込む
- setの中で、自分より1つ小さいインデックスをlとし、nl = idx - lとする
- setの中で、自分より1つ大きいインデックスをrとし、nr = r - idxとする
- nl * nrが、その数が最大値となる区間数であるので、区間数*その数をansに足していく
- 本テクニックは、区間2nd maxやK-th maxでも応用可能
### 例題
- 区間2nd maxの総和 [E - Second Sum](https://atcoder.jp/contests/abc140/tasks/abc140_e)

# 貪欲法
- 自明な貪欲は簡単だが非自明な貪欲は思いつくのが難しい
- DPで計算量が間に合わないなら貪欲を疑ってみると良い
- 2つ以上の変数がある場合、1つに減らせれば貪欲な選択ができる（区間スケジューリングはその代表例）
- 辞書順最小を求めたい場合、貪欲で求まることが多い
### 例題
- 前から見れば開始時刻は無視してよくなる [D - Printing Machine](https://atcoder.jp/contests/abc325/tasks/abc325_d)
- 後ろから見れば時刻は無視してよくなる [D - Summer Vacation](https://atcoder.jp/contests/abc137/tasks/abc137_d)
- 辞書順最小 [006 - Smallest Subsequence](https://atcoder.jp/contests/typical90/tasks/typical90_f)

## 区間スケジューリング問題
- なるべく多くの会議に出席したい場合、終了時刻で昇順ソートして、貪欲に選択するのが最適
- 昇順ソートしたpairを順に見えていけば良い（開始時刻で二分探索とか変なことを考えると難しくなってしまう）
- 全部で最大K会議選べるとしたとき、最初の1会議をなるべく早く終わらせた方が残りK-1会議の選択肢が増える。2番目、3番目の会議も同様の考え方
- 亜種問題として、全ての会議を串刺しする問題あり。この階は区間スケジューリング問題の解に一致する。終了時刻昇順でソートしたとき、最初に終わる会議をその終了時刻までに選択するしかないが、なるべくたくさん串刺しするには、終了時刻で串刺しした方が残りの会議数を減らせる為
### 例題
- [D - Islands War](https://atcoder.jp/contests/abc103/tasks/abc103_d)

# 全部クリア問題（全クリ）
- 全要素をリセットするようなクエリがある問題の場合、そのクエリがO(N)なので、全体としてO(NQ)となりTLEする
- 情報としてはリセット後だけあれば良いので、その情報だけmapで持てば良い
- リセット時にmapを消すが、ならし計算量はO(1)となるのでTLEしない
### 例題
- [D - All Assign Point Add](https://atcoder.jp/contests/abc278/tasks/abc278_d)

# グラフ

## BFS
- BFSはqueueで実装
- ループの先頭でpopして、空になるまで継続
- queueに入れるのは状態、目的値（最短距離など）はvectorで管理。
- ループありグラフを全探索するなら使用した頂点を訪れないように工夫が必要（目的値が存在しない頂点のみ辿るなど）
- この時、queueに入れる直前にvisitedフラグを立てる等しないと、同距離の頂点が重複してqueueに入ってしまうので注意（目的値を更新しているのであれば特に問題ない）
- 最短経路問題にBFSが使用可能。（e.g. 迷路の最短経路問題、01-BFS）
- 最短経路問題や01-BFSについては動的計画法の章で言及
- ボードゲームの全探索にも使用可能。各マスの状態を並べたベクトルを状態ベクトルとしてqueueに突っ込む

## DFS
- DFSはstackあるいは再帰関数で実装
- 再帰関数で実装する場合、重複演算しないように注意（メモ化再帰で工夫できる場合もある）
- DFSは最終経路まで一つずつ探索する方法であり、再帰関数で実装する事でバックトラックが可能。関数の最初に探索点の履歴をtrue、関数の最後に探索点の履歴をfalseすれば、visited配列を1つ持つだけで実装できる
- グラフのDFSはTLEしないか要チェック。ポイントは再帰呼び出しに重複がないかどうかなので、f(f,x)の手前で再捜索しないような仕組みを入れる
- 具体的にはけんちょんのページが分かりやすい。帰りがけ順使用ノードを再探索しないのは当たり前だが、サイクル検出など行きがけ順済みと帰りがけ順を区別したい場合は別のデータとして持つ事（もちろん行きがけ順使用ノードも再探索しない）
- 頂点を1度だけ訪れれば良い場合は、行きがけ順で探索済みの頂点は再探索不要
- 合計距離Kでゴールにたどり着く迷路問題など、ループを許容し同じ地点での再探索がありうる場合は、頂点以外の情報（距離など）もセットで状態として管理し、状態が同じものは再探索しないようにする
### 例題
- バックトラック (072 - Loop Railway Plan（★4）)[https://xn--atcoder-nr4f8b4xyfyc.jp/contests/typical90/tasks/typical90_bt]

## サイクル検出
- 検出するだけならunion findが使えるかどうか検討の余地あり（ただし入次数2以上が存在する一般の有向グラフでは不可能）
- 一般にはDFSを用いるが、seenとfinishedの両方の情報が必要（けんちょんのページが分かりやすい）
- seenだけだと、有向グラフの途中から探索してseenになっている頂点があったとして、その手前から探索した場合にseenに辿り付いてサイクル検出してしまう
- 例えば、1->2->3で、2から探索すると2と3がseenとなる。次に1から探索すると2のseenに辿り付きサイクル検出してしまう
- 従って現在探索中がseen、完全終了がfinishedにしておく
- 再帰関数をリターンして良いのはサイクル検出した時のみ（検出の瞬間と次頂点がサイクル検出した時）。finishedを見つけてもreturnではなくcontinue（スルー）
- サイクル内の点ではサイクル始点を返し、それ以外は-1を返すdfsを組んでいる場合、自己ループがある場合は要注意
- サイクルを見つけた瞬間＝自分自身を見つけた瞬間という場合もあるので、この場合はちゃんと-1を返すこと
### 例題
- 単純なfunctional graphだが、サイクル検出の難しさを考えさせられる良問 [D - Change Usernames](https://atcoder.jp/contests/abc285/tasks/abc285_d)
- これもfunctional graphだが、自己ループあり[E - Transition Game](https://atcoder.jp/contests/abc296/tasks/abc296_e)
- ダブリングでもOK [058 - Original Calculator（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_bf)

## 木と森
- 要素数が辺の数＋1のとき木になる
- xの最遠点yの最遠点zとすると、yとzの距離が直径となる
- ある要素からの部分木サイズをxとすると、上側部分木のサイズは(N-x)と求まる
- 連結とは限らない閉路を含まないグラフを森という（木が幾つも含まれたグラフ）
- 森の連結成分数は頂点数 - 辺の数
- 次数が2以下の木をパスという（パスは、次数2以下かつ閉路なしで判定可能）
### 例題
- 木の塗分け問題 [E - Virus Tree 2](https://atcoder.jp/contests/abc133/tasks/abc133_e)
- 森の連結成分数の性質 [F - Intervals on Tree](https://atcoder.jp/contests/abc173/tasks/abc173_f)
- DFSしながら期待値（場合の数）を数え上げる [F - Surrounded Nodes](https://atcoder.jp/contests/abc149/tasks/abc149_f)

## オイラーツアーと部分木
- 木に対してDFSの行きがけ順に探索する事をオイラーツアーと呼ぶ
- 各頂点に対し、オイラーツアーの行きがけ順を開始時と終了時に記憶しておくと部分木の半開区間が求まる
### 例題
- [E - Count Descendants](https://atcoder.jp/contests/abc202/tasks/abc202_e)

## パスグラフ
- パスグラフである為の必要十分条件は、連結でありかつ全頂点の次数が2以下の木である事

## スターグラフ（うにグラフ）
- 距離2の頂点組み合わせが最も多くなる（N-1C2）。nC2から最低必要辺数のN-1を引くと一致する事からこれより多くはできないことがわかる
- 針の先同士をつなげば距離2の組み合わせを1つずつ減らせるので、距離2の頂点組み合わせは0以上N-1C2であればすべて実現可能
### 例題
- [E - Friendships](https://atcoder.jp/contests/abc131/tasks/abc131_e)

## 完全グラフ
- 全頂点をつないだグラフで、K_Nなどと書く
- 完全グラフの事をクリークとも呼ぶ

## 最小クリーク被覆問題
- 最小何個の完全グラフで構成されているか（=最小クリーク数）を解く問題
- dpで解く。dp[s]は集合sの最小クリーク数。dp[0]=0、その他INFで初期化
- 2つの部分問題に分解し、それぞれ解く
- (1) s(>=1)がクリークなら1、そうでないならINFのまま
- sのどれでも良いので1つ頂点vを取り出した集合をmsとすると、dp[ms]=1(or0)であり、かつvからmsの全頂点に辺が貼られていればdp[s]=1
- これは、sの小さい順にループを回せば上手くdpテーブルを更新できる
- (2) 各部分集合sに対して、部分集合tとuに分け、chmin(dp[s], dp[t]+dp[u])を繰り返す
- (t,u)を全探索すれば、必ずdp[t]+dp[u]がdp[s]となる(t,u)の組合せが見つかる為
- ちなみに、部分集合の全列挙（s,t,uの全探索）は、各頂点に着目すると、sに選ばれない、sに選ばれるがtに選ばれない、tに選ばれるの3通りなので、3^N通り（uはs^tで求まるのでO(1)）
- 実装方法としては、部分集合tの全列挙は1引いてsとのandを取るを繰り返せば良い
- 計算量はO(N 2^N + 3^N) 3^18≒4e8（N=18）が限界
### 例題
- [F - Close Group](https://atcoder.jp/contests/abc187/tasks/abc187_f)

## なもり木（pseudo tree）
- 頂点数と辺の数が一致する（実際は木ではない）
- 閉ループがただ一つ存在する
- functional graph（任意の頂点に対して出次数が1の有向グラフが描ける）
- UnionFind木を作成後、各辺・各頂点に対して親にカウントしていき、一致していればなもり木である

## DAG（Directed Acyclic Graph）とトポロジカルソート
- DAGは閉路のない有向グラフであり、トポロジカルソートができる事と同値
- その順番であれば逆戻りのない並べ方に変える事をトポロジカルソートと呼ぶ
- トポロジカルソートは入次数が0の頂点をキューに入れ、繋がっている頂点の入次数を1減らしてゼロになればキューに入れる事で実現可能
- あるいはDFSの帰りがけ順を求め、その逆順としても良い（行きがけ順でseen配列を管理して、再度訪れないようにする事）
- 有向グラフの閉路判定は、トポロジカルソートができなければ閉路ありと判定可能（ソート済み配列のsize != N）
- DAGであっても、DFSの計算量が発散する事はありえる（同じ経路を重複して数えてしまう場合）。DFSなら帰りがけ順でfinished配列を管理すると良い（finishedでcontinueするのは再帰関数の直前で！）
### 例題
- [E - Prerequisites](https://atcoder.jp/contests/abc315/tasks/abc315_e)
- 最長経路問題 [G - Longest Path](https://atcoder.jp/contests/dp/tasks/dp_g)

## Functional graph
- 全頂点からの出次数が1のグラフをfunctional graphと呼ぶ
- functional graphは必ずなもり木の形となる（というよりどこから辿ってもサイクルに流入するグラフ）
- functional graphを強連結成分分解すれば、サイクルのみを取り出すことが可能

## 強連結成分分解（SCC[Strongly Connected Components]分解）
- 1度目のDFSで帰りがけ順を記録し、帰りがけ順の逆順に2度目のDFSを実施する
- 2度目のDFSは辺を逆順に辿ることとし、辿り付く頂点が1つの強連結成分である
- 自己ループがあってもSCCは動作する（ただしサイズ1のサイクルになるので、サイクルか非サイクルかの判定が別途必要）
### 例題
- [E - Takahashi's Anguish](https://atcoder.jp/contests/abc256/tasks/abc256_e)
- [021 - Come Back in One Piece（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_u)

## 2部グラフ（二部グラフ）
- 頂点を2色に塗るとき、同じ色が隣り合わないように塗れるグラフ
- 2部グラフである必要十分条件は奇閉路がないこと（例えば木は必ず2部グラフ）
- 再帰関数DFSによって簡単に色塗り可能（BFSでも可）
- DFSして同じ色同士を結んでしまう場合は2部グラフでない
- 異なる連結成分同士を結ぶときは2部グラフを壊すことはない
- 完全2部グラフはKm,nのように表す
- XY平面上の格子系問題ではxとyの2部グラフと考えると上手くいくことがある（点を辺に対応させる）e.g. Must Be Rectangular
### 例題
- [D - Make Bipartitte 2](https://atcoder.jp/contests/abc282/tasks/abc282_d)
- [F - Must Be rectangular!](https://atcoder.jp/contests/abc131/tasks/abc131_f)

## 橋
- 取り除くと連結成分が増える辺を橋と呼ぶ
- low link法を用いるとDFSの計算量O(V+E)で全橋を列挙できる
- ord[v]にDFS行きがけ順、low[v]にエスケープできる頂点の最小行きがけ順を保存
- 文による説明は分かりにくい為、[こちらのyoutube参照](https://www.youtube.com/watch?v=iYJqgMKYsdI)
### 例題
- lowlinkでなくても間に合う制約だが、解法確認にもってこい [C - Bridge](https://atcoder.jp/contests/abc075/tasks/abc075_c?lang=ja)

## ダブリング
- n個先の頂点に進むとき、nが大きい場合、nを2進数で表すと上手くいく
- 前準備として、2^k個だけ進むグラフ辺を作っておく（kは0以上で、2^kがn以上となるkまで）
- あとはnを2進数で表し、1となっている桁に対応する辺を使って進めばよい
### 例題
- [E - Packing Potatoes](https://atcoder.jp/contests/abc258/tasks/abc258_e)　（ダブリング使わずに解いたが・・・）
- ダブリングそのまま問題 [D - Teleporter](https://atcoder.jp/contests/abc167/tasks/abc167_d)

## グラフその他
- 通常は頂点同士のつながりで考えるが、辺に着目（辺をベクターで持つ）することで解ける問題あり。例えば最小全域木を求めるクラスカル法はその良い例。または[全2頂点間最大辺の総和問題](https://atcoder.jp/contests/abc214/tasks/abc214_d)など

# 動的計画法（DP）

## 一般的なこと
- 漸化式は動的計画法で更新すると計算量を抑えられる
- 足していくDPは初期値0、min系DPは初期値INFとする事で、存在しない遷移を考慮しなくて良くなる
- 貰うdpと配るdpはどちらで解いても良いが、貰うdpでないと厳しい場合あり（配ると区間加算が必要だが貰うと単に累積和で良い [D - Leaping Tak](https://atcoder.jp/contests/abc179/tasks/abc179_d)）
- 状態量が10,000など大きくてもNが小さければ使える場合あり。もしかしたら使える可能性もあるので、計算量の見積りは冷静に実施する事
- 各状態が0か1なのであれば、状態をビットセットで持つと演算が楽になる場合あり
- 過去に選んだ番号の集合（bit）と最後に選んだ番号を同時に状態として保持する場合などは、初期化が難しい場合あり（何も選んでいないというdpの枠が作れない為）。このようなときは、そのとき初めて選んだ場合という事でiのループで毎回1増やすなどする（例: [E - Chain Contestant](https://atcoder.jp/contests/abc215/tasks/abc215_e)）
- dpテーブルをpとswapする場合、pの要素を全部なめているか要注意！（dp(N+1)のとき、p[N]からの遷移を忘れずに！！rep(i, N)とすると遷移がなくなるので）
- 初期値を-INFにする場合は要注意。足されて正の値になったら元も子もない。-1を初期値にして処理しないようにした方が無難かもしれない

## カエル型DP
- カエルが1~Kマスジャンプできるとき、最後のマスに到達する場合の数を求める問題
- 問題設定によってはカエル型であることを見抜くのが難しい
- 特に、一つずつの遷移ではないDPが苦手なので、何を状態にできるかよく考えること
### 例題
- 桁和 [042 - Multiple of 9（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_ap)

## DP実装特殊系問題
- 問題によってはvectorではなくmapを使った方が良かったり、値ではなく要素番号（座標圧縮のイメージ）でテーブルを持ったほうが良い場合あり
- 実装になれないと混乱しがちなので問題をまとめておく
### 例題
- [E - Traveler](https://atcoder.jp/contests/abc197/tasks/abc197_e)

## 部分和問題
- （連続でない）部分列の総和がKになる場合の数は単純なDPで解ける
- 部分和が存在するかどうかの単純DPの場合、bitsetでOR演算を繰り返すと超絶楽
- 部分和は各要素を(1+x^A[i])とみなし、全積を取ったときのx^Kの係数が答えとみなす事もできる（難しい問題の時に見通しをよくするテクニック）
- M個選んだ時の部分和の最大値を求める問題は、O(NM)必要（dp[i][j]でj個選んだ時の最大値とかするので）。工夫してjを減らす問題もある
### 例題
- 単純な部分和存在問題 [D - Cooking](https://atcoder.jp/contests/abc204/tasks/abc204_d)
- [F - Knapsack for All Segments](https://atcoder.jp/contests/abc159/tasks/abc159_f)
- 工夫するとdpの状態オーダーを減らせる [F - Select Half](https://atcoder.jp/contests/abc162/tasks/abc162_f)

## 部分集合の部分集合DP
- 全ての部分集合に対して部分和の場合の数を数える問題は、各要素に着目すると、部分集合に選ばれない、部分集合に選ばれるが和には選ばれない、部分集合に選べれ和に選ばれるの3通りがあるので、dp[i][j]（iまで見て和がj）の普通のDPを実施すれば良い（計算量がO(3^N)に関連）
- N=15の時、4^N=1e9、3^N=1e7なので、N=15ぐらいのときはこのテクニックが効いてくる
### 例題
- 全ての部分集合の部分和 [F - Knapsack for All Subsets](https://atcoder.jp/contests/abc169/tasks/abc169_f)
- [E - Lucky bag](https://atcoder.jp/contests/abc332/tasks/abc332_e)

## ナップサックDP
- 縦に要素、横にパターンや最大コスト等を並べて順次更新していく
- 全探索では計算量が間に合わず、幾つか要素がある場合はこれが使えないか検討してみる

## 個数制限なしナップサックDP
- 通常のDPのように、i個目までを選んでという状態を取ってしまうと、個数制限がないのでiを1つ進めるたびにN回のループが発生してしまう
- 重さ制限、残り体力など、通常2つ目に使う状態のみで実は十分。個数制限がない為、i個目まで使ってとか考える必要がないから
- 2次元のまま遷移を高速化するという手法もあり、そっちのほうが実は典型解法かも？？
### 例題
- [E - Crested Ibis vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_e)

## 経路数問題
- 単純にDPで足し合わせていけば経路数が求める
- 座標が大きい場合、map<Pair,ll> dpというdpテーブルを作れば良い（配列にこだわる必要なし）
- 一つの頂点から複数の頂点に行ける場合（飛車など）、累積和用のDPテーブルを持っておき、それぞれ遷移すれば良い（DP->DP、累積DP->累積DP、DP->累積DP、累積DP->DP）
### 例題
- [E - Warp](https://atcoder.jp/contests/abc265/tasks/abc265_e)
- 累積DP [E - Queen on Grid](https://atcoder.jp/contests/abc183/tasks/abc183_e)

## 文字列の部分列
- SがTのある要素を抜き取って並べたものであるとき、SはTの部分列という。連続していなくてもよい。連続している場合は部分文字列という。
- 部分列であるかどうかの判定は、Tのidxを用意し、Sの各文字に対して文字が一致するまでidxを進める（範囲外アクセス注意）
- idxが最後まで進んだら一致しなかったという事でアウト。
### 例題
- [E - Joint Two Strings](https://atcoder.jp/contests/abc324/tasks/abc324_e)
- 部分列そのものの問題ではないが、部分列は先頭から貪欲に取れば判定できる性質を利用 [F - Strivore](https://atcoder.jp/contests/abc171/tasks/abc171_f)

## LCS（Longest Common Subsequence）
- 文字列SとTのそれぞれの部分列（連続でなくてもよい）で一致する最長の長さをLCSという
- Sのi文字目、Tのj文字目まで見たLCSをdp[i][j]と定義し、更新していけば良い
- chmax(dp[i+1][j], dp[i][j]), chmax(dp[i][j+1], dp[i][j])であり、S[i]==T[j]のときのみchmax(dp[i+1][j+1], dp[i][j]+1)する（dpテーブルのiは1-indexed！）
- dpテーブルは全て0で初期化すれば良い（たぶん…）
- SとTでテーブルを書くと遷移がわかりやすい
- 復元するには、dp[i][j]==dp[i-1][j]ならi--、dp[i][j]==dp[i][j-1]ならj--、両方偽なら文字S[i-1]を選択してi--,j--すれば良い
### 例題
- LCSそのものではないが応用問題 [E - Common Subsequence](https://atcoder.jp/contests/abc130/tasks/abc130_e)
- LCSではないが似たようなDP [E - Sequence Matching](https://atcoder.jp/contests/abc185/tasks/abc185_e)
- LCSの復元 [F - LCS](https://atcoder.jp/contests/dp/tasks/dp_f)

## Z-algorithm（Zアルゴリズム）
- 要素iからの部分文字列が要素0からの部分文字列と一致する最大長さを求めるアルゴリズム
- 全探索だとO(N^2)だが、工夫することでO(N)に落とす
- 探索済み部分文字列の中で、最も右まで探索した部分文字列のインデックス[from,last)を記憶しておくのがミソ
- どこまで探索を省略できるかで頭が混乱しがちなので、かつっぱさんのyoutubeを見ると理解できる
- コードがバグっていてもO(N^2)で正しい答えが出てしまうので注意！（最初の要素を飛ばすとか、fromやlastの更新をしなくても正しい答えだけは出てしまうので・・・）
### 例題
- Zアルゴリズムを工夫すれば解ける問題 [E - Who Says a Pun?](https://atcoder.jp/contests/abc141/tasks/abc141_e)

## 区間DP
- 列の中で隣り合うものを順に処理していく問題に活用可能で、計算量はO(N^3)（ケーキの切り分けのように、遷移がO(1)の場合はO(N^2)）
- dp[l][r]で[l,r)での目的となる値を格納（半開区間である事に注意）
- widthを2～Nまで動かして、r=l+widthとする。lは0からN-widthまで動かす。repの終端条件が1ずれないように注意（1足さないと等号成立しない）！
- 遷移させるとき、単にdp[l][k]とdp[k][r]と必ず分割できるのか、A[l]とA[r-1]がくっつくパターンもあり分割できない場合もあるのか、よく考える事（Daruma Otoshiが分割できない良い例）
### 例題
- [N - Slimes](https://atcoder.jp/contests/dp/tasks/dp_n)
- [Matrix Chain Multiplication](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=ja)
- [B - ケーキの切り分け２ (Cake 2)](https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_b)
- [Daruma Otoshi](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp)

## bit DP
- N個の集合から1つずつ何かに割り当てていくとき、O(N!)なのをO(N*2^N)やO(N^2*2^N)ぐらいに落とせる手法
- N=20程度の場合、O(N!)は無理だがO(N*2^N)ならいける！などと制約から思いつくのも手
- 巡回セールスマン問題（TSP: Travelling Salesman Problem）やマッチング数が有名
- 各頂点を1度だけ訪れるという条件がないとbitDPで解けないが、頂点間距離に三角不等式が成り立つならこの条件がなくても解ける（2度以上訪れるメリットがないので）
- 集合から1つ取り除いたときの残りの集合との漸化式により解く
- dp[1がn個のbit列] = dp[1がn-1個のbit列] + 1個を取り除いたときのコストなどとする
- 取り除く時に残りの集合との依存関係がある場合はdp[bit列][要素番号]などとする
- 再帰関数で実装できるが、forループで回す手法も可能
- forループで回す場合、集合sの小さい順にループさせると良い（次のbitを立てるとき、必ずsの昇順となるから）
- なお、遷移の順を単純に考えてBFSで実装する事も可能（下のE-Boosterはそうやって解いた）
- 最短経路問題はforでも再帰でも解けそうだが、ゲームのように後ろからしか決まらないものは再帰でないと厳しい
### 例題
- マッチング数 [O - Matching](https://atcoder.jp/contests/dp/tasks/dp_o)
- [E - Booster](https://atcoder.jp/contests/abc274/tasks/abc274_e)
- [F - Shiritori](https://atcoder.jp/contests/abc278/tasks/abc278_f)
- 実装がやや大変 [E - Magical Ornament](https://atcoder.jp/contests/abc190/tasks/abc190_e)
- bit DPである事を見抜くのが難しい [E - Permutation](https://atcoder.jp/contests/abc199/tasks/abc199_e)
- bit DPである事を見抜くのが難しい2 [D - ぬいぐるみの整理 (Plush Toys)](https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d)

## 桁DP（Digit DP）
- 上位桁から見て、上限をなめているかなめていないかの2通りでDPしていく
- 上限->上限、上限->not上限、not上限->not上限の3通りの遷移がある
- 上限からの遷移が複雑なので注意
- 遷移が複雑なので、i桁目で0-9のどれを選ぶかのループ(rep(d, 10))を回し、その中でp[i][j][k] -> dp[ni][nj][nk]の遷移（すなわちni,nj,nk）がどうなるかのループを回した方が考えやすい
- 引き算の筆算のように、下位桁から考えるDPもある。問題設定によるが、繰り下がりの有無で状態を持つ
### 例題
- 基本 [S - Digit Sum](https://atcoder.jp/contests/dp/tasks/dp_s)
- [D - XXOR](https://atcoder.jp/contests/abc117/tasks/abc117_d)
- 難しいが練習になる [E - Sum Equals Xor](https://atcoder.jp/contests/abc129/tasks/abc129_e)
- [E - Almost Everywhere Zero](https://atcoder.jp/contests/abc154/tasks/abc154_e)
- 繰り下がり型DP [E - Payment](https://atcoder.jp/contests/abc155/tasks/abc155_e)

## 木DP
- DFSをしながら部分木に対する処理を実行していく
- dp[v][k]=頂点vを根とする部分木で状態kの時の場合の数などとすれば良い
- 潜った直後に処理すれば、部分木に対する処理は終わっているはず
### 例題
- 基本 [P - Independent Set](https://atcoder.jp/contests/dp/tasks/dp_p)
- 典型90からの出題だが難しめ [073 - We Need Both a and b（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_bu)

## DP経路復元
- 逆順にたどれば良いだけなのでよく考えればできるはず
- ただし、i=0以外ににも始点がある場合、遡るのを途中でやめなければならない
- 2経路の復元の場合は、常に異なる戦略を取って逆順に辿れば良い
- 複数経路復元は非常に難しい（D - Happy Birthday! 2のsnuke氏解説動画参照）
### 例題
- 想定解はDPではないが、経路復元で解ける（その場合のdiffは跳ね上がる。snuke氏も苦労） [D - Happy Birthday! 2](https://atcoder.jp/contests/abc200/tasks/abc200_d)

## 対戦ゲームDP
- 二人が最適戦略を取るという事は、後ろから考えていくと良い
- dp[自分or相手][状態] = 自分の得点とすると、自分の最適戦略はmax、相手の最適戦略はmin
- 後ろから考えていく場合でも、後ろの情報だけでは決まらない場合もある（例: D - ABS）。しかし必ずしも再起関数の先頭でreturnする必要はなく、最終的にきちんとreturnできれば良い。
### 例題
- 基本 [K - Stones](https://atcoder.jp/contests/dp/tasks/dp_k)
- 基本 [L - Deque](https://atcoder.jp/contests/dp/tasks/dp_l)
- [D - Stones](https://atcoder.jp/contests/abc270/tasks/abc270_d)
- [D - ABS](https://atcoder.jp/contests/abc078/tasks/arc085_b)
- 典型的な対戦ゲームだが、頭の整理に良い [E - Lucky 7 Battle](https://atcoder.jp/contests/abc195/tasks/abc195_e)

## 円環系DP
- 円環問題は最初の選択を固定する事で問題が簡易化する場合あり（不確定要素がなくなるので考えやすくなる）
- 最後の決め方に最初の決め方が依存してしまう場合、最初の選び方を追加次元（dp[最初の選択][現在の選択]）で管理しておき、最初と最後の選択で辻褄が合わない遷移を捨てればよい
- この場合、dpの初期値を埋めるのが若干手間（i=0のときのdpとi>=1の遷移を分けて書く必要あり。最初だけ特別だから）
- 更に綺麗な実装とするには、dp[最後の選択][現在の選択]とし、最後の選択が一致したものだけ採用するという方法もある（snuke解説）
- 円環のどこかに必ず固定できる点があるのであれば、それを1番目かつN+1番目の要素とする事で、円環を固定できる場合あり
### 例題
- [E - Distinct Adjacent](https://atcoder.jp/contests/abc307/tasks/abc307_e)
- [E - Takahashi and Animals](https://atcoder.jp/contests/abc251/tasks/abc251_e)
- [E - Work or Rest](https://atcoder.jp/contests/abc285/tasks/abc285_e)

## LIS 最長増加部分列
- 単調増加する最長の部分列を特定する手法
- 最初にINFで初期化したベクターを準備
- 要素を順番に検査し、自分より大きい数を見つけたら書き換えていくだけで実装可能（実装上は二分探索で挿入位置を見つける）
- 狭義単調増加ならlower_bound、広義単調増加ならupper_boundを使う事に注意！（良く考えないと逆と思ってしまうので注意！）
### 例題
- [F - LIS on tree](https://atcoder.jp/contests/abc165/tasks/abc165_f)
- LIS+少しのひねり [060 - Chimera（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_bh)

## DP高速化
- 遷移するときのループ分をO(1)で実施する
- 累積和やセグメント木が使える
### 例題
- 累積和 [M - Candies](https://atcoder.jp/contests/dp/tasks/dp_m)
- セグ木 x DP [037 - Don't Leave the Spice（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_ak)
- セグ木 x DP [Q - Flowers](https://atcoder.jp/contests/dp/tasks/dp_q)

# 最短経路問題
- 重み無しグラフの最短経路問題はBFSで解ける（始点が複数あってもOK！）
- 0/1重みグラフの最短経路問題は0/1-BFSで解ける（0の場合は先頭にpush）
- 重み有りグラフの最短経路問題はダイクストラ法（後述）
- 重み有りグラフの全頂点最短経路問題はワーシャル・フロイド法（後述）
- 最短経路の中で最大価値を求める（距離を{経路,-価値}のpair型にしてダイクストラやワーシャル・フロイド）
- 移動する点が複数ある時は、その状態をqueueに入れてBFSなど可能
- 2頂点を同時に動かす最短経路問題もある
- 最短経路となるパスの場合の数を同時に求める事も可能（pair型にしておいて、{経路長,数}を更新していけば良い）
### 例題
- [E - Souvenir](https://atcoder.jp/contests/abc286/tasks/abc286_e)
- [E - Swap Places](https://atcoder.jp/contests/abc289/tasks/abc289_e)
- 2頂点 [F - Construct a Palindrome](https://atcoder.jp/contests/abc197/tasks/abc197_f)
- 最短経路＋その場合の数（巡回セールスマン） [G - Revenge of Traveling Salesman Problem](https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g)

## 01-BFS
- 辺のコストが0か1しかない最短経路問題に使用可能
- ダイクストラ法の単純な場合と言っても良い（最小コスト頂点が自明な為。計算も速い）
- 0コスト辺の場合、接続先頂点をqueのfrontに、1コスト辺の場合、接続先頂点をqueのbackにpushする事で実装可能
- 単純BFSのようにdist[nv]!=INFでcontinueしてしまうと上手く動作しないので注意！ダイクストラのように、距離が更新できる時のみ更新するとしないといけない（BFSは書き込まれる距離が昇順だが、01-BFSの場合は書き込まれる距離が2種類ある為）
### 例題
- [043 - Maze Challenge with Lack of Sleep（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_aq)
- [E- Biship 2](https://atcoder.jp/contests/abc246/tasks/abc246_e)
- [D - Wizard in Maze](成分atcoder.jp/contests/abc176/tasks/abc176_d)

## スケート最短経路問題
- 同方向はコスト0、方向転換はコスト1の最短経路問題は、各頂点に方向の状態を持たせ01-BFSあるいはダイクストラすれば解ける
- 同方向は最大Kまでしか進めないという応用問題の場合、方向の状態に加え、同方向は1/K、方向転換は切り上げというダイクストラをすれば解ける（実装上はK倍した値で管理すると良い）
### 例題
- [F - Pond Skater](https://atcoder.jp/contests/abc170/tasks/abc170_f)

## ダイクストラ法（Dijkstra）
- 下記を繰り返していくことで、全頂点の距離を更新していき、最短経路を求める
- 始点（複数可）は0、それ以外の全頂点にINFを代入
- 確定された頂点に接続された頂点を更新
- 未確定頂点の中から最小コスト頂点を確定（その他の頂点がその頂点の距離を更新する事がありえない為）
- 負辺や負閉路があると使えない
- 実装はpriority_queueを用いると簡単。pushした時点の距離が更新されていたらそのpop値は破棄する
- しかしながら、完全グラフなど辺の数が多い場合は、O(N^2)で実装した方が速い。ヨビノリ動画の通りに素直に実装すれば良い。自分で解いた例は[こちら](https://atcoder.jp/contests/joi2014yo/submissions/42739462)
- ダイクストラ木を構成するには、各頂点がどの辺を使って辿りついたのかをキューに入れるタイミングで記録する。計算過程では複数経路で同じ頂点に辿り付くが、最終的に使われた（＝距離を更新した）経路が正しい（自明）。
### 例題
- 典型+α [E - Come Back Quickly](https://atcoder.jp/contests/abc191/tasks/abc191_e)
- 典型+α [E - Train](https://atcoder.jp/contests/abc192/tasks/abc192_e)
- Nの制約から工夫 [E - タクシー (Taxis)](https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_e)

## 拡張ダイクストラ法
- 頂点＋状態をキューに入れていくダイクストラ法
- 例えば、辺に距離だけでなく金銭が必要な場合、所持金を状態としてキューに入れると良い
- 計算量は辺の移動が状態S分だけ増えるので、O(SM)
### 例題
- [E - Two Currencies](https://atcoder.jp/contests/abc164/tasks/abc164_e)

## ワーシャルフロイド法（Warshall-Floyd）
- 全頂点から全頂点への最短経路を求める方法。計算量はO(N^3)
- 3重ループにより、経由値との比較をして順次行列を更新する
- 経由地が一番外側のループ！！（例えばa->b->c->dが最短路の時、a->dを最初に更新してしまうとこの経路は現れない）
- dist[i][i]=0で初期化しないと壊れるので注意！（chmin(d[i][i], d[i][k]+d[k][i]） の時に壊れる）
- 負辺があっても使えるが、負閉路があると使えない（負辺がある場合、INFの辺を使って更新しない事！！！INF＋マイナスの値がINFより小さいので、更新してはいけないものを更新してしまう）
- 自分自身への最短経路が負になった場合、負閉路ががあると検出できる！
- ワーシャルフロイド後の行列が与えられたとして、不要な辺を除く事を考える事もできる
- まず完全グラフを行列の通り作成、次に全3頂点について、三角不等式が等号成立した場合は最大を削除すれば不要な辺を除ける
- この時、同じ辺は1度だけ削除するように！（何度も削除しないように）
- 当然だが、三角不等式が不成立の場合はおかしいので、この場合はワーシャルフロイド後の行列として間違っていたということ
### 例題
- 基本問題 [D - バスと避けられない運命](https://atcoder.jp/contests/abc012/tasks/abc012_4)
- 負閉路検出付きの基本問題 [All Pairs Shortest Path](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja)
- 仕組みを理解する教育的良問 [D - Shortest Path Queries 2](https://atcoder.jp/contests/abc208/tasks/abc208_d)
- ワーシャルフロイド後行列 [D - Restoring Road Network](https://atcoder.jp/contests/abc074/tasks/arc083_b)

## ベルマンフォード法
- 負閉路があっても使える最短経路を求めるアルゴリズムで、計算量はO(NM)
- 負辺がある場合、距離INFの頂点からの更新はしない事！！！INF＋マイナスの値がINFより小さいので、更新してはいけないものを更新してしまう
- 全辺に対して、dist[v] > dist[u] + costである限り更新し続ける
- 更新ステップ数がNを超えたら、負閉路があるということ
- 始点と終点に関係ない点をあらかじめ除いておく事で、関係ない負閉路を使うことを避ける事も重要
### 例題
- [E - Coins Respawn](https://atcoder.jp/contests/abc137/tasks/abc137_e)

## 最小燃料回数問題
- 所持燃料に限界がある場合、補給なしで到達可能な頂点間を長さ1の辺で結ぶ事により、最小補給回数を求めることができる（正しくは最小補給回数+1が求まる）
- もしかしたら辺の張り直しという典型に分類されるか？？
### 例題
- [E - Travel by Car](https://atcoder.jp/contests/abc143/tasks/abc143_e)
- [E - Souvenir](https://atcoder.jp/contests/abc286/tasks/abc286_e)
- [D - Restoring Road Network](https://atcoder.jp/contests/abc074/tasks/arc083_b)

## グラフ＋状態遷移
- 頂点に状態を持たせる事で拡張する手法。頂点と状態をqueに入れる
- queに入ったコスト（得たい値）は別配列cost[v][state]で管理すれば良い
- 迷路の最小方向転換問題などに利用可能（01-BFS＋状態遷移）

## 最小全域木（MST: Minimum Spanning Tree）
- 全域木の中で辺の和が最小のものをいう
- クラスカル法により小さい順に連結頂点同士をつながないように辺を追加していく
- 連結頂点の判定はUnion-Find木を用いる
- Edgeという構造体を定義し、辺の長さで小さい順に並べる。この時、bool operaterで演算を定義しておく
### 例題
- 基本 [Minimum Spanning Tree](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja)
- 工夫して計算量を減らす [D - Built?](https://atcoder.jp/contests/abc065/tasks/arc076_b)

# IMOS法
- 重なり領域の累積はいもす法を用いて解決
- IMOS法は配列数が多すぎるときは座標圧縮とのコンビネーションで解ける問題多し
- 累積ではなく、重なっているかだけの判定で良ければ、引継ぎ型dpで解ける（ある点から何個後ろまで加算すべきかという情報において、何個の部分をmax取りしていけばよい）
- 木の上でもimos法は使える
### 例題
- 基本 [https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_a](A - 鉄道旅行 (Railroad Trip) )
- 引継ぎ型dp [D - 釘 (Nails) ](https://atcoder.jp/contests/joi2012ho/tasks/joi2012ho4)
- [D - Union of Interval](https://atcoder.jp/contests/abc256/tasks/abc256_d)
- 木 [E - Through Path](https://atcoder.jp/contests/abc187/tasks/abc187_e)
- 二次元IMOS [028 - Cluttered Paper（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_ab)

# 括弧列
- 正しい括弧列の条件(1)開きと閉じの数が同じ(2)ある地点で開きの数≧閉じの数
- 括弧列は、開き括弧がある度にスタックを積み、閉じ括弧がある度にスタックを取り出す操作をすれば、対応する括弧の情報を取り出す事ができる
- 括弧列は対応()を一つの頂点としてみると親子関係ができあがるので、根付き木に対応する
- つまりDFS（再帰関数）との相性が良い（＝再帰下降構文解析）
- 閉じ括弧を-1、開き括弧を1として増減させると、大局的な性質が分かる。最下点は閉じれない括弧の数、最下点からの最終到達点までの増加は開いたままの括弧の数となる
### 例題
- [002 - Encyclopedia of Parentheses（★3）](https://atcoder.jp/contests/typical90/tasks/typical90_b)
- [D - Scope](https://atcoder.jp/contests/abc283/tasks/abc283_d)
- [D - Mismatched Parenthesis](https://atcoder.jp/contests/abc307/tasks/abc307_d)
- どのように括弧列同士をつなげると括弧列になるか。つなげ方に工夫が必要 [F - Bracket Sequencing](https://atcoder.jp/contests/abc167/tasks/abc167_f)

# データ構造

## Union Find tree
- 各頂点の連結操作や判定がO(α(N))で可能（α(N)はアッカーマンの逆関数で、実質的にO(1)）
- UnionFind構造体を作る
- parentsの初期化（p[x]を用意し、全てが親、例えば-1としておく）
- find関数（再帰関数で実装すれば良い。実行時、p[x]も更新するとパス圧縮され次回のfindが速くなる）
- unite関数（親同士をくっつける。ただし、同じ連結木はつながないように注意）
- 辺を削除する問題は逆順に見てUnion Findをつなぐ問題に書き換えると解ける場合がある
- Union Findは親に情報を持たせるとデータ管理がしやすい（連結成分のサイズやある点群に繋がっているかなど）
- Union Findは経路存在問題にも応用可能（始点と終点が繋がっていれば経路が存在する）
### 例題
- [E - Blackout 2](https://atcoder.jp/contests/abc264/tasks/abc264_e)
- [E - Round Trip](https://atcoder.jp/contests/abc276/tasks/abc276_e)

## 集合
- Nが大きすぎる場合は、存在する値のみsetやmapで管理し、変更部分だけ操作すれば計算量を抑えられる
### 例題
- [E - White Pawn](https://atcoder.jp/contests/abc203/tasks/abc203_e)


# 2変数問題

## 1変数固定
- 1変数を固定して、もう1変数に対する探索を高速化できないか検討すると計算量が改善するケースあり
### 例題
- [F - Rook Score](https://atcoder.jp/contests/abc298/tasks/abc298_f)

## 平面走査
- (x,y)が順に与えられた場合に、"x1<x2 && y1<y2"となる点が存在するかを判定したい時などに使える
- 1次元の大小判定はソートすれば可能だが2次元だと難しい場合に使えるテクニック
- xの小さい順に走査し、存在するか判定。存在しなければyの値をためていく
- こうすることで、xについての大小判定を気にする必要がなくなる
- xに等しい値が存在する場合の実装に注意
### 例題
- [C - 2D Plane 2N Points](https://atcoder.jp/contests/abc091/tasks/arc092_a)
- 平面走査に辿り着くまでが難しいが良問 [F - Range Set Query](https://atcoder.jp/contests/abc174/tasks/abc174_f)

## 変数分離
- ΣiΣjf(i, j)のようにi,jのループだと計算が間に合わない場合、もしf(i,j) = g(i)h(j)とできればΣig(i)Σjh(j)と分離でき計算量を抑えられる
### 例題
- [D - National Railway](https://atcoder.jp/contests/abc210/tasks/abc210_d)

# セグメントツリー（Segment tree）
- atcoder libraryで使える
- 区間更新・加算、区間min・max・和取得などができる
- モノイドであればセグ木にのる
- セグメント木をDPに使う問題もある。このときは貰うDPの方が使える
### 例題
- [F - Silver Fox vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_f)
- 想定解は違うがセグ木で殴った [E - Bomber](https://atcoder.jp/contests/abc176/tasks/abc176_e)
- セグ木の典型 [F - Simplified Reversi](https://atcoder.jp/contests/abc179/tasks/abc179_f)

# 包除原理
- AでもBでもない場合の数はU-A-B+A∩Bで求まる
- 一般には集合の個数がM個あるとすると、積集合の全組み合わせ2^M通りについて、（符号）積集合[i]の場合の数の総和を求めればよい。符号は積集合のベース集合が奇数ならマイナス、偶数ならプラス（積集合が空集合の場合は全体集合となる）
- rep(i, 1LL<<M)で回せば全組み合わせ列挙できる
- Mが大きいと2^M通りのループは回せないが、完全順列の問題のように場合の数をまとめて数え上げられる場合は使えるケースあり
- 重複組合せで各変数がai≦xi≦biのとき、まず全体からΣaiを引きxi'=xi-aiとすれば全変数0以上と見なせる
- 次に各変数にci=bi-aiの上限がなければ単純な重複組合せ問題だが、包除原理によりj個の変数がci超えとなる場合の数を足したり引いたりすればOK
### 例題
- [F - Tree and Constraints](https://atcoder.jp/contests/abc152/tasks/abc152_f)
- 完全順列の亜種 [E - NEQ](https://atcoder.jp/contests/abc172/tasks/abc172_e)
- 重複組合せの包除原理 [E - Patisserie ABC 2](https://atcoder.jp/contests/abc200/tasks/abc200_e)

# 行列累乗
- 行列累乗でも繰り返し2乗法が使える
- 隣接行列（辺のコストは全て1）をK乗すると、要素(i,j)はiからjへ長さKで辿り着けるパスの個数となる
- こうなる理由はEDPC R - Walkの解説参照
- Nが50以下、Kがかなり大きい（10^9～10^18）の場合、行列累乗が使える可能性あり
### 例題
- [R - Walk](https://atcoder.jp/contests/dp/tasks/dp_r)

# その他典型
## ヒストグラム最大長方形（スパン）
- ヒストグラムの中で取りうる長方形の最大面積を求める問題
- まずは各要素に対して、その要素よりも初めて小さくなる左右の範囲（スパン）を求める
- 左から順番に{高さ,要素番号}のpairをスタックに積んでいくが、自分より高さの高いスタックは二度と使われることがないので捨ててよい。これで左スパンが求まる
- 右スパンも同様に求まるので、最大面積も求まる
### 例題
- [C - Mandarin Orange](https://atcoder.jp/contests/abc189/tasks/abc189_c)

## 実は計算量がlogに落ちる問題
- ΣN/iはNlog(N)なので、二重ループに見えて実は計算がかなり早い問題がある
- 各数の2倍、3倍、4倍、、、を考慮しなければいけない場合、こうなる事が多い
- 箱に入ったボールを次々に移し替えていく場合、少ない方を大きい方に移すことで、各ボールの移し替えられる回数は高々logN回に抑えられる（一般的なマージテク）
### 例題
- [E - Sum of gcd of Tuples (Hard)](https://atcoder.jp/contests/abc162/tasks/abc162_e)
- 一般的なマージテク [F - Colored Ball](https://atcoder.jp/contests/abc329/tasks/abc329_f)
- 一般的なマージテクだがUnionFindの改造が楽 [F - Confluence](https://atcoder.jp/contests/abc183/tasks/abc183_f)

## 標準形を考える
- 直線の傾きは{x, y}（xとyは互いに素、x>=0）で一意に定められる（ただし{0,-1}と{0,1}を分けてしまわないように注意）
### 例題
- [E - ∙ (Bullet)](https://atcoder.jp/contests/abc168/tasks/abc168_e)

## 差分を考える
- O(NK)では解けないが、O(K)では解ける場合、kを固定してO(1)で求められれば全体でO(K)となる
- この時、kを固定してもO(1)で求められないが、kが求まっていればk+1の答えが差分から求められるのであればO(1)になる
### 例題
- [D - Various Sushi](https://atcoder.jp/contests/abc116/tasks/abc116_d)

## 偶奇に注目
- 隣り合う要素を反転できる場合、実は任意の2要素を反転できる事と等しい
- 更に、反転しても要素数（例えば黒の数）の偶奇は変わらない。
### 例題
- [D - Flipping Signs](https://atcoder.jp/contests/abc125/tasks/abc125_d)

## MODで考えてみる
- 求めたい物に割り算が関係する場合、MODで考えてみると見通しが良くなる場合あり。特にDPする際には、MODであれば状態数が減らせる
### 例題
- [F - Potion](https://atcoder.jp/contests/abc192/tasks/abc192_f)

## 不変量を見つける
- 不変量に着目すると解ける問題あり
### 例題
- 順次桁減らし [D - Digit Sum Replace](https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d)

## マンハッタン距離
- 45度回転（して√2倍拡大）した座標系を(a,b)とすると、max(|ai-aj|, |bi-bj|)がマンハッタン距離となる
- maxは結合法則を満たすので、マンハッタン距離の最大値であれば、軸ごとに独立に考えられる
### 例題
- [E - Dist Max](https://atcoder.jp/contests/abc178/tasks/abc178_e)
- [036 - Max Manhattan Distance（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_aj)

## パスカルの三角形
- 各行の総和は2^行番号となる
- ある斜め列のすぐ下側の斜め列は累積和の行列となっている
### 例題
- [F - Many Many Paths](https://atcoder.jp/contests/abc154/tasks/abc154_f)

## 左右から攻める
- ある要素について何かを調べたいとき、左からの情報と右からの情報を前処理として持っておくと、その要素の影響が調べられることがある
### 例題
- [E - Yutori](https://atcoder.jp/contests/abc161/tasks/abc161_e)

## クエリ先読み
- クエリを先読みすると楽に処理できる事がある
### 例題
- [068 - Paired Information（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_bp)
- [D - Decayed Bridges](https://atcoder.jp/contests/abc120/tasks/abc120_d)

## XY独立に考える
### 例題
- [070 - Plant Planning（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_br)
- [F - Minimize Bounding Square](https://atcoder.jp/contests/abc330/tasks/abc330_f)

## bitごとに独立に考える
### 例題
- [086 - Snuke's Favorite Arrays（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_ch)

## 操作列を考える
- 各操作に名前を付け、その操作列を考えると、無駄な連続部分操作列が見つかり、意味のある操作列を考察できる事がある
### 例題
- [F - +1-1x2](https://atcoder.jp/contests/abc188/tasks/abc188_f)

## アフィン変換（同次行列）
- x, yが1次を保ったまま変換される場合は、アフィン返還可能
- アフィン行列を構造体として定義し、アフィン行列同士の積を定義すれば実装が楽になる
### 例題
- [E - Rotate and Flip](https://atcoder.jp/contests/abc189/tasks/abc189_e)

# 関数の形のまま考える
- 合成関数の問題は、f(x)のxに対する処理ではなく、f(x)のグラフ全体（つまり全xに対するf(x)の値）のまま考えると見通しが良くなるケースあり
### 例題
- 自力で性質を考えてACしたが、グラフのまま考えればより自明に解が求まる [E - Filters](https://atcoder.jp/contests/abc196/tasks/abc196_e)

## コロンブスの卵
- 固定するものを入れ替える事で探索量が減るケースあり
- 例えば、N個からM個選んだ総和の絶対値のmaxを調べたいとき、先にM個選ぼうとすると組合せが膨大でTLEする。max(abs(x))はmax(x, -x)なので、そのままの総和と-を付けた総和のmax取りをすればよい。そのままの総和でも-を付けた総和でも、M個の選び方は自明（貪欲）
- 複数のΣがある問題は、Σを入れ替えることで計算量を抑えられることがある
### 例題
- [D - Patisserie ABC](https://atcoder.jp/contests/abc100/tasks/abc100_d)
- [E - Cell Distance](https://atcoder.jp/contests/abc127/tasks/abc127_e)
- [066 - Various Arrays（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_bn)

## 殆どOKなゲーム
- 殆どの手はOKだが、最後の方だけ気を付けないといけないゲーム
- 考察できれば勝ち
### 例題
- [F - Three Variables Game](https://atcoder.jp/contests/abc166/tasks/abc166_f)

# 読解が難しい問題
- 添え字多すぎ問題 [B - Longest Uncommon Prefix](https://atcoder.jp/contests/abc285/tasks/abc285_b)

# 実装が難しい問題
- 考察も難しいが実装も難しい [F - Contrast](https://atcoder.jp/contests/abc178/tasks/abc178_f)


# 実装テクニック

## ラムダ再帰
- auto func = [&](auto func, int x) -> int {return func(func, x)}のようなイメージで書ける
- わざわざグローバル変数にせずとも再帰関数に前提となる変数を渡すことができる（[&]の部分）
- 実際には関数オブジェクトなので関数ではないらしい

## 配列（ベクター）
- 配列の一致判定はv1 == v2で可能（2次元以上でもOK）
- 配列同士の部分一致はequal関数が使用できる（equal(v1.begin(), v1.end(), v2.begin(), v2.end()）)。なお、v2.end()は指定しなくても同じ要素数だけ検索されるので省略可
- v.end()はN-1番目ではなくN番目を指す。すなわち、v.end() - v.begin() = Nとなる事に注意
- 2次元配列をIDに変える場合は x * W + yでhash化すれば良い。ただし、Wはyの範囲であることに注意！
- 隣接行列などは、Nが大きいとMLE（あるいは初期化時にTLE）するので要注意
- vec.size()はunsignedなので、それ同士を引き算してもマイナスにならない（SIZEマクロでll型に変更推奨）
- 数列各要素を±のどちらかにして総和を求める問題は、dp[i][j]=｛iまで見て総和がjになればtrue｝とするのが定石だが、dp[i]=bitsetとすると、dp[i+1] |= dp[i]<<A[i]、dp[i+1] |= dp[i]>>A[i]でOKなのでいちいちループを回さずに済むので楽（https://www.youtube.com/watch?v=tNyPYIhy9MsのE問題解説コードが参考になる）

## 構造体
- コンストラクタを定義したのに引数を指定しないとエラーが出る。no matching function for call to 'Struct::Struct()'コンストラクタにデフォルト引数を指定しておけば解決する
- 構造体にbool operater < (const &Struct s) {return x < s.x}などとすると、構造体同士の演算が定義できる。ただし、priority_queueに使うときは{}の前にconstと書かないとエラーが出る（理由不明） -> 恐らくだが、greater<MYSTRUCT>と書く場合はconst記述が必要。そうしないとoperater>と型が完全一致しないのでエラーが出る
- 自分定義の構造体をN個のvectorにする場合は、初期値を設定しないとエラーになる
- 構造体定義の直下でvectorのサイズを定義すると理由不明だがエラーが出る。初期値関連はコンストラクタで初期化する必要がある

## TLE(Time Limit Exceeded)
- 要素数Nの初期化はO(N)の計算量が必要なことに注意！（次数が3以下のグラフを距離3までBFSする際、BFSのループ回数は少ないが、visited(N)としてしまうとO(N)かかるので注意）

## RE (Runtime Error)
- 多くはゼロ除算もしくは配列外参照
- 他に経験したREとしては、巨大配列vectorがある　（[](https://atcoder.jp/contests/abc273/submissions/45018373)）

## 実装テクニック（その他）
- double型に小数を代入すると、3.1415なのに3.141499999...のように誤差が出てしまう事あり。小数第4位までのdouble型を整数にキャストするときは、round(x*10000)を使うと3.1415は31415となっていて桁落ちなしでキャスト可能（単に(ll)xでは31414になる可能性あり） （eg [D - Circle Lattice Points](https://atcoder.jp/contests/abc191/tasks/abc191_d)）
- 区間[l,r)の一方だけに制限値処理をすると危険（たとえばchmax(l,x)などとするとl>rになりうる）。制限値処理は同時にかける（できればclampで）
- 下桁から処理するwhile文（例えばwhile(x>0){x/=10}）は、x==0のコーナーケースに注意！一度も処理されない
- イベントで処理する場合、時刻が同時のイベントが複数あっても基本はバグらない（時刻差分が0になるだけで何も更新されないので） 例 [D - Snuke Prime](https://atcoder.jp/contests/abc188/tasks/abc188_d)
- multisetでfor文やcountは計算量の面で危険
- 文字列S[i] != 0などと書いてしまうバグる。意外に気付かないので注意！（S[i] != '0'が正しい）
- for(auto [k,v]:map)のループ中にmp.erase(k)すると壊れるので、vl esに消したいkをプッシュバックしておいて後で消す
- accumulate(v.begin(), v.end(), 0LL)は一見便利だが、setに対して使うと壊れるので使わないこと！
- _GLIBCXX_DEBUGオプションはlower_boundを遅くする（ソート済みかの事前チェック）。ループ内にあると酷い事になりうる
- vec.resize(K)で先頭K要素だけ取り出す事が可能
- __builtin_popcountll()と末尾にllを付けないとオーバーフローする可能性あり
- lower_boundで.end()となってしまうのが面倒なので、番兵としてN+1番目の要素に何か入れておくと場合分けが不要となる
- 乱数発生はSTLのメルセンヌツイスタを用いる。rand()はRAND_MAXが小さすぎる（windowsは32767）
- ループ処理の中でごちゃごちゃ場合分けを書くぐらいなら2回ループ回した方がバグらせない（e.g. [C - Pyramid](https://atcoder.jp/contests/abc112/tasks/abc112_c)）
- nCrを何度も呼び出す場合、先に階乗を求めておいた方が速い（そうしないと呼び出す度に2*r回の掛け算が発生する為[実際は逆元の計算も追加で発生]）
- オーダーが数千万の時、無駄な処理を書きすぎるとTLEする可能性あり（定数倍が無視できなくなる）
- mapのkeyにpairを指定する場合、{a, b} (a<=b)となるように並び変えてから
- mapを作る際、keyに対するvalueが複数必要になるかどうか、常に注意
- 配列の値がxとなっている個数を調べたいときは、連想配列を使ってmap[x]=個数を作れば速度が速い（O(logN)）
- ループの中で履歴系の変数を使う際は要注意！毎ループ初期化すべきかそのままにすべきか考慮すること
- 漸化式の初期値（0 or 1）に気を付ける事（自信がなければ幾つか実験する事）
- swapする標準関数あり（swap(a, b)）
- INFを定義するときなどは、1LL<<62のようにLLを忘れずにつけること
- abs関数にはlong long用のllabsがあるのでそちらを使うほうが無難（GCCではabsでもOKらいしが）
- 負整数の割り算に注意！x/yにおいて、xが-(y-1)から-1の間のときも結果は0（切り上げられる形）。除算結果の正負判定は数学的に意味を持たなくなるので、分子・分母をそれぞれ判定する事
- 存在する要素から最小または最大を取り出したいだけのときは、優先度付きキューpriority_queueを用いるとO(logN)で実行可能（全探索すると最小値の判別にO(N)必要）
- setは平衡二分探索木で構成された順序付き集合であり、検索・挿入・削除が全てO(logN)で実行可能。
- x++と++xは代入演算子(=)とセットで使われると挙動が異なる。前置き(++x)はインクリメントされてからの代入となる
- MOD2を定義すると痛い目見る（MOD2と書いたつもりが一つだけMODと書いているなど。デバッグ困難）
- MOD忘れ要注意！

# コンパイルテクニック
- bits/stdc++.hのコンパイルに時間がかかるので、プリコンパイルしておくと良い
- 手元のWSL2 Ubuntu環境では3sec->0.7sぐらいに変化した
- このページ[bits/stdc++.hのインクルードを高速化しよう！（MacOS版）](https://qiita.com/DaikiSuyama/items/e502e09a1090f4a2cee3)がわかりやすい
- stdc++.hの場所は/usr/include/x86~~~/c++/11/bits/にあった。
- 意味は分からないが`gcc -x c++ -v -E /dev/null | grep include`でインクルードパス一覧が出るので、上位階層で`find -name "stdc++.h"`とでも打てば良いだろう

# 計算量
- 問題文にある制約は使うべし（e.g. 一般解を求めると計算量が不足するが、合計枚数9999枚で支払えるとある場合には、その制約内でループを回す事で計算量を制限する事が可能）
- 連想配列mapを使うと、キーへのアクセスがO(logN)で可能。集合setも同様にO(logN)
- 計算量オーダーが10^10程度の場合、もしかしたら間に合うかもしれない。例えば100C5は分母が120なので実際は10^8程度まてオーダーが下がる

# その他のメモ
- 直線の標準系: 傾きを(a, b)ベクトルで持つ（aは正、a=0ならb=1、約分必須）。y切片的なものをc=ay-bxとする。(a,b,c)をが標準系となる。
- 3点が同一直線状である事と外積が0である事は同値
- 円環問題は、2*Nのベクターにすると解けることがある。円環で考えると難しいが直線だと簡単な場合は要検討
- 長方形は対角線上の2点を決めればすべての座標が決まる
- floor(N/i) i=1...Nは高々2*sqrt(N)個しかない。i<=sqrt(N)がsqrt(N)種類、その他のiについてはfloor(N/i)がsqrt(N)以下となるのでsqrt(N)種類という事
- グラフの形からオーダー制約を考えると見通しが良い場合あり（[D - I hate Factorization](https://atcoder.jp/contests/abc166/tasks/abc166_d)）
- WINDOWSでMINGWのgccを使う場合、スタックオーバーフローに注意。AtCoderでは1024MBのスタックサイズが許容されているが、`ulimit -a`で調べると手元では2032KBしか確保されていなかった。ulimitでは変更が上手くいかないので、コンパイル時に`-Wl,--stack,1073741824`を指定して解決した（1073741824[Byte] = 1024MB）
- AtCoderではスペースと改行を区別しないとsnuke氏はおっしゃっていたが、少なくともABC109のD問題では行末にスペースを入れたことでWAした・・・。サンプルまでWAになった場合は疑ってみる価値あり

# これまでに解いた問題数
- 以下は最初に解いた問題群。以降は[Atcoder Problemsで管理](https://kenkoooo.com/atcoder/#/table/)ABCの過去問を解いている
- 競プロ典型90問: （★4以下の全問->後ほど★5以下全問on2023/12/28）
- 分野別　初中級者が解くべき過去問精選 100 問: （問1,10,17,18,24-25,28,32,34-38,44-46,48-49,53,56,60,64,66,68,70,82,85,92,94はatcoderでないためスキップ。52,75,84は難しい為スキップ） ->後ほど全問解いたon2024/1/23
- 1問: [N Slimes](https://atcoder.jp/contests/dp/tasks/dp_n) -> 後ほどEDPC Sまで全問
