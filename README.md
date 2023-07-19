# はじめに
このページでは、競プロでこれまでに学んだ内容（教訓）を端的に箇条書きします。

# 文字列操作
- S.substr(開始位置, 長さ)で部分文字列を取得可能
- regex_match(S, regex("正規表現"))で一致性を確認可能
- ただし正規表現は遅い。計算量がシビアな問題ではなるべく使わない
- S.find(s)は文字列sの含まれる最初の位置を出力。存在しない場合はnposを出力（sは文字でも可）
- charをintに直すには'5'-'0'などとする
- 文字列が連続している場合はランレングス圧縮が有効。余事象との組み合わせで、異なる文字が含まれる区間の場合の数も求められる

# ビット操作
- &や|等のビット演算子は==よりも優先順位が低いことに注意。ビットシフトも含め、ビット操作はとにかく括弧で囲め！
- ビット操作にはビット列bitsetが便利
- 部分集合の判定にbitsetを使用可能。A⊂BならA & B == A
- 決められた位置のみ一括で反転したい場合は、排他的論理和を使うと楽
- XORは繰り上がりなし足し算。その為、交換法則、結合法則が成り立つ
- x + y = (x xor y) + 2 * (x & y)が成り立つ（両方1の桁だけ繰り上がりがあり、他の桁は一致するため）

# 整数
- 約数と素因数分解は似て非なるもの。約数を列挙したいのか、素因数を列挙したいのか、よく考える
- a, b, cが自然数の時、a*b<=c とa<=floor(c/b)は同値（必要十分条件）
- a, b, cが自然数の時、a*b>c とa>floor(c/b)は同値（必要十分条件）

# 1000000007関連問題
- 掛け算や足し算してMODを上回る可能性がある場合はその都度MODで剰余を取る
- ただし、累積和にMODを取ると途中で減ってしまうので注意！区間和を求める際、MODを取るとマイナスになる事があったり、単純に絶対値を付けられなかったりする
- 繰り返し2乗法により、累乗のmodを高速に計算可能（modpowとしてツール化）
- MODの割り算は逆元を求めれば良く、modpow(x, MOD-2, MOD)で求まる。MODが素数で使えるフェルマーの小定理を利用したもの
- ちなみにMODが素数でない場合の逆元は拡張ユークリッドの互除法により求まる

# ユークリッドの互除法
- gcd(a, b) = gcd(b, r) = ... = gcd(b', 0) = b'という古典的アルゴリズム
- 再帰関数で簡潔に書ける
- 拡張ユークリッドの互除法も再帰関数で簡潔に書ける（ax+by=gcd(a,b)のx, y, gcd(a,b)を求める問題）

# 最大公約数と最小公倍数
- 最大公約数は、各素因数の最小指数を選んだもの、最小公倍数は最大指数を選んだものとなる
- (a, b, c)のGCDとLCMはそれぞれ、gcd(gcd(a, b), c)、lcm(lcm(a, b), c)と書ける。理由は素因数分解から明らか
- 素因数の指数部が同じであるかどうかの判定は、LCM/GCDを素因数で割り切れるかどうか調べればよい（例えばLCM/GCDが3で割り切れれば、3の指数部は同じ数。理由は素因数分解から明らか）

# 約数全列挙
- 約数を全列挙するのは、2から順番に割り切れるか確かめ、割り切れたらその数と割られた数を保存していく
- 元の数をMとすると、計算量はO(sqrt(M))
- 複数の数の約数を同時に全列挙するには、bool配列を用意しておき、最初に調べたい数のところを全てtrueにする
- 次に、この配列2の倍数の位置を全て調べ、trueがあったら2は約数という事で2のところをtrueにする
- 続けて3, 4と調べていく。計算量は約数最大値をMとすると、O(M logM)になる（M/2 + M/3 + M/4 + ... + M/M回調べる為）

# 小数
- 小数点を出力する際はcout << fixed << setprecision(10) << x << endl;などとしないと小数点以下の桁が6桁ぐらいまでしか出力されない（printf("%.10f\n", x)の方が簡単）
- 小数点の計算は誤差がある為、厳密な大小判定には使えない。整数型に直せれば厳密な判定が可能。
- 小数を整数に入力したい場合、scnaf("%d.%d", &x)で整数、小数を分離して入力可能

# ソート
- lower_bound関数で、配列中のどこの間に入るかわかる（戻り値がイテレータである事に注意）
- 上手く規格が合わずソートできない場合は、無理やり規格を合わせてごちゃ混ぜソートすると解ける場合あり（e.g. 1分でB点、2分でA点取れる場合、1分でB点取り、更に1分でA-B点取れると考えるなど）

# 座標圧縮
- 簡単に実装するなら、圧縮前の座標をmap[x]=0 (for all x)で用意しておき、int i=0; for (auto [k, _]: map) {map[k] = i++;}でOK
- 以下はmapの定数倍の遅さを解決したい場合の手法（あまり使う事はないかもしれない）
- 重複要素削除はソート後にvec.erase(unique(all(vec)), vec.end())で可能。uniqueは隣接の重複しか削除しないので事前ソート必須。また、uniqueはベクター長を変えないので、eraseで末尾のゴミを削除しておくこと
- 後は求めたい数字が上記ベクターの何番目にあるか調べれば良い。lower_boundを用いる
- IMOS法用に座標圧縮する場合は、-1を入れるための箱を用意する事（例：3~5日の累積を取りたいとき、座標としては3と6とすべきで、5でないことに注意）

# 多重ループ全探索
- ループの数を減らせないか工夫してみる
- 途中までループして後は二分探索などすると、O(N^4)がO(N^2 logN^2)となってACできる場合あり

# 順列全探索
- 制約数が少なければ全探索を考える
- 後述のBFSやDFSも全探索だが、こちらの方が実装が簡単なので、可能なら順列全探索
- nCrの全探索にも応用可能（bitsetのpattern.count()==rだけ実行する）。この時、trueビット以外の項目をスルーして良いかどうか要確認！（NからK個を選らんでビルが全部見える高さを考える場合、N-K個の選ばれていないビルの高さに影響されてしまう等）
- next_permutationは辞書順に検索できる。しかも重複があってもそれをスキップして探索してくれるので超便利
- next_permutationは使用前にsortが必要！辞書順最後に到達した時点でnextがなくなる為
- 10!は約360万であるので、O(11!)ぐらいまではループで回せる

# 二分探索法
- lower_boundやupper_boundは二分探索で計算量はO(logN)
- 全組合せは膨大すぎて調べられない場合、目的の値（得点など）を二分探索するとO(logN)になる。N=1e18でもlogNは60程度

# 尺取り法
- 単調性があるときに使用可能
- 区間の長さ1（left=right）の時にOK、NGの両方ありうる場合は半開区間で考える（[l,r)）というか基本は半開区間
- rightをNGになるまでwhile分で進める際、NGになった瞬間のrightでwhile分の中を計算しないこと！
- 尺の中にある要素をmapやsetで持つのが典型（！？）

# 累積和
- 区間和を高速に求める事ができる
- 元の配列に仕切りをいれて、図示するとイメージしやすい（区間和は半開区間で求めるイメージ）
- 連続部分列がある値Kとなる個数を求めるには、Sr-Sl=Kとなれば良いので、Slをmap[Sl]=（Slとなる個数）としておけば高速に求められる

# グラフ

## BFS
- BFSはqueueで実装
- ループの先頭でpopして、空になるまで継続
- queueに入れるのは状態、目的値（最短距離など）はvectorで管理。
- ループありグラフを全探索するなら使用した頂点を訪れないように工夫が必要（目的値が存在しない頂点のみ辿るなど）
- 最短経路問題にBFSが使用可能。（e.g. 迷路の最短経路問題、01-BFS）
- 最短経路問題や01-BFSについては動的計画法の章で言及
- ボードゲームの全探索にも使用可能。各マスの状態を並べたベクトルを状態ベクトルとしてqueueに突っ込む

## DFS
- DFSはstackあるいは再帰関数で実装
- 再帰関数で実装する場合、重複演算しないように注意（メモ化再帰で工夫できる場合もある）
- DFSは最終経路まで一つずつ探索する方法であり、再帰関数で実装する事でバックトラックが可能。関数の最初に探索点の履歴をtrue、関数の最後に探索点の履歴をfalseすれば、visited配列を1つ持つだけで実装できる

## 木と森
- 要素数が辺の数＋1のとき木になる
- xの最遠点yの最遠点zとすると、yとzの距離が直径となる
- ある要素からの部分木サイズをxとすると、上側部分木のサイズは(N-x)と求まる
- 連結とは限らない閉路を含まないグラフを森という（木が幾つも含まれたグラフ）
- 森の連結成分数は頂点数 - 辺の数
- 次数が2以下の木をパスという（パスは、次数2以下かつ閉路なしで判定可能）

## なもり木（pseudo tree）
- 頂点数と辺の数が一致する（実際は木ではない）
- 閉ループがただ一つ存在する
- functional graph（任意の頂点に対して出次数が1の有向グラフが描ける）
- UnionFind木を作成後、各辺・各頂点に対して親にカウントしていき、一致していればなもり木である

## DAGと有向グラフ
- DAGは閉路のない有向グラフ
- トポロジカルソートに使用可能（入次数が0の頂点をキューに入れ、繋がっている頂点の入次数を1減らしてゼロになればキューに入れる）
- トポロジカルソートとは、グラフのつながる順番に頂点を並べるソートの事。繋がっていない頂点同士の優先順位は問題設定による
- 有向グラフの閉路判定は、トポロジカルソートができなければ閉路ありと判定可能（ソート済み配列のsize != N）

## 2部グラフ
- 頂点を2色に塗るとき、同じ色が隣り合わないように塗れるグラフ
- 木は必ず2部グラフ
- 再帰関数によって簡単に色塗り可能


## グラフその他
- 通常は頂点同士のつながりで考えるが、辺に着目（辺をベクターで持つ）することで解ける問題あり。例えば最小全域木を求めるクラスカル法はその良い例。または[全2頂点間最大辺の総和問題](https://atcoder.jp/contests/abc214/tasks/abc214_d)など

# 動的計画法（DP）

## 漸化式問題
- 漸化式は動的計画法で更新すると計算量を抑えられる
- 貰うdpと配るdpはどちらで解いても良い
- 状態量が10,000など大きくてもNが小さければ使える場合あり。もしかしたら使える可能性もあるので、計算量の見積りは冷静に実施する事
- 各状態が0か1なのであれば、状態をビットセットで持つと演算が楽になる場合あり
- 最後に選んだ番号を状態として保持する場合などは、初期化が難しい場合あり（何も選んでいないというdpの枠がない為）。このようなときは、そのとき初めて選んだ場合という事でiのループで毎回1増やすなどする（例: [E - Chain Contestant](https://atcoder.jp/contests/abc215/tasks/abc215_e)）

## 文字列問題
- 各文字を縦に並べ、正解文字を横に並べたdpテーブルを作ればよい
- dpテーブルと文字列の要素番号が一致するように、文字列にはあらかじめ空文字を先頭に追加しておくと良い

## ナップサックDP
- 縦に要素、横にパターンや最大コスト等を並べて順次更新していく
- 全探索では計算量が間に合わず、幾つか要素がある場合はこれが使えないか検討してみる

## 区間DP
- 列の中で隣り合うものを順に処理していく問題に活用可能
- dp[l][r]で[l,r)での目的となる値を格納（右側開区間である事に注意）
- widthを2～Nまで動かして、r=l+widthとする。lは0からN-widthまで動かす。repの終端条件が1ずれないように注意（1足さないと等号成立しない）！
- 遷移させるとき、単にd[l][k]とd[k][r]と分割できるのか、A[l]とA[r-1]がくっつくパターンもあり分割できないのか、よく考える事

## bit DP
- N個の集合から1つずつ何かに割り当てていくとき、O(N!)なのをO(N*2^N)やO(N^2*2^N)ぐらいに落とせる手法
- 巡回セールスマン問題が有名
- 集合から1つ取り除いたときの残りの集合との漸化式により解く
- dp[1がn個のbit列] = dp[1がn-1個のbit列] + 1個を取り除いたときのコストなどとする
- 取り除く時に残りの集合との依存関係がある場合はdp[bit列][要素番号]などとする
- 再帰関数で実装できるが、forループで回す手法も可能（まだ理解できていない）

## LIS 最長増加部分列
- 単調増加する最長の部分列を特定する手法
- 要素を順番に検査し、自分より大きい数を見つけたら書き換えていくだけで実装可能

## 最短経路問題
- 重み無しグラフの最短経路問題はBFSで解ける（始点が複数あってもOK！）
- 0/1重みグラフの最短経路問題は0/1-BFSで解ける（0の場合は先頭にpush）
- 重み有りグラフの最短経路問題はダイクストラ法（後述）
- 重み有りグラフの全頂点最短経路問題はワーシャル・フロイド法（後述）

## 01-BFS
- 閉ループであっても、辺のコストが0か1しかない最短経路問題に使用可能
- ダイクストラ法の単純な場合と言っても良い（最小コスト頂点が自明な為。計算も速い）
- 0コスト辺の場合、接続先頂点をqueのfrontに、1コスト辺の場合、接続先頂点をqueのbackにpushする事で実装可能
- 閉ループで戻ってきてしまうので、popした後、usedフラグを立てて置く。usedフラグが立っている場合はcontinue（popした頂点は確定点の為、再探索不要）

## ダイクストラ法
- 下記を繰り返していくことで、全頂点の距離を更新していき、最短経路を求める
- 始点は0、それ以外の全頂点にINFを代入
- 確定された頂点に接続された頂点を更新
- 未確定頂点の中から最小コスト頂点を確定
- 実装はpriority_queueを用いると簡単。pushした時点の距離が更新されていたらそのpop値は破棄する
- しかしながら、完全グラフなど辺の数が多い場合は、O(N^2)で実装した方が速い。ヨビノリ動画の通りに素直に実装すれば良い。自分で解いた例は[こちら](https://atcoder.jp/contests/joi2014yo/submissions/42739462)

## ワーシャルフロイド法
- 全頂点から全頂点への最短経路を求める方法
- 3重ループにより、経由値との比較をして順次行列を更新する
- 実装は非常にシンプル
- 計算量はO(N^3)

## グラフ＋状態遷移
- 頂点に状態を持たせる事で拡張する手法。頂点と状態をqueに入れる
- queに入ったコスト（得たい値）は別配列cost[v][state]で管理すれば良い
- 迷路の最小方向転換問題などに利用可能（01-BFS＋状態遷移）

## Union-Find tree
- UnionFind構造体を作る
- parentsの初期化（p[x]を用意し、全てが親、例えば-1としておく）
- find関数（再帰関数で実装すれば良い。実行時、p[x]も更新するとパス圧縮され次回のfindが速くなる）
- unite関数（親同士をくっつける。ただし、同じ連結木はつながないように注意）

## 最小全域木
- 全域木の中で辺の和が最小のものをいう
- クラスカル法により小さい順に連結頂点同士をつながないように辺を追加していく
- 連結頂点の判定はUnion-Find木を用いる
- Edgeという構造体を定義し、辺の長さで小さい順に並べる。この時、bool operaterで演算を定義しておく

# 計算量
- 問題文にある制約は使うべし（e.g. 一般解を求めると計算量が不足するが、合計枚数9999枚で支払えるとある場合には、その制約内でループを回す事で計算量を制限する事が可能）
- 連想配列mapを使うと、キーへのアクセスがO(logN)で可能。集合setも同様にO(logN)
- 計算量オーダーが10^10程度の場合、もしかしたら間に合うかもしれない。例えば100C5は分母が120なので実際は10^8程度まてオーダーが下がる

# IMOS法
- 重なり領域の累積はいもす法を用いて解決
- IMOS法は配列数が多すぎるときは座標圧縮とのコンビネーションで解ける問題多し
- 累積ではなく、重なっているかだけの判定で良ければ、引継ぎ型dpで解ける（ある点から何個後ろまで加算すべきかという情報において、何個の部分をmax取りしていけばよい）

# 平面走査
- (x,y)が順に与えられた場合に、"x1<y1 && x2<y2"となる点が存在するかを判定したい時に使える
- xの小さい順に走査し、存在するか判定。存在しなければyの値をためていく

# 実装テクニック

## ラムダ再帰
- auto func = [&](auto func, int x) -> int {return func(func, x)}のようなイメージで書ける
- わざわざグローバル変数にせずとも再帰関数に前提となる変数を渡すことができる（[&]の部分）
- 実際には関数オブジェクトなので関数ではないらしい

## 配列（ベクター）
- 配列同士の部分一致はequal関数が使用できる（equal(v1.begin(), v1.end(), v2.begin(), v2.end()）)。なお、v2.end()は指定しなくても同じ要素数だけ検索されるので省略可
- v.end()はN-1番目ではなくN番目を指す。すなわち、v.end() - v.begin() = Nとなる事に注意
- 2次元配列をIDに変える場合は x * W + yでhash化すれば良い。ただし、Wはyの範囲であることに注意！
- 隣接行列などは、Nが大きいとMLE（あるいは初期化時にTLE）するので要注意
- vec.size()はunsignedなので、それ同士を引き算してもマイナスにならない（SIZEマクロでll型に変更推奨）

## 構造体
- コンストラクタを定義したのに引数を指定しないとエラーが出る。no matching function for call to 'Struct::Struct()'コンストラクタにデフォルト引数を指定しておけば解決する
- 構造体にbool operater < (const &Struct s) {return x < s.x}などとすると、構造体同士の演算が定義できる。ただし、priority_queueに使うときは{}の前にconstと書かないとエラーが出る（理由不明）
- 自分定義の構造体をN個のvectorにする場合は、初期値を設定しないとエラーになる

## 実装テクニック（その他）
- vec.resize(K)で先頭K要素だけ取り出す事が可能
- nCrを何度も呼び出す場合、先に階乗を求めておいた方が速い（そうしないと呼び出す度に2*r回の掛け算が発生する為[実際は逆元の計算も追加で発生]）
- mapのkeyにpairを指定する場合、{a, b} (a<=b)となるように並び変えてから
- mapを作る際、keyに対するvalueが複数必要になるかどうか、常に注意
- 配列の値がxとなっている個数を調べたいときは、連想配列を使ってmap[x]=個数を作れば速度が速い（O(logN)）
- ループの中で履歴系の変数を使う際は要注意！毎ループ初期化すべきかそのままにすべきか考慮すること
- 漸化式の初期値（0 or 1）に気を付ける事（自信がなければ幾つか実験する事）
- swapする標準関数あり（swap(a, b)）
- INFを定義するときなどは、1LL<<62のようにLLを忘れずにつけること
- 負整数の割り算に注意！x/yにおいて、xが-(y-1)から-1の間のときも結果は0（切り上げられる形）。除算結果の正負判定は数学的に意味を持たなくなるので、分子・分母をそれぞれ判定する事
- 存在する要素から最小または最大を取り出したいだけのときは、優先度付きキューpriority_queueを用いるとO(logN)で実行可能（全探索すると最小値の判別にO(N)必要）
- setは平衡二分探索木で構成された順序付き集合であり、検索・挿入・削除が全てO(logN)で実行可能。
- x++と++xは代入演算子(=)とセットで使われると挙動が異なる。前置き(++x)はインクリメントされてからの代入となる
- MOD2を定義すると痛い目見る（MOD2と書いたつもりが一つだけMODと書いているなど。デバッグ困難）
- MOD忘れ要注意！

# その他
- 円環問題は、2*Nのベクターにすると解けることがある。円環で考えると難しいが直線だと簡単な場合は要検討
- 長方形は対角線上の2点を決めればすべての座標が決まる
- floor(N/i) i=1...Nは高々2*sqrt(N)個しかない。i<=sqrt(N)がsqrt(N)種類、その他のiについてはfloor(N/i)がsqrt(N)以下となるのでsqrt(N)種類という事

# これまでに解いた問題数
- 以下は最初に解いた115問。以降は[Atcoder Problemsで管理](https://kenkoooo.com/atcoder/#/table/)
- 45問: 競プロ典型90問: （★4以下の全問）
- 69問: 分野別　初中級者が解くべき過去問精選 100 問: （問1,10,17,18,24-25,28,32,34-38,44-46,48-49,53,56,60,64,66,68,70,82,85,92,94はatcoderでないためスキップ。52,75,84は難しい為スキップ）(memo) 4+2+2+5+3+2+9=28, 3
- 1問: [N Slimes](https://atcoder.jp/contests/dp/tasks/dp_n)



