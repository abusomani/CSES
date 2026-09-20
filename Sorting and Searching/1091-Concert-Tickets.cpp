#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll N, M, x;
  cin >> N >> M;
  multiset<ll> MSt;
  for (int i = 0; i < N; i++) {
    cin >> x;
    MSt.insert(x);
  }
  for (int i = 0; i < M; i++) {
    cin >> x;
    // No tickets to sell
    if (MSt.empty()) {
      cout << -1 << endl;
      continue;
    }
    // Find the smallest value >= our price being quoted
    auto it = MSt.lower_bound(x);
    // If its the end or the value is greater than our quoted price then see the
    // previous pointer
    if (it == MSt.end() or (*it) > x) {
      it = prev(it);
      // if there does not exist any price then -1
      if (it == MSt.end()) {
        cout << -1 << endl;
        continue;
      }
    }
    // If the value does exist then simple check
    if (*it > x) {
      cout << -1 << endl;
    } else {
      cout << *it << endl;
      // We erase the ticket sold
      MSt.erase(it);
    }
  }

  return 0;
}