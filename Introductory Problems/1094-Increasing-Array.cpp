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
  long mx = 0, curr, res = 0;
  for (int i = 0; i < N; i++) {
    cin >> curr;
    // Very important: the element would be increased in-place for the rest of
    // the array, hence we keep track of the maximum till now
    if (curr < mx)
      res += mx - curr;
    mx = max(mx, curr);
  }
  cout << res << endl;
  return 0;
}