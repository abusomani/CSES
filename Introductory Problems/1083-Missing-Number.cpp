#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, res = 0, x;
  cin >> N;
  for (int i = 1; i < N; i++) {
    cin >> x;
    res ^= x;
    res ^= i;
  }
  res ^= N;
  cout << res << endl;
  return 0;
}