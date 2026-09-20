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

  int N;
  cin >> N;

  vector<int> dp(N + 1, INT_MAX); // dp[i] is minimum number of steps required
                                  // to make i as 0 using its digits

  dp[0] = 0; // no steps required as already 0
  // in one step the number can be made 0
  for (int i = 1; i <= 9; i++)
    dp[i] = 1;

  for (int i = 10; i <= N; i++) {
    int tmp = i;
    vector<int> cnt(10, 0);
    while (tmp) {
      cnt[tmp % 10] = 1;
      tmp /= 10;
    }
    for (int j = 1; j <= 9; j++) {
      if (cnt[j])
        dp[i] = min(dp[i], 1 + dp[i - j]);
    }
  }
  cout << dp[N] << endl;
  return 0;
}