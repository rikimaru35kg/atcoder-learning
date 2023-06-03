# はじめに
このページでは、競プロでこれまでに学んだ内容（教訓）を端的に箇条書きします。

# これまでに解いた問題数
- 競プロ典型90問: 27問（★4以下の問48まで）

# 順列全探索
- 制約数が少なければ全探索を考える
- 後述のBFSやDFSも全探索だが、こちらの方が実装が簡単なので、可能なら順列全探索

# 尺取り法
- 単調性があるときに使用可能
- 尺の中にある要素をmapやsetで持つのが典型

# グラフ

## BFSとDFS
- BFSはqueue、DFSはstackで実装
- ループの先頭でpopして、空になるまで継続
- 基本的に全探索するなら木構造（＝閉路なし）である必要があるが、動的計画法と併用する事でBFSが使える場合もある（e.g. 迷路の最短経路問題、01-BFS）
- 01-BFSについては動的計画法の章で言及

## 木の直径
- 要素数が辺の数＋1のとき木になる
- xの最遠点yの最遠点zとすると、yとzの距離が直径となる

## 2部グラフ
- 頂点を2色に塗るとき、同じ色が隣り合わないように塗れるグラフ
- 木は必ず2部グラフ
- 再帰関数によって簡単に色塗り可能

# 動的計画法

## 文字列問題
- 各文字を縦に並べ、正解文字を横に並べたdpテーブルを作ればよい
- dpテーブルと文字列の要素番号が一致するように、文字列にはあらかじめ空文字を先頭に追加しておくと良い

## ダイクストラ法
- 下記を繰り返していくことで、全頂点のコストを更新していく
- 確定された頂点に接続された頂点を更新
- 未確定頂点の中から最小コスト頂点を確定

## 01-BFS
- 閉ループであっても、辺のコストが0か1しかない最短経路問題に使用可能
- ダイクストラ法の単純な場合と言っても良い（最小コスト頂点が自明な為。計算も速い）
- 0コスト辺の場合、接続先頂点をqueのfrontに、1コスト辺の場合、接続先頂点をqueのbackにpushする事で実装可能

## グラフ＋状態遷移
- 頂点に状態を持たせる事で拡張する手法。頂点と状態をqueに入れる
- queに入ったコスト（得たい値）は別配列cost[v][state]で管理すれば良い
- 迷路の最短方向転換問題などに利用可能（01-BFS＋状態遷移）

# Union-Find tree
- parentsの初期化、find関数（再帰関数、親更新）、unite関数
- unite関数で同じ連結木にある元同士をつながないように注意！

# ユークリッドの互除法
- gcd(a, b) = gcd(b, r) = ... = gcd(b', 0) = b'という古典的アルゴリズム
- 再帰関数で簡潔に書ける
- 拡張ユークリッドの互除法も再帰関数で簡潔に書ける（ax+by=gcd(a,b)のx, y, gcd(a,b)を求める問題）

# その他
- lower_bound関数で、配列中のどこの間に入るかわかる（戻り値がイテレータである事に注意）
- 2次元配列をIDに変える場合は x * W + yでhash化すれば良い。ただし、Wはyの範囲であることに注意！
- 問題文にある制約は使うべし（e.g. 一般解を求めると計算量が不足するが、合計枚数9999枚で支払えるとある場合には、その制約内でループを回す事で計算量を制限する事が可能）
- 小数点を出力する際はcout << fixed << setprecision(10) << x << endl;などとしないと小数点以下の桁が6桁ぐらいまでしか出力されない
- 小数点の計算は誤差がある為、厳密な大小判定には使えない。整数型に直せれば厳密な判定が可能。
- 連想配列mapを使うと、キーへのアクセスがO(logN)で可能。集合setも同様にO(logN)
- 配列の値がxとなっている個数を調べたいときは、連想配列を使ってmap[x]=個数を作れば後の処理が軽くなる
- 重なり領域の累積はいもす法を用いて解決
- ループの中で履歴系の変数を使う際は要注意！毎ループ初期化すべきかそのままにすべきか考慮すること
- a, b, cが自然数の時、a*b<=c とa<=floor(c/b)は同値（必要十分条件）
- 漸化式の初期値（0 or 1）に気を付ける事（自信がなければ幾つか実験する事）
- swapする標準関数あり
- 上手く規格が合わずソートできない場合は、無理やり規格を合わせてごちゃ混ぜソートすると解ける場合あり（e.g. 1分でB点、2分でA点取れる場合、1分でB点取り、更に1分でA-B点取れると考えるなど）


