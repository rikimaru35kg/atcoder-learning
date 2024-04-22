# はじめに
このページでは、競プロでこれまでに学んだ内容（教訓）を端的に箇条書きします。

# 数や文字の扱い

## 文字列
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
- 文字列の数列は、辞書順に並べるとtrie木の構造となり、前後の文字列と比較するだけでLCAが分かる
### 例題
- 基本 [B - ROT N](https://atcoder.jp/contests/abc146/tasks/abc146_b)
- !要復習 LCP(Longest Common Prefix) [E - Karuta](https://atcoder.jp/contests/abc287/tasks/abc287_e)

## Z-algorhythm（Zアルゴリズム）
- 要素iからの部分文字列が要素0からの部分文字列と一致する最大長さを求めるアルゴリズム
- 全探索だとO(N^2)だが、工夫することでO(N)に落とす
- 探索済み部分文字列の中で、最も右まで探索した部分文字列のインデックス[from,last)を記憶しておくのがミソ
- どこまで探索を省略できるかで頭が混乱しがちなので、かつっぱ氏のyoutubeを見ると理解できる
- コードがバグっていてもO(N^2)で正しい答えが出てしまうので注意！（最初の要素を飛ばすとか、fromやlastの更新をしなくても正しい答えだけは出てしまうので・・・）
### 例題
- !復習価値中 Zアルゴリズムを工夫すれば解ける問題 [E - Who Says a Pun?](https://atcoder.jp/contests/abc141/tasks/abc141_e)
- !要復習 [F - ABCBAC](https://atcoder.jp/contests/abc284/tasks/abc284_f)

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
- !復習価値低 幾つかの区間和から総和が求まるか [E - Range Sums](https://atcoder.jp/contests/abc238/tasks/abc238_e)
- !要復習 XORした後の最大値の最小化 [F - Xor Minimization](https://atcoder.jp/contests/abc281/tasks/abc281_f)

## 2進数
- 2進数を用いると、N桁で2^Nの情報量を表せる
- Nに対し、切り上げと切り捨ての両方で2で割る操作を繰り返して出てくる数は高々2×log(N)個。2進数で考えると明快に分かる（切り捨てのみ繰り返すのと切り上げのみ繰り返すのとの差は高々1しか生まれない）
### 例題
- !要復習 2進数情報量を利用 [E - Bad Juice](https://atcoder.jp/contests/abc337/tasks/abc337_e)
- !復習価値中 [C - Divide and Divide](https://atcoder.jp/contests/abc340/tasks/abc340_c)

## 整数
- 約数と素因数分解は似て非なるもの。約数を列挙したいのか、素因数を列挙したいのか、よく考える
- a, b, cが自然数の時、a*b<=c とa<=floor(c/b)は同値（必要十分条件）
- a, b, cが自然数の時、a*b>c とa>floor(c/b)は同値（必要十分条件）
- c++では負の数の割り算の挙動に注意。a/bはabs(a)/abs(b)に符号を付けたもので、a%bはa=(a/b)*b + a%bが成り立つ値となる（余りが負になる事がある）
- 負の数を割ったときの余りを0以上b未満にしたい場合、余りが負の場合は+bすれば良い
- べき乗はpow(x, n)というSTLがあるが、戻り値がdouble型なので要注意！素直に自作pow関数を使うべき（2のn乗なら1LL<<nで十分）
### 例題
- !要復習 [C - ±1 Operation 1](https://atcoder.jp/contests/abc255/tasks/abc255_c)

## 余り
- c++は余りがマイナスとなる事があるので注意（余りがマイナスなら割る数を足してやると良い）
- 分数形式A/Bで表現された整数をMで割った余りは(A % B*M) / Bで求まる
- A/B = q*M + rであり、A = q*B*M + r*Bなので、M>rである事に注意するとAをB*Mで割った余りはr*Bとなり、Bで割ればrが求まる

## 1000000007（988244353）関連問題
- 掛け算や足し算してMODを上回る可能性がある場合はその都度MODで剰余を取る（最後出力するときにも油断してMOD取るのを忘れないように！！）
- ただし、累積和にMODを取ると途中で減ってしまうので注意！区間和を求める際、MODを取るとマイナスになる事があったり、単純に絶対値を付けられなかったりする
- MODの割り算は逆元を求めれば良く、modpow(x, MOD-2, MOD)で求まる。MODが素数で使えるフェルマーの小定理を利用したもの
- ちなみにMODが素数でない場合の逆元は拡張ユークリッドの互除法により求まる（ただし互いに素でないと逆元は存在しない）
- なお、ACLを用いれば素数かどうか気にする事無く逆元が求まる（普通に割る記号でもいけるし、inv()を使っても良い）
- xとMODが互いに素でないと逆元は存在しないので注意！（最大公約数でお互いに割ってから考察する事が多い）
- 繰り返し二乗法により高速に累乗が求まる
### 例題
- [E - Integer Sequence Fair](https://atcoder.jp/contests/abc228/tasks/abc228_e)
- !要復習 等比級数の和を求める [E - Geometric Progression](https://atcoder.jp/contests/abc293/tasks/abc293_e)

## ユークリッドの互除法（拡張含む）
- gcd(a, b) = gcd(b, r) = ... = gcd(b', 0) = b'という古典的アルゴリズム
- 再帰関数で簡潔に書ける
- 拡張ユークリッドの互除法も再帰関数で簡潔に書ける（ax+by=gcd(a,b)のx, y, gcd(a,b)を求める問題）
- 拡張ユークリッドの互除法は、ax≡b(mod M)を解くのと本質的に同じ。g=gcd(a,M)、ax+My=gを解き、bがgの倍数であれば両辺k(=b/g)倍してa(kx)+M(ky)=bとなるので、kxが答えとなる。なお、bがgの倍数でないときは解なしとなる
### 例題
- !復習価値高 snuke氏の拡張ユークリッド解説動画が神 [E - Throne](https://atcoder.jp/contests/abc186/tasks/abc186_e)

## 最小桁和
- 1からスタートし、+1するか*10するかを繰り返すと任意の自然数を作ることができる
- この時、+1した回数に1を加えると、桁和になる
- 最小桁和を求めたい場合、グラフを作って01-BFSすれば最小桁和を求める事ができる
### 例題
- !要復習 Kの倍数の最小桁和 [D - Small Multiple](https://atcoder.jp/contests/abc077/tasks/arc084_b)

## 有理数
- 有理数を小数で扱うと誤差が出てしまう
- 分母が必ず正の既約分数とし、分母と分子をそれぞれ保存すれば有理数を一対一で表せる
- 有理数ライブラリは便利だが、掛け算や足し算を複数回繰り返すとオーバーフローするので注意
- なお、y=ax+bを標準系として保存したい場合、a=p/qとすると、qy=px+bqとなるので、y切片bではなく分母をかけたbq(=qy-px)を保存すると良い
- ちなみに傾き∞の場合は(p,q,bq)=(1,0,-x)となり、同一標準形で扱える
### 例題
- !要復習 条件を満たす直線は何本？ [E - K-colinear Line](https://atcoder.jp/contests/abc248/tasks/abc248_e)

## 最大公約数と最小公倍数
- 最大公約数は、各素因数の最小指数を選んだもの、最小公倍数は最大指数を選んだものとなる
- 最小公倍数はオーバーフローに注意（1e9以下同士であれば大丈夫だが、それ以上の場合はgcdを求めてオーバーフロー判定する必要あり）
- (a, b, c)のGCDとLCMはそれぞれ、gcd(gcd(a, b), c)、lcm(lcm(a, b), c)と書ける。理由は素因数分解から明らか
- 素因数の指数部が同じであるかどうかの判定は、LCM/GCDを素因数で割り切れるかどうか調べればよい（例えばLCM/GCDが3で割り切れなければ、3の指数部は同じ数。理由は素因数分解から明らか）
- 0, a, 2a, ..., (N-1)aはaとNが互いに素のときMOD Nで全て異なる
- より一般には、0,a,2a,...はg=gcd(a,N)とすると0,g,2g,3g,...(MOD N)を埋めつくす（順番はいろいろ）
### 例題
- !復習価値高 半公倍数 [D - Semi Common Multiple](https://atcoder.jp/contests/abc150/tasks/abc150_d)
- !要復習 グリッド上のGCD [F - Rectangle GCD](https://atcoder.jp/contests/abc254/tasks/abc254_f)
- !要復習 最大公約数の種類数 [E - LCM on Whiteboard](https://atcoder.jp/contests/abc259/tasks/abc259_e)

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
- ただし、10^18の約数（あるいは約数の個数）を全列挙するとTLEするので要注意！
- オーダーではO(N^(1/(loglogN)))らしく、O(sqrt(N))よりは小さいがO(logN)よりは大きい
### 例題
- !復習価値中 [C - Four Variables](https://atcoder.jp/contests/abc292/tasks/abc292_c)
- !復習価値高 約数の個数が少ないが故に解ける問題 [F - Division or Subtraction](https://atcoder.jp/contests/abc161/tasks/abc161_f)

## 積分解（約数類似系）
- M<=abとなるなるべく小さいabに分解するには、aが固定された場合はb=roundup(M/a)となる
- a<=bを仮定すると、a <= roundup(M/a) < M/a + 1よりa^2-a < Mの範囲でaを試せばよい（O(sqrt(M))）
### 例題
- !要復習 [D - M<=ab](https://atcoder.jp/contests/abc296/tasks/abc296_d)

## 周期系数え上げ
- 異なる周期であっても最終的に同じ列になるものを同一視しなければならない場合、最小周期で場合分けすれば重複を排除できる
- しかしながら、周期Tの列を考えると、Tの約数周期の列も重複して数えていることになる
- よって、最小周期が小さい順に求めていき、Tの約数の時の場合の数を全て引けば重複を排除できる
### 例題
- !要復習 [F - Shift Table](https://atcoder.jp/contests/abc304/tasks/abc304_f)

## 素数判定
- sqrt(N)まで試して割れなければ素数である
- 素数関連では最も簡単（素因数分解や素数全列挙と比較して）

## 素因数分解
- 2からsqrt(N)まで試して、割り切れる回数が指数となる
- sqrt(N)まで試して、割り切った数が1でない場合は、その数も素数であるので忘れないように
- ライブラリprime_factorizationとして保存した
- 当たり前だが、その数自身も素数になる可能性があるので、N!の中に素数は最大N個程度ある（sqrt(N)ではないので要注意）
- エラトステネスの篩に真偽ではなく最初に消されたときの数値を記録しておけば、素因数分解を繰り返すときに高速素因数分解できる。ただし篩を作るのにO(NloglogN)かかるので、素因数分解が数個しかない場合は遅くなるので注意
- X<=10^16の素因数の個数は高々13個（2*3*5*...*41）
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
- !要復習（茶diffなのに解けなかった） [D - 250-like Number](https://atcoder.jp/contests/abc250/tasks/abc250_d)
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
- t≡a (mod C)かつt≡b (mod D)となる最小のtを求める問題（ t%LCM(C, D)を求める問題とも言える）
- 式変形により拡張ユークリッドの互除法で解ける
- ACLにcrt関数があり、auto [t, s] = crt({a,b}, {C,D});で求まる
- s==0の場合は解なし
### 例題
- !復習価値中 CRTを思い出すのに役立つ [E - Oversleeping](https://atcoder.jp/contests/abc193/tasks/abc193_e)
- !要復習 インタラクティブ [F - Guess The Number 2](https://atcoder.jp/contests/abc286/tasks/abc286_f)

## 平方数
- 素因数分解したときの指数がすべて偶数なら平方数
- 平方数を考えるときは指数をMOD 2で考える（つまり0か1のみで、0の場合は無いのと同じなので指数が1の素因数の積になる）
- 指数をMOD 2した場合、2数の積が平方数となるのは、同じ数との積のみ
- 指数をMOD 2するには、素因数分解までは不要で、平方数で割れるだけ割ればよい
### 例題
- 基本 平方数数え上げ [D - Together Square](https://atcoder.jp/contests/abc254/tasks/abc254_d)
- !復習価値中 平方数数え上げ [D - Square Pair](https://atcoder.jp/contests/abc342/tasks/abc342_d)

## 小数
- 小数点を出力する際はcout << fixed << setprecision(10) << x << endl;などとしないと小数点以下の桁が6桁ぐらいまでしか出力されない（printf("%.10f\n", x)の方が簡単）
- 小数点の計算は誤差がある為、厳密な大小判定には使えない。整数型に直せれば厳密な判定が可能。
- 小数を整数に入力したい場合、scnaf("%d.%d", &x, &y)で整数、小数を分離して入力可能
- double型に小数を代入すると、3.1415なのに3.141499999...のように誤差が出てしまう事あり。小数第4位までのdouble型を整数にキャストするときは、round(x*10000)を使うと3.1415は31415となっていて桁落ちなしでキャスト可能（単に(ll)xでは31414になる可能性あり）
### 例題
- !要復習 円内格子点の数 [D - Circle Lattice Points](https://atcoder.jp/contests/abc191/tasks/abc191_d)

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
- ゴールするまでの回数の期待値などは、後ろから考えると良い
- あくまで感覚だが、ポイント的なもの（出目の総和など）を状態にもつカエル型DPが多い気がする
- 考察の結果は必ずしも配るDPにはならないので、くどいが良く考える事
### 例題
- !復習価値中 [https://atcoder.jp/contests/abc326/tasks/abc326_e](https://atcoder.jp/contests/abc326/tasks/abc326_e)
- !要復習 期待値としてもDPとしても良問 [E - Roulettes（青diff）](https://atcoder.jp/contests/abc314/tasks/abc314_e)
- !要復習 典型的な期待値DP [E - Sugoroku 3](https://atcoder.jp/contests/abc263/tasks/abc263_e)
- !復習価値高 [E - Roulettes](https://atcoder.jp/contests/abc314/tasks/abc314_e)

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
- 二分探索で最小値を求める問題の場合、f(l)=false、f(r)=trueとなる関数を用いて最終的な答えはr。この時f(x)は答えをx以下（正確にはxを上界）にできるかを返す関数であり、頭が混乱するので注意（Yokan Partyはこの逆）
### 例題
- !復習価値中 二分探索の基本 [001 - Yokan Party（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_a)
- !復習価値高 二分探索良問 [D - 射撃王](https://atcoder.jp/contests/abc023/tasks/abc023_d)
- !要復習 グラフの辺削除 [E - Erasing Vertices 2](https://atcoder.jp/contests/abc267/tasks/abc267_e)
- !要復習 小数の扱いが難しい [E - Logs](https://atcoder.jp/contests/abc174/tasks/abc174_e)
- !復習価値中 混乱しがちな実装だが良問 [E - Handshake](https://atcoder.jp/contests/abc149/tasks/abc149_e)
- !復習価値高 頭が混乱するが良問 [D - Pond](https://atcoder.jp/contests/abc203/tasks/abc203_d)
- !復習価値中 ひねりあり [087 - Chokudai's Demand（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_ci)
- !要復習 有名問題（暗記必須） [D - Project Planning](https://atcoder.jp/contests/abc227/tasks/abc227_d)

## 二分探索による平均最大化
- 分母と分子に変数がある場合の最大値を求めたい場合、答えを決め打つと二分探索に持ち込める場合あり
- 平均最大化はその典型例
- 最短経路問題でsum(bi)/sum(ci)（bi,ciは各辺に割りつけられた価値とコスト）を最大化せよという問題の場合、コストが単純でないので普通に解けない。こんな時に答えXを決め打ちし、それ以上になるかどうかという問題に置き換えると、sum(bi-X*ci)>=0と変形できるので二分探索を使うことができる（なお、この問題は平均最大化という有名テクニック）
### 例題
- !要復習 平均＆中央値最大化（良問） [E - Average and Median](https://atcoder.jp/contests/abc236/tasks/abc236_e)
- !要復習 平均最大化の類題 [F - Beautiful Path](https://atcoder.jp/contests/abc324/tasks/abc324_f)
- !復習価値低 砂糖水濃度最大化 [F - Sugar Water 2](https://atcoder.jp/contests/abc294/tasks/abc294_f)


## 三分探索法
- 狭義に下に凸の区間における最小値を求めるときに使える。
- 幅が2になるまでwhileループさせる
- 最後はleftからrightまでの最小値を求めれば良い
- 最小包含円のようにxy平面で凸な関数となる場合は二重に三分探索すれば良い
- double型の三分探索はr-lの幅ではなく回数を決め打ちすると良いが、収束が意外に遅いので注意。(2/3)^100でも1e-17ぐらいなので、場合によっては100回では足りない
### 例題
- 基本 [D - Freefall](https://atcoder.jp/contests/abc279/tasks/abc279_d)
- 基本 double型の三分探索 [B - ムーアの法則](https://atcoder.jp/contests/arc054/tasks/arc054_b)
- !復習価値中 最小包含円 [F - Enclose All](https://atcoder.jp/contests/abc151/tasks/abc151_f)

## 尺取り法（Two-pointer approach）
- 単調性があるときに使用可能
- 半開区間[l,r)で考えると、要素を全く選ばなかった時も考慮可能なので便利
- [l,r)では条件を満たしているので、条件を満たす範囲でrを進められるだけ進める
- 半開区間なので、while(r<N && sum+A[r]<=K)などして次の[l,r+1)を試す。もともと半開区間のデータ（例えば累積和）であれば、while(r<N && S[r+1]-S[l])などとする
- whileを抜けた後のrはrを進める条件に当てはまらない状態という事
- 例えばwhile(r<N && sum+A[r]<=K)なら、whileを抜けた後はsum+A[r]>Kとなっている（もしくはr==Nかつsum+A[r]<=K）
- whileを抜けた後に直前の値を参照したいならA[r-1]とする必要がある
### 例題
- 基本 [076 - Cake Cut（★3）](https://atcoder.jp/contests/typical90/tasks/typical90_bx)
- 基本 [C - 列](https://atcoder.jp/contests/abc032/tasks/abc032_c)
- !復習価値低 XORの性質 [D - Xor Sum 2](https://atcoder.jp/contests/abc098/tasks/arc098_b)
- !復習価値低 尺取りでなくても解ける [C - Minimize Abs 2](https://atcoder.jp/contests/abc330/tasks/abc330_c)
- !復習価値中 尺取りでなくても解ける [D - Impartial Gift](https://atcoder.jp/contests/abc302/tasks/abc302_d)
- !要復習 最大値X最小値Yとなる区間の総数 [E - Max Min](https://atcoder.jp/contests/abc247/tasks/abc247_e)
- !要復習 交差1の数列が全要素を包含するか（snuke氏考察はオーバーキル） [E - At Least One](https://atcoder.jp/contests/abc260/tasks/abc260_e)

## 半分全列挙
- N=40程度のとき、2^NはTLEするが2^(N/2)であればTLEしない事を利用
- 数列を半分に分け、それぞれで全探索する
- その後、問題に応じて上手く組み合わせる事ができるのであれば使えるアルゴリズムである
- N=10^12程度のとき、10^6に分けるとうまくいくような問題もある（数列の二乗など）
### 例題
- !復習価値低 基本 [C - ダーツ](https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c)
- !要復習 基本 [051 - Typical Shop（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_ay)
- !要復習 XORが0になる経路数 [F - XOR on Grid Path](https://atcoder.jp/contests/abc271/tasks/abc271_f)
- !復習価値中 ロボット移動（実装重め） [F - Robot Rotation](https://atcoder.jp/contests/abc326/tasks/abc326_f)

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
- [C - GCD on Blackboard](https://atcoder.jp/contests/abc125/tasks/abc125_c)
- !要復習 性質を理解していれば解ける [D - Non-decreasing](https://atcoder.jp/contests/abc081/tasks/arc086_b)

## 2次元累積和
- 累積和は2次元でも取れる
- 包除原理的な考え方で累積和を取る
- 区間和を取るときも包除原理的な考え方でやる
### 例題
- 基本 [A - 惑星探査 (Planetary Exploration)](https://atcoder.jp/contests/joi2011ho/tasks/joi2011ho1)
- 基本 [D - AtCoder Express 2](https://atcoder.jp/contests/abc106/tasks/abc106_d)
- !復習価値低 [D - Checker](https://atcoder.jp/contests/abc086/tasks/arc089_b) なお、この問題は何も考えずにlong longを使いすぎるとMLEする

## BIT木（Fenwick tree）
- 元の配列が動的に変わるときの要素iまでの累積和を高速（logN）で求める事ができる
- 個数を保存しておけば、ある値以下の個数を求める事にも使える
- 累積和のlower_boundも実装する事ができるので、ある値以下に何個存在するかも求める事ができる
### 例題
- !復習価値中 想定解は非BIT木 [E - Least Elements](https://atcoder.jp/contests/abc281/tasks/abc281_e)

## 連続部分列問題
- 左右を固定してO(N^2)を考えた後、右端を固定して高速に求められないか検討すると良い
- キーワード：連続部分列は累積和！（もしくは尺取り法）
- 和がKとなる連続部分列が存在するかどうかは、累積和をsetに入れておけば判定可能。S[i]+KとなるS[j]が存在するのであれば、[i,j)の和はKという事
- 連続部分列の和がある値Kとなる個数を求めるには、Sr-Sl=Kとなれば良いので、Slをmap[Sl]=（Slとなる個数）としておけば高速に求められる
- map[0] = 1という初期化を忘れずに！（累積和は0から始まる）
- 数列の連続部分列[L,R]の中で値がKに一致する個数を求める場合、事前にK毎にvectorを用意しておき、そのvectorにKとなる要素番号を格納しておく。後は[L,R]となる個数をupper_boundで調べれば良い
- Kと一致ではなくK以上の個数などとなる場合はmapで累積和を保存しても個数が求められないので尺取り法か二分探索
- 累積和のMODが部分列の長さと一致するという問題でも応用可能。具体的には最初に1ずつ引いた数列にしておけば、累積和を取った時に長さ分の考慮が不要となる
- 0-9で構成された連続部分文字列がMOD Pで0になる個数を求める問題は、右から見ていくと良い（左から見ると単純に足していけない、もちろん累積和も、ので）
### 例題
- !復習価値高 なぜか典型解法を忘れていた [D - Candy Distribution](https://atcoder.jp/contests/abc105/tasks/abc105_d)
- !復習価値低 [D - Three Days Ago](https://atcoder.jp/contests/abc295/tasks/abc295_d)
- !復習価値高 茶diff？ [D - Range Count Query](https://atcoder.jp/contests/abc248/tasks/abc248_d)
- !復習価値低 K以上となる個数問題（尺取りでも二分探索でも） [D - Enough Array](https://atcoder.jp/contests/abc130/tasks/abc130_d)
- !復習価値高 累積和MODが部分列の長さと一致の個数数え上げ [E - Rem of Sum is Num](https://atcoder.jp/contests/abc146/tasks/abc146_e)
- 連続部分文字列がMOD Pで0になる個数 その1 [D - Multiple of 2019](https://atcoder.jp/contests/abc164/tasks/abc164_d)
- !復習価値中 連続部分文字列がMOD Pで0になる個数 その2 [E - Divisible Substring](https://atcoder.jp/contests/abc158/tasks/abc158_e)
- !要復習 [E - LEQ](https://atcoder.jp/contests/abc221/tasks/abc221_e)

## Mo's Algorithm
- 連続部分列の区間1増減をO(1)で計算できる場合、クエリ回数QとするとO(N sqrt(Q))で全てのクエリに答えられる
- クエリ[l,r)を座標上にプロットし、sqrt(Q)個に分割（すなわち高さをN/sqrt(Q)に分割）し、各分割ブロックごとに小さい順に辿って行けば良い
### 例題
- [G - Range Pairing Query](https://atcoder.jp/contests/abc242/tasks/abc242_g)

## 区間和がxの倍数
- 区間和がxの倍数になるとは、[l,r)の累積和Sr-Sl≡0（mod x）、つまりSr≡Slなので、累積和（mod x）が等しければ良い
- 累積和が等しい場合の数を全て加算しておけば、貰うDPで一括で足しこめる
### 例題
- !要復習 非常に難しく頭が混乱。DPに慣れた頃に再度解きたい問題 [E - Mod i](https://atcoder.jp/contests/abc207/tasks/abc207_e) なお、snuke氏の解説だけでは理解が難しいので、[コメントを付きでコードを提出](https://atcoder.jp/contests/abc207/submissions/49805079)

## ある順列P{1,2,...,N}の区間max値の総和
- 全区間を試すとO(N^2)なので、ある数が何回出現するかを高速にカウントすれば、O(N)（本当はO(NlogN)）で求められる
- 数が大きい順に見るループを作り、まず自分自身のインデックスをsetに突っ込む
- setの中で、自分より1つ小さいインデックスをlとし、nl = idx - lとする
- setの中で、自分より1つ大きいインデックスをrとし、nr = r - idxとする
- nl * nrが、その数が最大値となる区間数であるので、区間数*その数をansに足す
- 文章ではわかりにくいので、[snuke氏の解説参照](https://www.youtube.com/live/VSeggcnxwrc?feature=shared&t=5618)
- 本テクニックは、区間2nd maxやK-th maxでも応用可能
### 例題
- 区間2nd maxの総和 [E - Second Sum](https://atcoder.jp/contests/abc140/tasks/abc140_e)

## 区間スケジューリング問題
- なるべく多くの会議に出席したい場合、終了時刻で昇順ソートして、貪欲に選択するのが最適
- 昇順ソートしたpairを順に見えていけば良い
- ソート済みpair（すなわち区間）を図示するとイメージしやすい。M区間に対してrep(i,M)して、それぞれどういう処理をすれば良いか考えれば実装できる
- 全部で最大K会議選べるとしたとき、最初の1会議をなるべく早く終わらせた方が残りK-1会議の選択肢が増える。2番目、3番目の会議も同様の考え方
- 亜種問題として、全ての会議を串刺しする問題あり。この階は区間スケジューリング問題の解に一致する。終了時刻昇順でソートしたとき、最初に終わる会議をその終了時刻までに選択するしかないが、なるべくたくさん串刺しするには、終了時刻で串刺しした方が残りの会議数を減らせる為
### 例題
- !要復習 亜種問題 [D - Islands War](https://atcoder.jp/contests/abc103/tasks/abc103_d)
- !復習価値低 フが何個見えるか [E - フ](https://atcoder.jp/contests/abc225/tasks/abc225_e)

# 貪欲法
- 自明な貪欲は簡単だが非自明な貪欲は思いつくのが難しい
- DPで計算量が間に合わないなら貪欲を疑ってみると良い
- 2つ以上の変数がある場合、1つに減らせれば貪欲な選択ができる（区間スケジューリングはその代表例）
- 区間スケジューリング類似問題は、何らかの形で範囲の形として表せれば、解法が思いつきやすい。あるいは範囲を考える問題では貪欲法を疑ってみると良い
- 辞書順最小を求めたい場合、貪欲で求まることが多い
### 例題
- !復習価値中（実装難しめ） キーエンスプリント機械 [D - Printing Machine](https://atcoder.jp/contests/abc325/tasks/abc325_d)
- !復習価値中 区間ボール入れ [E - Packing Under Range Regulations](https://atcoder.jp/contests/abc214/tasks/abc214_e)
- !要復習 日雇いアルバイト問題 [D - Summer Vacation](https://atcoder.jp/contests/abc137/tasks/abc137_d)
- !要復習 辞書順最小 [006 - Smallest Subsequence](https://atcoder.jp/contests/typical90/tasks/typical90_f)
- !要復習 クーポンマッチング問題 [F - Vouchers](https://atcoder.jp/contests/abc308/tasks/abc308_f)

# 全要素更新問題（全クリア）
- 全要素を一斉更新（リセット、加算など）するようなクエリがある問題の場合、そのクエリがO(N)なので、全体としてO(NQ)となりTLEする
- 全要素一斉更新の情報を一つのスカラー情報として持ち、回答クエリの時のみその情報を活用する方針が良い
- リセット型クエリの場合、リセット値とリセット後の情報だけmap等で持てば良い
- 最初は0リセットされていると考え、初期状態を全部mapに突っ込んでおく（と実装が楽）
- リセット時にmapを消すが、ならし計算量はO(1)となるのでTLEしない
- 加算型クエリの場合、加算値と加算前の情報を持てば良い
### 例題
- !復習価値低 snuke氏の実装が参考になる [D - All Assign Point Add](https://atcoder.jp/contests/abc278/tasks/abc278_d)
- 基本 [D - Querying Multiset](https://atcoder.jp/contests/abc212/tasks/abc212_d)

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
- 木DFSの超基本 [C - Simple path](https://atcoder.jp/contests/abc270/tasks/abc270_c)
- 基本 [E - Round Trip](https://atcoder.jp/contests/abc276/tasks/abc276_e)
- !復習価値中 バックトラック (072 - Loop Railway Plan（★4）)[https://atcoder.jp/contests/typical90/tasks/typical90_bt]
- !要復習 お堀 [E - Moat](https://atcoder.jp/contests/abc219/tasks/abc219_e)

## サイクル検出
- 検出するだけならunion findが使えるかどうか検討の余地あり（ただし入次数2以上が存在する一般の有向グラフでは不可能）
- 一般にはDFSを用いるが、seenとfinishedの両方の情報が必要（けんちょんのページが分かりやすい）
- seenだけだと、有向グラフの途中から探索してseenになっている頂点があったとして、その手前から探索した場合にseenに辿り付いてサイクル検出してしまう
- 例えば、1->2->3で、2から探索すると2と3がseenとなる。次に1から探索すると2のseenに辿り付きサイクル検出してしまう
- 従って現在探索中がseen、完全終了がfinishedにしておく
- 再帰関数をリターンして良いのはサイクル検出した時のみ（検出の瞬間と次頂点がサイクル検出した時）。finishedを見つけてもreturnではなくcontinue（スルー）
- 再帰関数の途中でリターンする場合、必ずfinishedをtrueにするのを忘れずに！（サイクルが複数ある場合は必須）
- サイクル内の点ではサイクル始点を返し、それ以外は-1を返すdfsを組んでいるsnuke式の場合、自己ループがある場合は要注意
- サイクルを見つけた瞬間＝自分自身を見つけた瞬間という場合もあるので、この場合はちゃんと-1を返すこと
### 例題
- 基本 [F - Well-defined Path Queries on a Namori](https://atcoder.jp/contests/abc266/tasks/abc266_f)
- !復習価値中 サイクル検出のみ（サイクル部復元なし） [D - Change Usernames](https://atcoder.jp/contests/abc285/tasks/abc285_d)
- !復習価値中 自己ループありのfunctional graph [E - Transition Game](https://atcoder.jp/contests/abc296/tasks/abc296_e)
- !復習価値低 ダブリングでもOK [058 - Original Calculator（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_bf)
- !復習価値高 不満度最小化 [E - Takahashi's Anguish](https://atcoder.jp/contests/abc256/tasks/abc256_e)

## 木と森
- 要素数が辺の数＋1のとき木になる
- ある要素からの部分木サイズをxとすると、上側部分木のサイズは(N-x)と求まる
- 連結とは限らない閉路を含まないグラフを森という（木が幾つも含まれたグラフ）
- 森の連結成分数は頂点数 - 辺の数
- 次数が2以下の木をパスという（パスは、次数2以下かつ閉路なしで判定可能）
### 例題
- !要復習（惜しかった!） 森の連結成分数の性質 [F - Intervals on Tree](https://atcoder.jp/contests/abc173/tasks/abc173_f)
- !復習価値中 木で穴あき度の期待値計算 [F - Surrounded Nodes](https://atcoder.jp/contests/abc149/tasks/abc149_f)
- !要復習 任意の頂点からのコストmax点 [F - Expensive Expense](https://atcoder.jp/contests/abc222/tasks/abc222_f)

## 木の直径、重心
- xの最遠点yの最遠点zとすると、yとzの距離が直径となる
- 任意の頂点vからの最遠点は、yかzのどちらかである
- ある頂点から与えれた距離の頂点を素早く見つけるには、直径の端点からのパスだけ記録して置けば良い（最も遠い点はどちらかの端点になるはずなので）
- 辺を移動する際、移動先部分木のサイズが移動前部分木のサイズより大きいなら移動、を繰り返すことで重心に辿り着ける
- 言い換えると、移動先部分木サイズが総和/2より大きければ移動すれば良い
- 実装ではDFS全探索中に、全部分木サイズが総和/2以下であれば重心としてメモすれば良い
### 例題
- 木の直径基本 [003 - Longest Circular Road（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_c)
- !要復習 木の頂点からある距離にある頂点 [F - Exactly K Steps](https://atcoder.jp/contests/abc267/tasks/abc267_f)
- !要復習 木の重心（超簡単な全方位木DPの練習にも） [E - Minimize Sum of Distances](https://atcoder.jp/contests/abc348/tasks/abc348_e)

## オイラーツアーと部分木
- 木に対してDFSの行きがけ順に探索する事をオイラーツアーと呼ぶ
- 各頂点に対し、オイラーツアーの行きがけ順を開始時と終了時に記憶しておくと部分木の半開区間が求まる
- 各頂点を探索している時に、その頂点に対する操作をするのか、あるいは繋がっている全頂点に対する操作（場合の数をかける等）をするのか、色々バリエーションあり
- 区間をぎっちり詰めたい場合は、葉の個数分だけの区間長になる（この場合は葉のたびにインクリメント）
### 例題
- !復習価値高 オイラーツアーの性質 [E - Count Descendants](https://atcoder.jp/contests/abc202/tasks/abc202_e)
- !要復習 木の塗分け問題 [E - Virus Tree 2](https://atcoder.jp/contests/abc133/tasks/abc133_e)
- !復習価値高 部分木を区間で表現 [E - Ranges on Tree](https://atcoder.jp/contests/abc240/tasks/abc240_e)

## LCA（Lowest Common Ancester）
- 色々やり方はあるらしいが、Euler Tourを用いる方法を学習した
- オイラーツアーの順に区間用のセグツリーやBIT木を適用すると色々対応可能
### 
- !要復習 木の頂点間距離 w/オンラインコスト変化 [G - Distance Queries on a Tree](https://atcoder.jp/contests/abc294/tasks/abc294_g)

## 完全二分木
- 全ての葉が同じ深さを持ち、葉以外の全ての頂点が子を二つ持つ二分木を完全二分木と呼ぶ
- 再帰的な構造を持っている為、高さhの関数f[h]はf[h-1]を用いて計算できる事が多い
### 例題
- 基本 [D - Moves on Binary Tree](https://atcoder.jp/contests/abc243/tasks/abc243_d)
- !要復習 距離Dとなるパスの個数 [E - Distance on Large Perfect Binary Tree](https://atcoder.jp/contests/abc220/tasks/abc220_e)
- !要復習 距離Dとなる頂点の個数 [E - Complete Binary Tree](https://atcoder.jp/contests/abc321/tasks/abc321_e)

## パスグラフ
- パスグラフである為の必要十分条件は、連結でありかつ全頂点の次数が2以下の木である事

## スターグラフ（うにグラフ）
- 距離2の頂点組み合わせが最も多くなる（N-1C2）。nC2から最低必要辺数のN-1を引くと一致する事からこれより多くはできないことがわかる
- 針の先同士をつなげば距離2の組み合わせを1つずつ減らせるので、距離2の頂点組み合わせは0以上N-1C2であればすべて実現可能
### 例題
- !復習価値高 スターグラフの性質 [E - Friendships](https://atcoder.jp/contests/abc131/tasks/abc131_e)

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
- !要復習 [F - Close Group](https://atcoder.jp/contests/abc187/tasks/abc187_f)

## DAG（Directed Acyclic Graph）とトポロジカルソート
- DAGは閉路のない有向グラフであり、トポロジカルソートができる事と同値
- その順番であれば逆戻りのない並べ方に変える事をトポロジカルソートと呼ぶ
- BFS式: トポロジカルソートは入次数が0の頂点をキューに入れ、繋がっている頂点の入次数を1減らしてゼロになればキューに入れる事で実現可能
- DFS式: あるいはDFSの帰りがけ順を求め、その逆順としても良い（行きがけ順でseen配列を管理して、再度訪れないようにする事）
- 有向グラフの閉路判定は、トポロジカルソートができなければ閉路ありと判定可能（ソート済み配列のsize != N、ただしこの判定方式はBFS式でソートした場合のみ）
- DAGであっても、DFSの計算量が発散する事はありえる（同じ経路を重複して数えてしまう場合）ので、同じ頂点を何度も探索しないようにする事
- DAGはサイクルがないので、後ろから辿ると最長経路問題を解くことが可能
### 例題
- 基本 [D - Restricted Permutation](https://atcoder.jp/contests/abc223/tasks/abc223_d)
- !復習価値中 基本の復習に丁度良い [E - Prerequisites](https://atcoder.jp/contests/abc315/tasks/abc315_e)
- !復習価値中 基本の復習に丁度良い 最長経路問題 [G - Longest Path](https://atcoder.jp/contests/dp/tasks/dp_g)
! 要復習 巨大マス目上の最長経路問題 [E - Integers on Grid](https://atcoder.jp/contests/abc224/tasks/abc224_e)

## なもりグラフ（pseudo tree）とFunctional graph
- 頂点数と辺の数が一致する（実際は木ではない）
- 閉ループがただ一つ存在する
- functional graph（任意の頂点に対して出次数が1の有向グラフが描ける）
- UnionFind木を作成後、各辺・各頂点に対して親にカウントしていき、一致していればなもりグラフである
- functional graphは必ずなもりグラフの形となる（というよりどこから辿ってもサイクルに流入するグラフ）
- functional graphを強連結成分分解すれば、サイクルのみを取り出すことが可能
### 例題
- 基本 [E - Just one](https://atcoder.jp/contests/abc226/tasks/abc226_e)

## 強連結成分分解（SCC[Strongly Connected Components]分解）
- 1度目のDFSで帰りがけ順を記録し、帰りがけ順の逆順に2度目のDFSを実施する
- 2度目のDFSは辺を逆順に辿ることとし、辿り付く頂点が1つの強連結成分である
- 自己ループがあってもSCCは動作する（ただしサイズ1のサイクルになるので、サイクルか非サイクルかの判定が別途必要）
- SCC後、強連結成分毎に見るとトポロジカル順に並べたDAGになっている
### 例題
- !復習価値中 基本 [021 - Come Back in One Piece（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_u)
- !復習価値低 基本 [E - Wrapping Chocolate](https://atcoder.jp/contests/abc245/tasks/abc245_e)

## 2部グラフ（二部グラフ）
- 頂点を2色に塗るとき、同じ色が隣り合わないように塗れるグラフ
- 2部グラフである必要十分条件は奇閉路がないこと（例えば木は必ず2部グラフ）
- 再帰関数DFSによって簡単に色塗り可能（BFSでも可）
- DFSして同じ色同士を結んでしまう場合は2部グラフでない
- 異なる連結成分同士を結ぶときは2部グラフを壊すことはない
- 完全2部グラフはKm,nのように表す
- XY平面上の格子系問題ではxとyの2部グラフと考えると上手くいくことがある（点を辺に対応させる）e.g. Must Be Rectangular
### 例題
- !要復習 2部グラフの性質 [D - Make Bipartitte 2](https://atcoder.jp/contests/abc282/tasks/abc282_d)
- !要復習 考察メイン [F - Must Be rectangular!](https://atcoder.jp/contests/abc131/tasks/abc131_f)

## 橋
- 取り除くと連結成分が増える辺を橋と呼ぶ
- low link法を用いるとDFSの計算量O(V+E)で全橋を列挙できる
- ord[v]にDFS行きがけ順、low[v]にエスケープできる頂点の最小行きがけ順を保存
- 文による説明は分かりにくい為、[こちらのyoutube参照](https://www.youtube.com/watch?v=iYJqgMKYsdI)
### 例題
- !要復習 lowlinkでなくても間に合う制約だが、解法確認にもってこい [C - Bridge](https://atcoder.jp/contests/abc075/tasks/abc075_c?lang=ja)

## ダブリング
- n個先の頂点に進むとき、nが大きい場合、nを2進数で表すと上手くいく
- 前準備として、2^k個だけ進むグラフ辺を作っておく（kは0以上で、2^kがn以上となるkまで）
- あとはnを2進数で表し、1となっている桁に対応する辺を使って進めばよい
### 例題
- 基本 [D - Teleporter](https://atcoder.jp/contests/abc167/tasks/abc167_d)
- !復習価値中 考察1つ [E - Packing Potatoes](https://atcoder.jp/contests/abc258/tasks/abc258_e)

## グラフその他
- 通常は頂点同士のつながりで考えるが、辺に着目（辺をベクターで持つ）することで解ける問題あり。例えば最小全域木を求めるクラスカル法はその良い例。または下の例題（Sum of Maximum Weights）など
### 例題
- !要復習 全2頂点間最大辺の総和問題 [D - Sum of Maximum Weights](https://atcoder.jp/contests/abc214/tasks/abc214_d)

## グラフに関する問題の計算量見積り
- ダイクストラ法やBFSの計算量は、辺の数で抑えられる（O(N+M)、O((N+M)log(M)など）
- 各辺は確定頂点からしか呼ばれる事はなく、各辺は2頂点としか繋がっていない為、高々2回しか呼ばれない
- グラフを用いたDPなどでも、同じ議論は成り立つので、計算量はO(NM)ではなくO(N+M)かもしれない事に注意せよ
### 例題
- [E - Safety Journey](https://atcoder.jp/contests/abc212/tasks/abc212_e)

# 動的計画法（DP）

## 一般的なこと
- 【重要！】DP（≒メモ化再帰）は状態を頂点とするグラフがDAG（トポソできる）でないと演算不可能（例えば[D - Multiply and Rotate](https://atcoder.jp/contests/abc235/tasks/abc235_d)は良い例）
- 漸化式は動的計画法で更新すると計算量を抑えられる
- 足していくDPは初期値0、min系DPは初期値INFとする事で、存在しない遷移を考慮しなくて良くなる
- 貰うdpと配るdpはどちらで解いても良いが、貰うdpでないと厳しい場合あり（配ると区間加算が必要だが貰うと単に累積和で良い（例: D - Leaping Tak）
- 状態量が10,000など大きくてもNが小さければ使える場合あり。もしかしたら使える可能性もあるので、計算量の見積りは冷静に実施する事
- 各状態が0か1なのであれば、状態をビットセットで持つと演算が楽になる場合あり
- 過去に選んだ番号の集合（bit）と最後に選んだ番号を同時に状態として保持する場合などは、初期化が難しい場合あり（何も選んでいないというdpの枠が作れない為）。このようなときは、そのとき初めて選んだ場合という事でiのループで毎回1増やすなどする（例: E - Chain Contestant）
- dpテーブルをpとswapする場合、pの要素を全部なめているか要注意！（dp(N+1)のとき、p[N]からの遷移を忘れずに！！rep(i, N)とすると遷移がなくなるので）
- 初期値を-INFにする場合は要注意。足されて正の値になったら元も子もない。-1を初期値にして処理しないようにした方が無難かもしれない

## カエル型DP
- カエルが1~Kマスジャンプできるとき、最後のマスに到達する場合の数を求める問題
- 問題設定によってはカエル型であることを見抜くのが難しい
- 特に、一つずつの遷移ではないDPが苦手なので、何を状態にできるかよく考えること
### 例題
- !要復習 桁和 [042 - Multiple of 9（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_ap)

## DP実装特殊系問題
- 問題によってはvectorではなくmapを使った方が良かったり、値ではなく要素番号（座標圧縮のイメージ）でテーブルを持った方が実装が楽になる場合あり
- 実装になれないと混乱しがちなので問題をまとめておく
### 例題
- !復習価値中 [E - Traveler](https://atcoder.jp/contests/abc197/tasks/abc197_e)

## 部分和問題
- （連続でない）部分列の総和がKになる場合の数は単純なDPで解ける
- 部分和が存在するかどうかの単純DPの場合、bitsetでOR演算を繰り返すと超絶楽（ビット数に気を付けて！！）
- 部分和は各要素を(1+x^A[i])とみなし、全積を取ったときのx^Kの係数が答えとみなす事もできる（難しい問題の時に見通しを良くするテクニック）
- 上記は結局、rep(i,N)の毎ループでdp[0]++をしてから普通の部分和問題を解く事に一致する
- M個選んだ時の部分和の最大値を求める問題は、O(NM)必要（dp[i][j]でj個選んだ時の最大値とかするので）。工夫してjを減らす問題もある
### 例題
- !復習価値低 基本 [D - Cooking](https://atcoder.jp/contests/abc204/tasks/abc204_d)
- !要復習 全連続部分列での部分和個数総和 [F - Knapsack for All Segments](https://atcoder.jp/contests/abc159/tasks/abc159_f)
- !要復習 工夫するとdpの状態オーダーを減らせる [F - Select Half](https://atcoder.jp/contests/abc162/tasks/abc162_f)

## 部分集合の部分集合DP
- 全ての部分集合に対して部分和の場合の数を数える問題は、各要素に着目すると、部分集合に選ばれない、部分集合に選ばれるが和には選ばれない、部分集合に選べれ和に選ばれるの3通りがあるので、dp[i][j]（iまで見て和がj）の普通のDPを実施すれば良い（計算量がO(3^N)に関連）
- N=15の時、4^N=1e9、3^N=1e7なので、N=15ぐらいのときはこのテクニックが効いてくる
### 例題
- !要復習 分散最小袋分け [E - Lucky bag](https://atcoder.jp/contests/abc332/tasks/abc332_e)

## ナップサックDP
- 縦に要素、横にパターンや最大コスト等を並べて順次更新していく
- 全探索では計算量が間に合わず、幾つか要素がある場合はこれが使えないか検討してみる

## 個数制限なしナップサックDP
- 通常のDPのように、i個目までを選んでという状態を取ってしまうと、個数制限がないのでiを1つ進めるたびにN回のループが発生してしまう
- 重さ制限、残り体力など、通常2つ目に使う状態のみで実は十分。個数制限がない為、i個目まで使ってとか考える必要がないから
- 2次元のまま遷移を高速化するという手法もあり、そっちのほうが実は典型解法かも？？
### 例題
- 基本 [E - Crested Ibis vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_e)

## 経路数問題
- 単純にDPで足し合わせていけば経路数が求める
- 座標が大きい場合、map<Pair,ll> dpというdpテーブルを作れば良い（配列にこだわる必要なし）
- 一つの頂点から複数の頂点に行ける場合（飛車など）、累積和用のDPテーブルを持っておき、それぞれ遷移すれば良い（DP->DP、累積DP->累積DP、DP->累積DP、累積DP->DP）
### 例題
- !復習価値中（実装面） 大きい座標上の経路数 [E - Warp](https://atcoder.jp/contests/abc265/tasks/abc265_e)
- !復習価値高（考察＆実装）　クイーン経路数 [E - Queen on Grid](https://atcoder.jp/contests/abc183/tasks/abc183_e)

## 文字列の部分列
- SがTのある要素を抜き取って並べたものであるとき、SはTの部分列という。連続していなくてもよい。連続している場合は部分文字列という。
- 部分列であるかどうかの判定は、Tのidxを用意し、Sの各文字に対して文字が一致するまでidxを進める（前から貪欲に判定）
- idxが最後まで進んだら一致しなかったという事でアウト。
- なお、部分列が要素番号を無視して等しいものを同じ種類と数えるタイプの問題の場合、貪欲判定法を採用すれば、同じ種類のものをダブルカウントする事はなくなる
### 例題
- !復習価値中 2つの文字列を連結してある文字列を構成できるか [E - Joint Two Strings](https://atcoder.jp/contests/abc324/tasks/abc324_e)
- !要復習 文字列に文字をK回挿入 [F - Strivore](https://atcoder.jp/contests/abc171/tasks/abc171_f)
- !要復習 部分列DP [F - Substrings](https://atcoder.jp/contests/abc214/tasks/abc214_f)

## LCS（Longest Common Subsequence）
- 文字列SとTのそれぞれの部分列（連続でなくてもよい）で一致する最長の長さをLCSという
- Sのi文字目、Tのj文字目まで見たLCSをdp[i][j]と定義し、更新していけば良い
- chmax(dp[i+1][j], dp[i][j]), chmax(dp[i][j+1], dp[i][j])であり、S[i]==T[j]のときのみchmax(dp[i+1][j+1], dp[i][j]+1)する（dpテーブルのiは1-indexed！）
- LCSっぽいDPを書く場合、i,jをカーソルと考えて1つずつ進める遷移を考えてみると良い
- LCSの場合、i,jまでの文字は処理済み（つまり共通文字として採用or不採用で棄却）と考えると、過去のi,jまでの文字がどうであったかはどうでも良い事が分かると思う（そもそも状態としてi,jしか持っていないので、過去の文字は不必要な情報という事）
- i+1,jやi,j+1への遷移は文字不採用、i+1,j+1への遷移は文字採用という事。なおi+1,j+1への遷移でも不採用で遷移しても良いが、処理としてあまり意味がない（chmax(dp[i+1][j+1],dp[i][j]はあってもなくても結果には影響しないから）
- dpテーブルは全て0で初期化すれば良い
- SとTでテーブルを書くと遷移がわかりやすい
- 復元するには、dp[i][j]==dp[i-1][j]ならi--、dp[i][j]==dp[i][j-1]ならj--、両方偽なら文字S[i-1]を選択してi--,j--すれば良い
### 例題
- !復習価値中 LCSの復元 [F - LCS](https://atcoder.jp/contests/dp/tasks/dp_f)
- !要復習 LCSではないが似たようなDP（LCS DPの本質が分かって良い） [E - Sequence Matching](https://atcoder.jp/contests/abc185/tasks/abc185_e)
- !要復習 LCSそのものではないが応用問題 [E - Common Subsequence](https://atcoder.jp/contests/abc130/tasks/abc130_e)  （解説は動画より[けんちょん氏のページ](https://drken1215.hatenablog.com/entry/2019/06/21/230200)推奨）

## 区間DP
- 列の中で隣り合うものを順に処理していく問題に活用可能で、計算量はO(N^3)（ケーキの切り分けのように、遷移がO(1)の場合はO(N^2)）
- dp[l][r]で[l,r)での目的となる値を格納（半開区間である事に注意）
- widthを2～Nまで動かして、r=l+widthとする。lは0からN-widthまで動かす。repの終端条件が1ずれないように注意（1足さないと等号成立しない）！
- 遷移させるとき、単にdp[l][k]とdp[k][r]と必ず分割できるのか、A[l]とA[r-1]がくっつくパターンもあり分割できない場合もあるのか、よく考える事（Daruma Otoshiが分割できない良い例）
### 例題
- 基本 [Matrix Chain Multiplication](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=ja)
- !復習価値中 [N - Slimes](https://atcoder.jp/contests/dp/tasks/dp_n)
- !復習価値中 [B - ケーキの切り分け２ (Cake 2)](https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_b)
- !要復習 区間DPについて考えさせられる良問 [Daruma Otoshi](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp)
- !要復習 ペア選び（高難度） [F - Make Pair](https://atcoder.jp/contests/abc217/tasks/abc217_f)

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
- !復習価値中 基本 ペアマッチングの総数 [O - Matching](https://atcoder.jp/contests/dp/tasks/dp_o)
- !復習価値中 巡回セールスマン問題 [E - Booster](https://atcoder.jp/contests/abc274/tasks/abc274_e)
- !復習価値高 bitDPの練習N増しに [F - Shiritori](https://atcoder.jp/contests/abc278/tasks/abc278_f)
- !要復習 実装面で勉強になる [E - Magical Ornament](https://atcoder.jp/contests/abc190/tasks/abc190_e)
- !復習価値中 bit DPである事を見抜くのが難しい [D - ぬいぐるみの整理 (Plush Toys)](https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d)
- !要復習 bit DPである事を見抜くのが難しい2 [E - Permutation](https://atcoder.jp/contests/abc199/tasks/abc199_e)
- !要復習 並び替え [F - Simple Operations on Sequence](https://atcoder.jp/contests/abc232/tasks/abc232_f)
- !要復習 ネガティブTSP [F - Negative Traveling Salesman](https://atcoder.jp/contests/abc338/tasks/abc338_f)

## 桁DP（Digit DP）
- 上位桁から見て、上限をなめているかなめていないかの2通りでDPしていく
- 上限->上限、上限->not上限、not上限->not上限の3通りの遷移がある
- 上限からの遷移が複雑なので注意
- 遷移が複雑なので、i桁目で0-9のどれを選ぶかのループ(rep(d, 10))を回し、その中でp[i][j][k] -> dp[ni][nj][nk]の遷移（すなわちni,nj,nk）がどうなるかのループを回した方が考えやすい
- 引き算の筆算のように、下位桁から考えるDPもある。問題設定によるが、繰り下がりの有無で状態を持つ
### 例題
- !復習価値中 基本 [S - Digit Sum](https://atcoder.jp/contests/dp/tasks/dp_s)
- !復習価値中 基本 [E - Almost Everywhere Zero](https://atcoder.jp/contests/abc154/tasks/abc154_e)
- !要復習 XOR（ちゃんと考えないとハマる） [D - XXOR](https://atcoder.jp/contests/abc117/tasks/abc117_d)
- !要復習 XOR2 [E - Sum Equals Xor](https://atcoder.jp/contests/abc129/tasks/abc129_e)
- !復習価値中 おつり（桁DPの亜種） [E - Payment](https://atcoder.jp/contests/abc155/tasks/abc155_e)
- !復習価値中 おつり2（上の問題＋一工夫） [E - Minimal payments](https://atcoder.jp/contests/abc231/tasks/abc231_e)
- !復習価値中 回文 [E - (∀x∀)](https://atcoder.jp/contests/abc242/tasks/abc242_e)

## 木DP
- DFSをしながら部分木に対する処理を実行していく
- dp[v][k]=頂点vを根とする部分木で状態kの時の場合の数などとすれば良い
- 潜った直後に処理すれば、部分木に対する処理は終わっているはず
### 例題
- !復習価値低 基本 [P - Independent Set](https://atcoder.jp/contests/dp/tasks/dp_p)
- !要復習 典型90からの出題だが難しい [073 - We Need Both a and b（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_bu) [かつっぱ氏の解説](https://www.youtube.com/watch?v=woK8jwuc3z0)と[こちらの解説](https://takeg.hatenadiary.jp/entry/2021/12/03/113718)を合わせて見れば理解可能。どちらの考え方も身に着けておきたい

## 全方位木DP（難しい全方位は青コーダーになるには不要と思われる）
- まず木DPで下向き部分木の求めたい値を求める
- 再度DFS(BFS)する際に、潜り先の値を引いた物を渡してやる事で、逆向きの求めたい値を渡せる
- 親からの逆向きの値を貰ってしまえば、全辺の合計値が求まる
- 実装は難し目なのでライブラリ使用を推奨
### 例題
- !要復習 距離総和を全頂点について求める（チャレンジ問題） [F - Distance Sums 2](https://atcoder.jp/contests/abc220/tasks/abc220_f)

## DP経路復元
- 逆順にたどれば良いだけなのでよく考えればできるはず
- ただし、i=0以外ににも始点がある場合、遡るのを途中でやめなければならない
- 2経路の復元の場合は、常に異なる戦略を取って逆順に辿れば良い
- 複数経路復元は非常に難しい（D - Happy Birthday! 2のsnuke氏解説動画参照）
### 例題
- !要復習 想定解はDPではないが、経路復元で解ける（その場合のdiffは跳ね上がる。snuke氏も苦労） [D - Happy Birthday! 2](https://atcoder.jp/contests/abc200/tasks/abc200_d)

## 対戦ゲームDP
- 二人が最適戦略を取るという事は、後ろから考えていくと良い
- dp[自分or相手][状態] = 自分の得点とすると、自分の最適戦略はmax、相手の最適戦略はmin
- DP全般に言える事だが、いかにして状態数を減らせるかが大事（例: D - ABS）。計算量が間に合わないときは、無駄な状態はないかよく考える事
### 例題
- 基本 [K - Stones](https://atcoder.jp/contests/dp/tasks/dp_k)
- 基本 [L - Deque](https://atcoder.jp/contests/dp/tasks/dp_l)
- 基本 [D - Stones](https://atcoder.jp/contests/abc270/tasks/abc270_d)
- 基本（なぜ青diff？） [E - Lucky 7 Battle](https://atcoder.jp/contests/abc195/tasks/abc195_e)
- !要復習 カードめくり [D - ABS](https://atcoder.jp/contests/abc078/tasks/arc085_b)

## 円環系DP
- 円環問題は最初の選択を固定する事で問題が簡易化する場合あり（不確定要素がなくなるので考えやすくなる）
- 最後の決め方に最初の決め方が依存してしまう場合、最初の選び方を追加次元（dp[最初の選択][現在の選択]）で管理しておき、最初と最後の選択で辻褄が合わない遷移を捨てればよい
- この場合、dpの初期値を埋めるのが若干手間（i=0のときのdpとi>=1の遷移を分けて書く必要あり。最初だけ特別だから）
- 更に綺麗な実装とするには、dp[最後の選択（予言）][現在の選択]とし、最後の選択が一致したものだけ採用するという方法もある（snuke解説、なお、予言は添え字にせず、予言分だけ新たにdpを実施した方が分かりやすい）
- 予言は実際にdpの値に最後の選択値を代入するものではないが、それをベースにdpを遷移させていく（このあたりの概念は分かりにくいので[snuke氏解説動画](https://www.youtube.com/live/lBhn0wg-IS4?feature=shared&t=2853)を参照
- 円環のどこかに必ず固定できる点があるのであれば、それを1番目かつN+1番目の要素とする事で、円環を固定できる場合あり
### 例題
- !復習価値低 同じ数字が隣り合ったらアウト [E - Distinct Adjacent](https://atcoder.jp/contests/abc307/tasks/abc307_e)
- !要復習 隣り合う頂点を選択して全被覆 [E - Takahashi and Animals](https://atcoder.jp/contests/abc251/tasks/abc251_e)
- !要復習 生産性最大化の為の平日休日割当 [E - Work or Rest](https://atcoder.jp/contests/abc285/tasks/abc285_e)
- !要復習 2部グラフ作成 [F - Make Bipartite](https://atcoder.jp/contests/abc229/tasks/abc229_f)

## LIS 最長増加部分列
- 単調増加する最長の部分列を特定する手法
- 最初にINFで初期化したベクターを準備
- 要素を順番に検査し、自分より大きい数を見つけたら書き換えていくだけで実装可能（実装上は二分探索で挿入位置を見つける）
- 狭義単調増加ならlower_bound、広義単調増加ならupper_boundを使う事に注意！（良く考えないと逆と思ってしまうので注意！）
### 例題
- !復習価値低 LIS+木の実装 [F - LIS on tree](https://atcoder.jp/contests/abc165/tasks/abc165_f)
- !復習価値高 LIS+ひねり [060 - Chimera（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_bh)

## DP高速化
- 遷移するときのループ分をO(1)で実施する
- 累積和やセグメント木が使える
- あるいは状態量を減らす事で高速化できる事もある（DP値がboolなら状態量を1つ減らせるはず）
- 平方分割を組み合わせて遷移を減らすこともある
### 例題
- !復習価値中 基本 [E - Distance Sequence](https://atcoder.jp/contests/abc253/tasks/abc253_e)
- !復習価値高 飴の配り方 [M - Candies](https://atcoder.jp/contests/dp/tasks/dp_m)
- !復習価値高 料理価値最大化 [037 - Don't Leave the Spice（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_ak)
- !復習価値中 花の高さと美しさ [Q - Flowers](https://atcoder.jp/contests/dp/tasks/dp_q)
- !復習価値高 サイコロゲーム [F - Black Jack](https://atcoder.jp/contests/abc342/tasks/abc342_f)
- !要復習（解説見ても難しく解いていない。余裕があれば挑戦しても良いかも） [E - RLE](https://atcoder.jp/contests/abc249/tasks/abc249_e)
- !要復習 区間センター最適配置問題 [F - Sensor Optimization Dilemma](https://atcoder.jp/contests/abc325/tasks/abc325_f)
- !要復習 ホッピングすごろく [F - Hop Sugoroku](https://atcoder.jp/contests/abc335/tasks/abc335_f)

## 状態を工夫するDP
- 状態を工夫する事でDPに落とし込める問題
- 問題ごとに考察が必要
### 例題
- !復習価値中 計算量改善の考察1つ [D - Leaping Tak](https://atcoder.jp/contests/abc179/tasks/abc179_d)
- !要復習 [E - Chain Contestant](https://atcoder.jp/contests/abc215/tasks/abc215_e)
- !復習価値中 輪ゴムで釘を囲む [D - 釘 (Nails) ](https://atcoder.jp/contests/joi2012ho/tasks/joi2012ho4)
- !要復習 稼ぎ＋最短経路（高難度） [F - Earn to Advance](https://atcoder.jp/contests/abc344/tasks/abc344_f)

## DP in DP
- DPの結果をDPの状態として持つようなDPがある
- 例えば部分和の結果を状態として持つ（部分和の結果が10までで良いなら2^10でOK）
### 例題
- !要復習 [F - Make 10 Again](https://atcoder.jp/contests/abc310/tasks/abc310_f)

## 戻すDP
- 可換な操作であればDPテーブルを戻すことが可能
- 部分和問題は可換（形式的べき級数FPSで考えれば明らか）
### 例題
- !要復習 [F - #(subset sum = K) with Add and Erase](https://atcoder.jp/contests/abc321/tasks/abc321_f)

# 最短経路問題

## 01-BFS
- 辺のコストが0か1しかない最短経路問題に使用可能
- ダイクストラ法の単純な場合と言っても良い（最小コスト頂点が自明な為。logが無いので計算も速い）
- 0コスト辺の場合、接続先頂点をqueのfrontに、1コスト辺の場合、接続先頂点をqueのbackにpushする事で実装可能
- 単純BFSのようにdist[nv]!=INFでcontinueしてしまうと上手く動作しないので注意！ダイクストラのように、距離が更新できる時のみ更新するとしないといけない（BFSは書き込まれる距離が昇順だが、01-BFSの場合は書き込まれる距離が2種類ある為）
### 例題
- 基本 [043 - Maze Challenge with Lack of Sleep（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_aq)
- !復習価値低 基本 [E- Bishop 2](https://atcoder.jp/contests/abc246/tasks/abc246_e)
- !復習価値低 基本 [D - Wizard in Maze](https://atcoder.jp/contests/abc176/tasks/abc176_d)
- !復習価値中 壁破壊 [https://atcoder.jp/contests/abc213/tasks/abc213_e](https://atcoder.jp/contests/abc213/tasks/abc213_e)

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
- !復習価値低 典型+α（snuke氏解説の実装がスマート） [E - Come Back Quickly](https://atcoder.jp/contests/abc191/tasks/abc191_e)
- !復習価値低 典型+α [E - Train](https://atcoder.jp/contests/abc192/tasks/abc192_e)
- !復習価値高 終電 [E - Last Train](https://atcoder.jp/contests/abc342/tasks/abc342_e)

## 拡張ダイクストラ法（or 拡張BFS）
- 頂点に状態を持たせる事で拡張する手法。頂点と状態をqueに入れる
- 例えば、辺に距離だけでなく金銭が必要な場合、所持金を状態としてキューに入れると良い
### 例題
- 基本 [E - Swap Place](https://atcoder.jp/contests/abc289/tasks/abc289_e)
- !復習価値高 [E - Two Currencies](https://atcoder.jp/contests/abc164/tasks/abc164_e)
- !要復習 [F - Shortest Good Path](https://atcoder.jp/contests/abc244/tasks/abc244_f)

## ダイクストラ＋ポテンシャル法
- ダイクストラは負辺があると使えないが、各頂点にポテンシャルを設定できれば全辺を非負に変換でき、ダイクストラが使えるようになる
- ポテンシャルは重力ポテンシャルのようなもので、経路によらず保存されるような値
- 問題設定上明らかな場合以外は、ベルマンフォードなどでポテンシャルを求める必要あり。この場合の計算量はO(NM)なので、全頂点にダイクストラを用いてもO(NMlogM)となり、後述のワーシャルフロイドより改善する（辺の数が少なければ）
### 例題
- ダイクストラ関係ないがポテンシャルを理解する良問 [F - Pay or Receive](https://atcoder.jp/contests/abc280/tasks/abc280_f)
- !要復習 [E - Skiing](https://atcoder.jp/contests/abc237/tasks/abc237_e)

## ワーシャルフロイド法（Warshall-Floyd）
- 全頂点から全頂点への最短経路を求める方法。計算量はO(N^3)
- 3重ループにより、経由値との比較をして順次行列を更新する
- 経由地が一番外側のループ！！（例えばa->b->c->dが最短路の時、a->dを最初に更新してしまうとこの経路は現れない）
- dist[i][i]=0で初期化しないと壊れるので注意！（chmin(d[i][i], d[i][k]+d[k][i]） の時に壊れる）
- 負辺があっても使えるが、負閉路があると使えない（負辺がある場合、INFの辺を使って更新しない事！！！INF＋マイナスの値がINFより小さいので、更新してはいけないものを更新してしまう）
- 自分自身への最短経路が負になった場合、負閉路ががあると検出できる！
- ワーシャルフロイド後の行列が与えられたとして、不要な辺を除く事を考える事もできる
- まず完全グラフを行列の通り作成、次に全辺に対して、三角不等式が等号成立するような経由頂点が存在する場合はその辺を削除すれば良い
- この時、同じ辺は1度だけ削除するように！（何度も削除しないように）
- 当然だが、三角不等式が不成立の場合はおかしいので、この場合はワーシャルフロイド後の行列として間違っていたということ
### 例題
- 基本問題 [D - バスと避けられない運命](https://atcoder.jp/contests/abc012/tasks/abc012_4)
- !復習価値中 負閉路検出付きの基本問題 [All Pairs Shortest Path](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja)
- !復習価値低 仕組みを理解する教育的良問 [D - Shortest Path Queries 2](https://atcoder.jp/contests/abc208/tasks/abc208_d)
- !要復習 ワーシャルフロイド後行列 [D - Restoring Road Network](https://atcoder.jp/contests/abc074/tasks/arc083_b)

## ベルマンフォード法
- 負閉路があっても使える最短経路を求めるアルゴリズムで、計算量はO(NM)
- 負辺がある場合、距離INFの頂点からの更新はしない事！！！INF＋マイナスの値がINFより小さいので、更新してはいけないものを更新してしまう
- 全辺に対して、dist[v] > dist[u] + costである限り更新し続ける
- 更新ステップ数がNを超えたら、負閉路があるということ
- 始点と終点に関係ない点をあらかじめ除いておく事で、関係ない負閉路を使うことを避ける事も重要
### 例題
- [E - Coins Respawn](https://atcoder.jp/contests/abc137/tasks/abc137_e)

## 一度に複数辺を進める場合の最短経路
- 所持燃料に限界がある場合、補給なしで到達可能な頂点間を長さ1の辺で結ぶ事により、最小補給回数を求めることができる（正しくは最小補給回数+1が求まる）
### 例題
- !復習価値低 燃料補給回数 [E - Travel by Car](https://atcoder.jp/contests/abc143/tasks/abc143_e)  （参考：[距離1/Kで燃料補給は切り上げ方式の別解](https://atcoder.jp/contests/abc143/submissions/50298596)だが、計算量改善、ダイクストラO(N^2)方式の優先順位、最終的な答えの求め方（切上？切捨？）が難しすぎるので非推奨。こんな解き方もできるよ程度）
- !復習価値高 定額タクシー [E - タクシー (Taxis)](https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_e)

## 最短経路問題+α
- 最短経路の中で最大価値を求める（距離を{経路,-価値}のpair型にしてダイクストラやワーシャル・フロイド）
- 2頂点を同時に動かす最短経路問題は、queueに二つの頂点を入れればOK。
- 最短経路となるパスの場合の数を同時に求める事も可能（pair型にしておいて、{経路長,数}を更新していけば良い）
- 同方向は最大Kまでしか進めないという応用問題の場合、方向の状態に加え、同方向は1/K、方向転換は切り上げというダイクストラをすれば解ける（実装上はK倍した値で管理すると良い）
### 例題
- !復習価値高 最短路かつ最大価値 [E - Souvenir](https://atcoder.jp/contests/abc286/tasks/abc286_e)
- 基本（2頂点を同時に動かす） [E - Swap Places](https://atcoder.jp/contests/abc289/tasks/abc289_e)
- !要復習 2プレーヤー [D - Synchronized Players](https://atcoder.jp/contests/abc339/tasks/abc339_d)
- !要復習 グラフで回文 [F - Construct a Palindrome](https://atcoder.jp/contests/abc197/tasks/abc197_f)
- !復習価値中 最短経路＋その場合の数（巡回セールスマン） [G - Revenge of Traveling Salesman Problem](https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g)
- !要復習 [F - Pond Skater](https://atcoder.jp/contests/abc170/tasks/abc170_f)

## 最小全域木（MST: Minimum Spanning Tree）
- 全域木の中で辺の和が最小のものをいう
- クラスカル法により小さい順に連結頂点同士をつながないように辺を追加していく
- 連結頂点の判定はUnion-Find木を用いる
- Edgeという構造体を定義し、辺の長さで小さい順に並べる。この時、bool operaterで演算を定義しておく
### 例題
- 基本 [Minimum Spanning Tree](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja)
- !復習価値低 典型+α [D - Built?](https://atcoder.jp/contests/abc065/tasks/arc076_b)
- 追加辺はMSTに使われるか？ [E - MST + 1](https://atcoder.jp/contests/abc235/tasks/abc235_e)

## 仮想頂点（超頂点）を設ける
- 仮想頂点を設ける事で、見通しが良くなる場合あり
### 例題
- !要復習 テレポーター最短経路 [F - Teleporter Setting](https://atcoder.jp/contests/abc257/tasks/abc257_f)
- !要復習 手段が複数ある最小全域木 [F - Transportation](https://atcoder.jp/contests/abc270/tasks/abc270_f)
- !要復習 [F - Merge Set](https://atcoder.jp/contests/abc302/tasks/abc302_f)

## 全域木
- 無向グラフから全域木を構成すると見通しが良くなる事がある
- 全域木を構成するにはMSTの他、DFS木、BFS木、最短経路木などがある
- DFS木の後退辺（未使用辺）は必ず祖先の関係になる
- BFS木の未使用辺は必ず祖先の関係にならない
### 例題
- [F - Two Spanning Trees](https://atcoder.jp/contests/abc251/tasks/abc251_f)
- [E - Road Reduction](https://atcoder.jp/contests/abc252/tasks/abc252_e)
- [F - Many Lamps](https://atcoder.jp/contests/abc345/tasks/abc345_f)

# IMOS法
- 重なり領域の累積はいもす法を用いて解決
- IMOS法は配列数が多すぎるときは座標圧縮とのコンビネーションで解ける問題多し
- 累積ではなく、重なっているかだけの判定で良ければ、引継ぎ型dpで解ける（ある点から何個後ろまで加算すべきかという情報において、何個の部分をmax取りしていけばよい）
- 木の上でもimos法は使える
### 例題
- 基本 [D - Union of Interval](https://atcoder.jp/contests/abc256/tasks/abc256_d)
- 基本 [https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_a](A - 鉄道旅行 (Railroad Trip) )
- !復習価値中 木上の累積和 [E - Through Path](https://atcoder.jp/contests/abc187/tasks/abc187_e)
- !復習価値低t 二次元IMOS [028 - Cluttered Paper（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_ab)

# 括弧列
- 正しい括弧列の条件(1)開きと閉じの数が同じ(2)ある地点で開きの数≧閉じの数
- 括弧列は、開き括弧がある度にスタックを積み、閉じ括弧がある度にスタックを取り出す操作をすれば、対応する括弧の情報を取り出す事ができる
- 括弧列は対応()を一つの頂点としてみると親子関係ができあがるので、根付き木に対応する
- つまりDFS（再帰関数）との相性が良い（＝再帰下降構文解析）
- 閉じ括弧を-1、開き括弧を1として増減させると、大局的な性質が分かる。最下点は閉じれない括弧の数、最下点からの最終到達点までの増加は開いたままの括弧の数となる
### 例題
- 基本 正しい括弧列作成 [002 - Encyclopedia of Parentheses（★3）](https://atcoder.jp/contests/typical90/tasks/typical90_b)
- 基本 非括弧列の部分取り出し [D - Mismatched Parenthesis](https://atcoder.jp/contests/abc307/tasks/abc307_d)
- !復習価値低 基本 括弧と気絶（動画に再帰下降構文解析のおまけ解説あり）[D - Scope](https://atcoder.jp/contests/abc283/tasks/abc283_d)
- !復習価値中 文字列をつなげて括弧列を作れるか [F - Bracket Sequencing](https://atcoder.jp/contests/abc167/tasks/abc167_f)

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
- 発展的な重み付きUnion Findもある
### 例題
- !復習価値低 実装工夫次第 [E - Blackout 2](https://atcoder.jp/contests/abc264/tasks/abc264_e)
- !復習価値中 生徒通学合流 [F - Confluence](https://atcoder.jp/contests/abc183/tasks/abc183_f)
- !要復習 重み付きUnion Find [F - Good Set Query](https://atcoder.jp/contests/abc328/tasks/abc328_f)
- !復習価値低 重み付きUnion Findの練習にどうぞ [D - People on a Line](https://atcoder.jp/contests/abc087/tasks/arc090_b)

## 集合
- Nが大きすぎる場合は、存在する値のみsetやmapで管理し、変更部分だけ操作すれば計算量を抑えられる
### 例題
- !復習価値低 ポーンの動き [E - White Pawn](https://atcoder.jp/contests/abc203/tasks/abc203_e)

## 双方向リスト
- 要素の前後関係だけ保持するリスト
- ランダムアクセスはO(N)だが、指定要素の前後へのアクセス、挿入はO(1)
- 指定要素の削除もO(1)
### 例題
- !要復習 基本 [https://atcoder.jp/contests/abc344/tasks/abc344_f](https://atcoder.jp/contests/abc344/tasks/abc344_e)

## 小さい方からK個の和/max
- 最大ヒープと最小ヒープを用意し、最大ヒープサイズをKに保ち続ければ、Kが固定である限りは和やmaxが求まる
- 要素追加、削除の関数を用意しておくと実装が楽になる
### 例題
- !要復習 置き換えor和の操作を最大K回無視して最大化 [F - Ignore Operations](https://atcoder.jp/contests/abc249/tasks/abc249_f)
もう少し簡単な問題も例題に挙げられると良いのだが・・・

# セグメントツリー（Segment tree）
- atcoder libraryで使える
- 一点更新、区間min・max・和取得などができる（遅延評価セグメントツリー）
- モノイドであればセグ木にのる
- セグメント木をDPに使う問題もある。このときは貰うDPの方が使える
### 例題
- 基本 [E - Mancala 2](https://atcoder.jp/contests/abc340/tasks/abc340_e)
- !復習価値中 オセロ（基本+α） [F - Simplified Reversi](https://atcoder.jp/contests/abc179/tasks/abc179_f)
- !復習価値中 半径D以内に爆弾を繰り返す（基本+α） [F - Silver Fox vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_f)
- !復習価値中 想定解は非セグ木（十字領域総和） [E - Bomber](https://atcoder.jp/contests/abc176/tasks/abc176_e)
- !復習価値高 正しい括弧列判定（区間の持ち方工夫） [F - Parenthesis Checking](https://atcoder.jp/contests/abc223/tasks/abc223_f)
- !要復習 区間[l,r)の2番目に大きい数の個数クエリ [F - Second Largest Query](https://atcoder.jp/contests/abc343/tasks/abc343_f)

## 遅延伝播セグメントツリー（Lazy segment tree）
- セグメント木に加え、区間更新が可能
- 上側更新はO(logN)だが、下側更新は計算量が多いので、更新は最大区間で止めて必要になった時に下側に伝播させる
- 更新（＝作用）を組み合わせられる必要があるので、作用素モノイドが必要
- 作用素モノイドは結合律に加え、合成できる事が必要
- なお、一点取得しか必要ない場合、モノイドの結合（op,e）は適当な関数で良い
### 例題
- !要復習 矩形の中に最大何個のりんご？（ど典型） [F - Apples](https://atcoder.jp/contests/abc327/tasks/abc327_f)
- !要復習 高難度 0/1フリップ＆最大1連続長 [F - Vacation Query](https://atcoder.jp/contests/abc322/tasks/abc322_f)
- !要復習 数列区間操作期待値 [F - Random Update Query](https://atcoder.jp/contests/abc332/tasks/abc332_f)


## 永続データ構造
- push_back()とpop_back()は木構造で書ける
### 例題
- !要復習 [E - Notebook](https://atcoder.jp/contests/abc273/tasks/abc273_e)

## Sparse Table
- 全ての区間を二つの区間の和集合で表せる
- RMQにO(1)で回答可能（ただし構築にはsegtreeよりもメモリ消費が大きい）
### 例題
- !要復習 Sparse Tableの考え方 [F - Union of Two Sets](https://atcoder.jp/contests/abc282/tasks/abc282_f)

# 2変数問題

## 1変数固定
- 1変数を固定して、もう1変数に対する探索を高速化できないか検討すると計算量が改善するケースあり
- Sparseな行列の場合、意味のある部分だけ特別扱いする事で計算量が改善しないか検討すると良い
### 例題
- !要復習 復習価値高 十字領域総和の最大化 [F - Rook Score](https://atcoder.jp/contests/abc298/tasks/abc298_f)

## 平面走査
- (x,y)が順に与えられた場合に、"x1<x2 && y1<y2"となる点が存在するかを判定したい時などに使える
- 1次元の大小判定はソートすれば可能だが2次元だと難しい場合に使えるテクニック
- xの小さい順に走査し、存在するか判定。存在しなければyの値をためていく
- こうすることで、xについての大小判定を気にする必要がなくなる
- xに等しい値が存在する場合の実装に注意（同時に処理するならmap<int,vi>的な実装が必要）
### 例題
- !復習価値低 基本 [C - 2D Plane 2N Points](https://atcoder.jp/contests/abc091/tasks/arc092_a)
- !復習価値中 基本 [F - Jealous Two](https://atcoder.jp/contests/abc231/tasks/abc231_f)
- !要復習 平面走査に辿り着くまでが難しいが良問 [F - Range Set Query](https://atcoder.jp/contests/abc174/tasks/abc174_f)
- !要復習 xy min距離の最大値 [F - Dist Max 2](https://atcoder.jp/contests/abc215/tasks/abc215_f)

## 変数分離
- ΣiΣjf(i, j)のようにi,jのループだと計算が間に合わない場合、もしf(i,j) = g(i)h(j)とできればΣig(i)Σjh(j)と分離でき計算量を抑えられる
- min{f(i,j)}を求める問題でf(i,j)=g(i)+h(j)なら、min(g(i)+h(j))=min(g(i))+min(h(j))と選択肢を分離できる
### 例題
- !要復習 路線構築の最小コスト [D - National Railway](https://atcoder.jp/contests/abc210/tasks/abc210_d)

# 包除原理
- AでもBでもない場合の数はU-A-B+A∩Bで求まる
- 一般には集合の個数がM個あるとすると、積集合の全組み合わせ2^M通りについて、（符号）積集合[i]の場合の数の総和を求めればよい。符号は積集合のベース集合が奇数ならマイナス、偶数ならプラス（積集合が空集合の場合は全体集合となる）
- rep(i, 1LL<<M)で回せば全組み合わせ列挙できる
- Mが大きいと2^M通りのループは回せないが、完全順列の問題のように場合の数をまとめて数え上げられる場合は使えるケースあり
- 重複組合せで各変数がai≦xi≦biのとき、まず全体からΣaiを引きxi'=xi-aiとすれば全変数0以上と見なせる
- 次に各変数にci=bi-aiの上限がなければ単純な重複組合せ問題だが、包除原理によりj個の変数がci超えとなる場合の数を足したり引いたりすればOK
### 例題
- 基本 [F - typewriter](https://atcoder.jp/contests/abc246/tasks/abc246_f)
- !復習価値中 木の辺の塗り方 [F - Tree and Constraints](https://atcoder.jp/contests/abc152/tasks/abc152_f)
- !要復習 完全（攪乱）順列の亜種 [E - NEQ](https://atcoder.jp/contests/abc172/tasks/abc172_e)
- !復習価値高 重複組合せの包除原理（実装力も鍛えられる） [E - Patisserie ABC 2](https://atcoder.jp/contests/abc200/tasks/abc200_e)
- !要復習 [F - Minimum Bounding Box 2](https://atcoder.jp/contests/abc297/tasks/abc297_f)
- !要復習 最大公倍数=Mとなる場合の数 [F - Subsequence LCM](https://atcoder.jp/contests/abc349/tasks/abc349_f)

# 行列

## 行列累乗
- 行列累乗でも繰り返し2乗法が使える
- 隣接行列（辺のコストは全て1）をK乗すると、要素(i,j)はiからjへ長さKで辿り着けるパスの個数となる
- こうなる理由はEDPC R - Walkの解説参照
- Nが50以下（本当？100ぐらいでも大丈夫な気がするが…）、Kがかなり大きい（10^9～10^18）の場合、行列累乗が使える可能性あり
### 例題
- !復習価値高 [R - Walk](https://atcoder.jp/contests/dp/tasks/dp_r)

## 掃き出し方
- 基底を次々に追加する実装が分かりやすい
### 例題
- !要復習 最小スパイスコスト [F - Spices](https://atcoder.jp/contests/abc236/tasks/abc236_f)

# その他典型
## ヒストグラム最大長方形（スパン）
- ヒストグラムの中で取りうる長方形の最大面積をO(N)で求める問題
- まずは各要素に対して、その要素よりも初めて小さくなる左右の範囲（スパン）を求める
- 左から順番に{高さ,要素番号}のpairをスタックに積んでいくが、自分より高さの高いスタックは二度と使われることがないので捨ててよい。これで左スパンが求まる
- 右スパンも同様に求まるので、最大面積も求まる
### 例題
- !復習価値中 基本（O(N^2)でも解けるが…） [C - Mandarin Orange](https://atcoder.jp/contests/abc189/tasks/abc189_c)

## 計算量がlog(N)やsqrt(N)に落ちる問題
- ΣN/iはNlog(N)なので、二重ループに見えて実は計算がかなり早い問題がある
- 各数の2倍、3倍、4倍、、、を考慮しなければいけない場合、こうなる事が多い
### 例題
- !復習価値中 "GCD of 全数列"の総和 [E - Sum of gcd of Tuples (Hard)](https://atcoder.jp/contests/abc162/tasks/abc162_e)
- !要復習 floor(N/i)の総和 [E - Fraction Floor Sum](https://atcoder.jp/contests/abc230/tasks/abc230_e)

## マージテク
- 箱に入ったボールを次々に移し替えていく場合、少ない方を大きい方に移すことで、各ボールの移し替えられる回数は高々logN回に抑えられる（データ構造をマージする一般的なテク）
- 二分木を下（葉）から足していく際、総和=Σ頂点のコスト*高さとなるので、葉が決まっている際に最小和を求めるためには、小さい順にマージしていけばよい
### 例題
- !復習価値低 一般的なマージテク基本 [F - Colored Ball](https://atcoder.jp/contests/abc329/tasks/abc329_f)
- !要復習 [F - Bread](https://atcoder.jp/contests/abc252/tasks/abc252_f)

## 標準形を考える
- 直線の傾きは{x, y}（xとyは互いに素、x>=0）で一意に定められる（ただし{0,-1}と{0,1}を分けてしまわないように注意）
### 例題
- !要復習 内積ペアを選ばない総数（難しいが良問） [E - ∙ (Bullet)](https://atcoder.jp/contests/abc168/tasks/abc168_e)

## 差分を考える
- O(NK)では解けないが、O(K)では解ける場合、kを固定してO(1)で求められれば全体でO(K)となる
- この時、kを固定してもO(1)で求められないが、kが求まっていればk+1の答えが差分から求められるのであればO(1)になる
### 例題
- !復習価値中 寿司おいしさ+種類数ボーナス最大化 [D - Various Sushi](https://atcoder.jp/contests/abc116/tasks/abc116_d)
- !要復習 [F - Distance Sums 2](https://atcoder.jp/contests/abc220/tasks/abc220_f)
- !要復習 カードの期待値 [F - Double Chance](https://atcoder.jp/contests/abc276/tasks/abc276_f)

## 偶奇に注目
- 隣り合う要素を反転できる場合、実は任意の2要素を反転できる事と等しい
- 更に、反転しても要素数（例えば黒の数）の偶奇は変わらない。
- 同様に隣り合う要素をswapできる場合、任意の2要素を反転できる事と等しい（バブルソートの仕組みに通じる）
### 例題
- !復習価値低 隣り合う要素の符号を反転 [D - Flipping Signs](https://atcoder.jp/contests/abc125/tasks/abc125_d)
- !要復習 グラフの2彩色場合の数 [E - Red and Blue Graph](https://atcoder.jp/contests/abc262/tasks/abc262_e)

## MODで考えてみる
- 求めたい物に割り算が関係する場合、MODで考えてみると見通しが良くなる場合あり。特にDPする際には、MODであれば状態数が減らせる
### 例題
- !要復習 薬の最適調合 [F - Potion](https://atcoder.jp/contests/abc192/tasks/abc192_f)

## 円環問題
- 円環はそのままでは扱いにくいので、(1)2つ繋げて列にするか、(2)頂点1から頂点1までの区間長Nの列にするか、(3)頂点1から頂点Nまでの区間長N-1の列にするかで考えると見通しが良くなる
### 例題
- !要復習（本番で解けなかった） 最適な橋の切断 [D - Island Tour](https://atcoder.jp/contests/abc338/tasks/abc338_d)
- !要復習（本番で解けなかった） 弦が交差するか [E - Chords](https://atcoder.jp/contests/abc338/tasks/abc338_e)

## 不変量を見つける
- 不変量に着目すると解ける問題あり
### 例題
- !復習価値高 順次桁減らし [D - Digit Sum Replace](https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d)
- !要復習 RAQ [D - Range Add Query](https://atcoder.jp/contests/abc288/tasks/abc288_d)

## マンハッタン距離
- 45度回転（して√2倍拡大）した座標系を(a,b)とすると、max(|ai-aj|, |bi-bj|)がマンハッタン距離となる
- maxは結合法則を満たすので、マンハッタン距離の最大値であれば、軸ごとに独立に考えられる
### 例題
- 基本 マンハッタン距離 [E - Dist Max](https://atcoder.jp/contests/abc178/tasks/abc178_e)
- !復習価値低 マンハッタン距離 [036 - Max Manhattan Distance（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_aj)

## パスカルの三角形
- 各行の総和は2^行番号となる
- ある斜め列のすぐ下側の斜め列は累積和の行列となっている
### 例題
- !復習価値高 グリッド経路数の総和 [F - Many Many Paths](https://atcoder.jp/contests/abc154/tasks/abc154_f)

## 左右から攻める
- ある要素について何かを調べたいとき、左からの情報と右からの情報を前処理として持っておくと、その要素の影響が調べられることがある
### 例題
- !要復習 必ず働く日列挙 [E - Yutori](https://atcoder.jp/contests/abc161/tasks/abc161_e)

## クエリ先読み
- クエリを先読みすると楽に処理できる事がある
### 例題
- 基本 [D - Decayed Bridges](https://atcoder.jp/contests/abc120/tasks/abc120_d)
- !復習価値高 隣接要素の和が与えられる [068 - Paired Information（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_bp)
- !復習価値高 [D - Gomamayo Sequence](https://atcoder.jp/contests/abc346/tasks/abc346_d)

## XY独立に考える
### 例題
- 基本 [070 - Plant Planning（★4）](https://atcoder.jp/contests/typical90/tasks/typical90_br)
- !復習価値高 格子点を正方形に収める最小回数 [F - Minimize Bounding Square](https://atcoder.jp/contests/abc330/tasks/abc330_f)

## bitごとに独立に考える
### 例題
- !復習価値中 [086 - Snuke's Favorite Arrays（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_ch)

## 操作列を考える
- 各操作に名前を付け、その操作列を考えると、無駄な連続部分操作列が見つかり、意味のある操作列を考察できる事がある
### 例題
- !要復習 [F - +1-1x2](https://atcoder.jp/contests/abc188/tasks/abc188_f)

## アフィン変換（同次行列）
- x, yが1次を保ったまま変換される場合は、アフィン変換可能
- アフィン行列を構造体として定義し、アフィン行列同士の積を定義すれば実装が楽になる
### 例題
- !復習価値高 [E - Rotate and Flip](https://atcoder.jp/contests/abc189/tasks/abc189_e)

## 関数の形のまま考える
- 合成関数の問題は、f(x)のxに対する処理ではなく、f(x)のグラフ全体（つまり全xに対するf(x)の値）のまま考えると見通しが良くなるケースあり
### 例題
- 写像min or max or +を合成 [E - Filters](https://atcoder.jp/contests/abc196/tasks/abc196_e)

## 組合せ数減らし（主客転倒）
- 全組合せを列挙するとTLEする場合、演算（maxやΣなど）の順番を入れ替える事で探索量が減るケースあり
- 例えば、N個からM個選んだ総和の絶対値のmaxを調べたいとき、先にM個選ぼうとすると組合せが膨大でTLEする。max(abs(x))はmax(x, -x)なので、そのままの総和と-を付けた総和のmax取りをすればよい。そのままの総和でも-を付けた総和でも、M個の選び方は自明（貪欲）
- 複数のΣがある問題は、Σを入れ替えることで計算量を抑えられることがある
### 例題
- !要復習 お菓子の選び方 [D - Patisserie ABC](https://atcoder.jp/contests/abc100/tasks/abc100_d)
- !要復習 駒置きコストの総和（難しいが良問） [E - Cell Distance](https://atcoder.jp/contests/abc127/tasks/abc127_e)
- !復習価値高 転倒数の期待値 [066 - Various Arrays（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_bn)
- !要復習 全演算方法の総和 [F - Problem where +s Separate Digits](https://atcoder.jp/contests/abc224/tasks/abc224_f)
- !要復習 全連続部分列についての回文コストの和 [E - Make it Palindrome](https://atcoder.jp/contests/abc290/tasks/abc290_e)

## 構築系問題
- 構築させる問題
### 例題
- !復習価値低 [D - At Most 3 (Contestant ver.)](https://atcoder.jp/contests/abc251/tasks/abc251_d)
- !復習価値中 [F - Three Variables Game](https://atcoder.jp/contests/abc166/tasks/abc166_f)

## ホール（Hall）の結婚定理
- 完全マッチングできる必要十分条件に関する定理（参考：[グラフ理論⑥(ホールの結婚定理)](https://www.youtube.com/watch?v=-W7QTRk0Yic)）
- 女性の任意の部分集合に対し、結婚先が女性の人数以上あれば完全マッチング可能
- 必要性は鳩ノ巣原理から、十分性は帰納法で証明可能（証明はややこしいので覚える必要なし）
### 例題
- !要復習 数列マッチング（実装難） [F - Contrast](https://atcoder.jp/contests/abc178/tasks/abc178_f)

## まとめて処理する
- 日数が多い場合、変化のある日（イベント）にだけ着目してまとめて処理する事で計算量を抑えられる
- イベントで処理する場合、時刻が同時のイベントが複数あっても基本はバグらない（時刻差分が0になるだけで何も更新されないので） 
### 例題
- !復習価値中 [D - Snuke Prime](https://atcoder.jp/contests/abc188/tasks/abc188_d)

## NIMとgrundy数
- NIMは残り山の石の個数のxorが0なら負け、非0なら勝
- xor=0からはxor!=0にしか遷移できないし、xor!=0なら最上位bitが立つ山を選んで下位bitが全て0になるように取り除けばxor=0に遷移可能
- NIMでは石の数がgrundy数だが、一般には遷移先のMEX（非負非除最小整数）が各山のgrundy数となる
- NIMと同じ議論でxor=0からはxor!=0にしか遷移できないし、xor!=0なら～～
### 例題
- !要復習 L~R取り除けるNIM [G - Constrained Nim 2](https://atcoder.jp/contests/abc297/tasks/abc297_g)

## Zoblist hash
- 集合同士をO(1)で比較可能
- 各要素に乱数を割り当て、全要素のXORを集合のハッシュとする
- メルセンヌツイスターで乱数を発生させると良い
### 例題
- !要復習 [E - Prefix Equality](https://atcoder.jp/contests/abc250/tasks/abc250_e)

## 偶置換・奇置換
- 順列を置換した回数で分類（順列である必要はないが重複要素があっては駄目）
- サイクル個数の偶奇と置換の偶奇は一対一対応する（N=偶数なら一致、N=奇数なら逆）
- 重複要素のある数列は偶置換でも奇置換でもあると見なせる
### 例題
- !要復習 スワップだけで一致するか [F - Simultaneous Swap](https://atcoder.jp/contests/abc296/tasks/abc296_f)

## 読解が難しい問題
### 例題
- 添え字が多い問題 [B - Longest Uncommon Prefix](https://atcoder.jp/contests/abc285/tasks/abc285_b)

# 実装が重い問題
### 例題
- !復習価値低 シート重ね合わせ（実装工夫すればすっきり書ける） [C - Ideal Sheet](https://atcoder.jp/contests/abc307/tasks/abc307_c)
- !復習価値低 タイル置き（実装工夫すればそんなに大変ではない） [D - Tiling](https://atcoder.jp/contests/abc345/tasks/abc345_d)
- !要復習 トーナメント（入力部の実装が大変） [F - A Certain Game](https://atcoder.jp/contests/abc314/tasks/abc314_f)
- !要復習 クッキー消し（丁寧に実装しないと沼る） [D - Magical Cookies](https://atcoder.jp/contests/abc315/tasks/abc315_d)
- !復習価値高 がっかりビンゴ（実装方針によっては沼る） [C - False Hope](https://atcoder.jp/contests/abc319/tasks/abc319_c)
- !復習価値高 ABCパズル（実装方針間違えるとありえないぐらい沼る） [D - ABC Puzzle](https://atcoder.jp/contests/abc326/tasks/abc326_d)

# 青コーダーになるのに必須ではないと思われるアルゴリズム

## 牛ゲー
- 2変数間の制約(xj-xi<=ci)が与えられる時、xN-x0を最大化したいという問題
- 線形計画法のLP双対により、最短経路問題に帰着できる
- 詳しくは理解できていないが、数直線上に牛の絵を描いてみるとその心がなんとなく分かる
### 例題
- [G - 01Sequence](https://atcoder.jp/contests/abc216/tasks/abc216_g)

## DPでTop2を持つ
- 和の最大値を求めるDPにおいて、隣が同じ色になってはNGの場合、最後に選んだ色をDPの状態に持てば良いが、計算量が収まらない場合あり
- この時、実はTop2のみ持てば良い事が分かる
- Top1と同じ色であればTop2をベースに更新すれば良いし、異なる色であればTop1をベースに更新する
- 更新の実装は結構大変なので、2つの関数を持つstruct Top2を定義すると良い
- 関数(1) 色が与えられたとき、異なる色での最大値を返す（i番目におけるpdp[j]からの最大ペアを求める為）
- 関数(2) 新しい（色、値）のペアが来た際、Top2を更新する（入替する）
### 例題
- !要復習 色が隣合わないようにK個選んだ時の価値総和最大値（実装難） [E - Colorful Subsequence](https://atcoder.jp/contests/abc345/tasks/abc345_e)

## ローリングハッシュ（Rolling Hash）
- 素数Pと乱数Xを用意し、ABCDという文字列をA*X+B*X^2+C*X^3+D*X^4(mod P)にハッシュ化する
- ハッシュが一致すれば同一文字列と判定できる
- 文字列が不変ならハッシュの累積和を作っておくことで部分文字列のハッシュを取り出せる
- (hash,x^n)はモノイドなのでセグ木にも乗せられる
- ロリハで最も難しいのは衝突確率。非衝突確率1-1/PなのでQ回のクエリでの衝突確率は約Q/P。事前にしっかり見積もること。特に文字列の種類数をカウントする時などは種類^2回のクエリに耐える必要がある
- 衝突確率を下げる為、mintsを導入すると良い（2つの素数でmodを取った値を保持）
- 衝突確率があるので、ロリハを使わなくても解けるなら使わない方が良い
### 例題
- [F - Palindrome Query](https://atcoder.jp/contests/abc331/tasks/abc331_f)

## ハッシュで一致判定
- ロリハと同じように一致判定はハッシュを使うと効率が良い
- 衝突確率を下げる為、素数を多めに用意すると良い
### 例題
- [F - Product Equality](https://atcoder.jp/contests/abc339/tasks/abc339_f)

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
- 数列各要素を±のどちらかにして総和を求める問題は、dp[i][j]=｛iまで見て総和がjになればtrue｝とするのが定石だが、dp[i]=bitsetとすると、dp[i+1] |= dp[i]<<A[i]、dp[i+1] |= dp[i]>>A[i]でOKなのでいちいちループを回さずに済むので楽（[こちら](https://www.youtube.com/watch?v=tNyPYIhy9Ms)のE問題解説コードが参考になる）
- vectorを大量に定義すると実行時間制限の厳しい問題ではTLEする可能性あり。特に長さの短いvectorだと何回も定義しがちなので注意。長さ固定ならstructを定義する等した方がよい（[TLEする例](https://atcoder.jp/contests/abc343/submissions/52479159)）

## 構造体
- コンストラクタを定義したのに引数を指定しないとエラーが出る。no matching function for call to 'Struct::Struct()'コンストラクタにデフォルト引数を指定しておけば解決する
- 構造体にbool operater < (const Struct &s) {return x < s.x}などとすると、構造体同士の演算が定義できる。
- ただし、priority_queueに使うときは2点注意が必要。(1)bool operator>（greater<MYSTRUCT>なので） (2){}の前にconstと書かないとエラーが出る（理由不明） -> 恐らくだが、greater<MYSTRUCT>と書く場合はconst記述が必要。そうしないと内部で定義してあるoperater>と型が完全一致しないのでエラーが出るのではないか
- お行儀の悪い書き方としては、operator<を逆向き"<"で定義してしまうやり方あり。こうすればpriority_que<MYSTRUCT>と定義するだけでよくなり実装は楽
- 自分定義の構造体をN個のvectorにする場合は、初期値を設定しないとエラーになる
- 構造体定義の直下でvectorのサイズを定義すると理由不明だがエラーが出る。初期値関連はコンストラクタで初期化する必要がある
- しかしながら、プログラム中で大量の構造体が使われる場合、vectorを使ってしまうと宣言時に領域を異常に確保してしまうからか、容易にTLEする。サイズが決まっている場合はint d[N]などと配列で準備する必要があるっぽい。正確には理解できていない（例えばこの問題[F - Palindrome Query](https://atcoder.jp/contests/abc331/tasks/abc331_f)）
- 上記はもしかすると動的に確保する領域が散らばったり衝突したりして、アクセスが遅くなっているのかもしれない。あるいは構造体など関係なく、そもそも大量のvectorを定義してしまうと遅くなってしまうのかもしれない

## set/multiset
- set.lower_bound(x), set.upper_bound(x)が使えるが、範囲外に注意する事
- まずit == set.end()となったら範囲外。後ろに進めるのはit!=st.end()の時、前に進めるのはit!=set.begin()の時、最終的にit!=set.end()である事にも注意したい
### 例題
- [D - Sequence Query](https://atcoder.jp/contests/abc241/tasks/abc241_d)

## TLE(Time Limit Exceeded)
- 要素数Nの初期化はO(N)の計算量が必要なことに注意！（次数が3以下のグラフを距離3までBFSする際、BFSのループ回数は少ないが、visited(N)としてしまうとO(N)かかるので注意）

## RE (Runtime Error)
- 多くはゼロ除算もしくは配列外参照
- 空setに対して演算するとRE
- set.erase(set.end())などとするとRE（なぜならset.erase(--set.end())とする必要があるから）
- 他に経験したREとしては、巨大配列vectorがある　（[](https://atcoder.jp/contests/abc273/submissions/45018373)）

## 実装テクニック（その他）
- ACLのdsu.size(v)はint型なので、そのまま掛け算に使うとオーバーフローして危険
- ACLのmintはdouble型をキャストできないので注意（eg. (mint)(1e8)などとすると壊れる）
- set<ll,greater<ll>>とすると降順setが構築可能
- 区間[l,r)の一方だけに制限値処理をすると危険（たとえばchmax(l,x)などとするとl>rになりうる）。制限値処理は同時にかける（できればclampで）
- 下桁から処理するwhile文（例えばwhile(x>0){x/=10}）は、x==0のコーナーケースに注意！一度も処理されない
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
- tasks.jsonはタスクの自動化であり、コンパイルオプションなどを指定可能
- launch.jsonはデバッグの設定であり、実行ファイルa.outの指定や入力ファイルなどを指定
- 理由は分からないが、rep(i,H)rep(j,W) a[i][j]=b[i][j];をデバッグで1行進もうとすると固まる。次のブレークポイントまで右三角で飛ばすと固まらない（H*W=1e6程度）。デバッグで固まった場合は試してみる価値あり

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
- WINDOWSでMINGWのgccを使う場合、スタックオーバーフローに注意。AtCoderでは1024MBのスタックサイズが許容されているが、`ulimit -a`で調べると手元では2032KBしか確保されていなかった。ulimitでは変更が上手くいかないので、コンパイル時に`-Wl,--stack,1073741824`を指定して解決した（1073741824[Byte] = 1024MB）
- AtCoderではスペースと改行を区別しないとsnuke氏はおっしゃっていたが、少なくともABC109のD問題では行末にスペースを入れたことでWAした・・・。サンプルまでWAになった場合は疑ってみる価値あり

# これまでに解いた問題数
- 以下は最初に解いた問題群。以降は[Atcoder Problemsで管理](https://kenkoooo.com/atcoder/#/table/)ABCの過去問を解いている
- 競プロ典型90問: （★4以下の全問->後ほど★5以下全問on2023/12/28）
- 分野別　初中級者が解くべき過去問精選 100 問: （問1,10,17,18,24-25,28,32,34-38,44-46,48-49,53,56,60,64,66,68,70,82,85,92,94はatcoderでないためスキップ。52,75,84は難しい為スキップ） ->後ほど全問解いたon2024/1/23
- 1問: [N Slimes](https://atcoder.jp/contests/dp/tasks/dp_n) -> 後ほどEDPC Sまで全問

# 上記以外でもう一度解くべき問題（＝ACできなかった問題）

## ACできたがグダった問題
- [C - Slot Strategy](https://atcoder.jp/contests/abc252/tasks/abc252_c)
- [D - Distinct Trio](https://atcoder.jp/contests/abc252/tasks/abc252_d)
- [E - Throwing the Die](https://atcoder.jp/contests/abc266/tasks/abc266_e)
- [C - Chinese Restaurant](https://atcoder.jp/contests/abc268/tasks/abc268_c)
- [E - Last Rook](https://atcoder.jp/contests/abc269/tasks/abc269_e)
- [E - Add and Mex](https://atcoder.jp/contests/abc272/tasks/abc272_e)
- [D - Freefall](https://atcoder.jp/contests/abc279/tasks/abc279_d)
- [C - Cross](https://atcoder.jp/contests/abc300/tasks/abc300_c)
- [D - Bitmask](https://atcoder.jp/contests/abc301/tasks/abc301_d)
- [D - Merge Slimes](https://atcoder.jp/contests/abc323/tasks/abc323_d)
- [E - Joint Two Strings](https://atcoder.jp/contests/abc324/tasks/abc324_e)
- [E - Modulo MST](https://atcoder.jp/contests/abc328/tasks/abc328_e)
- [D - Pyramid](https://atcoder.jp/contests/abc336/tasks/abc336_d)
- [E - Digit Sum Divisible](https://atcoder.jp/contests/abc336/tasks/abc336_e)
- [C - Many Replacement](https://atcoder.jp/contests/abc342/tasks/abc342_c)
- [D - AtCoder Express](https://atcoder.jp/contests/abc076/tasks/abc076_d)

## ACできなかった問題
- [F - Max Sum Counting](https://atcoder.jp/contests/abc216/tasks/abc216_f)
- [E - Rook Path](https://atcoder.jp/contests/abc232/tasks/abc232_e)
- [F - Reordering](https://atcoder.jp/contests/abc234/tasks/abc234_f)
- [F - |LIS| = 3](https://atcoder.jp/contests/abc237/tasks/abc237_f)
- [E - Subtree K-th Max](https://atcoder.jp/contests/abc239/tasks/abc239_e)
- [F - Construct Highway](https://atcoder.jp/contests/abc239/tasks/abc239_f)
- [F - Sum Sum Max](https://atcoder.jp/contests/abc240/tasks/abc240_f)
- [D - ABC Transform](https://atcoder.jp/contests/abc242/tasks/abc242_d)
- [F - Keep Connect](https://atcoder.jp/contests/abc248/tasks/abc248_f)
- [E - Addition and Multiplication 2](https://atcoder.jp/contests/abc257/tasks/abc257_e)
- [F - Find 4-cycle](https://atcoder.jp/contests/abc260/tasks/abc260_f)
- [F - Monochromatic Path](https://atcoder.jp/contests/abc264/tasks/abc264_f)
- [F - Numbered Checker](https://atcoder.jp/contests/abc269/tasks/abc269_f)
- [F - SSttrriinngg in StringString](https://atcoder.jp/contests/abc346/tasks/abc346_f)
- [D - Root M Leaper](https://atcoder.jp/contests/abc272/tasks/abc272_d)
- [C - Counting Squares](https://atcoder.jp/contests/abc275/tasks/abc275_c)
- [F - Erase Subarrays](https://atcoder.jp/contests/abc275/tasks/abc275_f)
- [E - Kth Takoyaki Set](https://atcoder.jp/contests/abc297/tasks/abc297_e)
- [D - AABCC](https://atcoder.jp/contests/abc300/tasks/abc300_d)
- [F - More Holidays](https://atcoder.jp/contests/abc300/tasks/abc300_f)
- [F - Box in Box](https://atcoder.jp/contests/abc309/tasks/abc309_f)
- [E - NAND repeatedly](https://atcoder.jp/contests/abc310/tasks/abc310_e)
- [F - Cans and Openers](https://atcoder.jp/contests/abc312/tasks/abc312_f)
- [D - Odd or Even](https://atcoder.jp/contests/abc313/tasks/abc313_d)
- [F - Shortcuts](https://atcoder.jp/contests/abc315/tasks/abc315_f)
- [F - Push and Carry](https://atcoder.jp/contests/abc323/tasks/abc323_f)
- [E - Maximize Rating](https://atcoder.jp/contests/abc327/tasks/abc327_e)
- [E - 7x7x7](https://atcoder.jp/contests/abc343/tasks/abc343_e)
- [E - Set Add Query](https://atcoder.jp/contests/abc347/tasks/abc347_e)
