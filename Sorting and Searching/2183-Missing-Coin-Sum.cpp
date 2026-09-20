/*
  After processing i coins in sorted order, if the sum of these coins is sm.
  Then,
  INVARIANT: Every value in the range [1, sm] can be formed using some
  subset of the processed coins.

  Because [1, sm] and if the next value of coin v is <= sm + 1, then this v
  could be added to each value to produce [v, v+sm]
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

  int N;
  cin >> N;
  vector<ll> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];

  sort(V.begin(), V.end());
  ll sm = 0;
  for (auto v : V) {
    if (v > sm + 1) {
      break;
    }
    sm += v;
  }
  cout << sm + 1 << endl;
  return 0;
}