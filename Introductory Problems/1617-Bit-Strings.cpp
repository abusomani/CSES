#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long N, res = 1;
  cin >> N;
  for (int i = 1; i <= N; i++)
    res = (res << 1) % MOD;
  cout << res << endl;

  return 0;
}