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

  int N, X;
  cin >> N >> X;
  vector<int> coins(N);
  for (int i = 0; i < N; i++)
    cin >> coins[i];

  sort(coins.begin(), coins.end());
  vector<ll> dp(X + 1,
                INT_MAX); // minimum number of coins required to make exactly i

  dp[0] = 0; // no coins required to make 0
  for (int i = 1; i <= X; i++) {
    for (auto c : coins) {
      if (c > i)
        break;
      if (dp[i - c] != INT_MAX)
        dp[i] = min(dp[i], 1 + dp[i - c]);
    }
  }
  cout << (dp[X] == INT_MAX ? -1 : dp[X]) << endl;
  return 0;
}