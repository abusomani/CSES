#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    long x, y;
    cin >> x >> y;
    long mx = max(x, y), base_num = mx * (mx - 1) + 1, res;
    // row same
    if (mx == x) {
      res = base_num + ((mx - y) * (mx % 2 == 0 ? 1 : -1));
    } else { // col same
      res = base_num + ((mx - x) * (mx % 2 == 0 ? -1 : 1));
    }
    cout << res << endl;
  }

  return 0;
}