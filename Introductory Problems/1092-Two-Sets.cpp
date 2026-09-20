/*
    Lemma is that every number can be formed [1, m] and then if we choose (m+1)
   then all numbers till (2*m + 1) can be formed.
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

  ll N;
  cin >> N;
  if (!(N % 4 == 0 or N % 4 == 3))
    cout << "NO\n";
  else {
    ll sm = (N * (N + 1)) / 4;
    vector<int> first, second;
    for (int i = N; i >= 1; i--) {
      if (i > sm)
        second.push_back(i);
      else {
        sm -= i;
        first.push_back(i);
      }
    }
    cout << "YES\n" << first.size() << endl;
    for (auto v : first)
      cout << v << " ";
    cout << "\n" << second.size() << endl;
    for (auto v : second)
      cout << v << " ";
  }

  return 0;
}