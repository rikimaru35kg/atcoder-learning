#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)


int main() {
  int N;
  cin >> N;

  if (N%2 != 0) {
    cout << endl;
    return 0;
  }

  vector<string> answers;
  queue<string> bfs;

  bfs.push("(");
  while( !bfs.empty()){
    string tmp = bfs.front();
    bfs.pop();

    if (tmp.size() == N) {
      answers.push_back(tmp);
    }

    if (count(tmp.begin(), tmp.end(), '(') < (N/2) ) {
      bfs.push(tmp + "(");
    }
    if (count(tmp.begin(), tmp.end(), '(') > (count(tmp.begin(), tmp.end(), ')'))) {
      bfs.push(tmp + ")");
    }
  }

  for (string x: answers) {
    cout << x << endl;
  }

}
