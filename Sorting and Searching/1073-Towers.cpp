/*
    Use vector to find upper_bound of given number. If it's the end then we need
   to create a new tower. Else, we coud simply replace the current tower element
   with the given number representing placing of the cube on top of the tower.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, x;
  cin >> N;
  vector<int> V;
  for (int i = 0; i < N; i++) {
    cin >> x;
    auto it = upper_bound(V.begin(), V.end(), x);
    if (it == V.end())
      V.push_back(x);
    else
      *it = x;
  }
  cout << (int)V.size() << endl;
  return 0;
}