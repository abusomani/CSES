/*
    dp[i][j] is the number of valid assignments of the first i positions
    such that value at position (i-1) is equal to j

    i.e. last processed value is j

    // Pull DP:
    // dp[i][j] receives contributions from
    // dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1].

    // Push DP:
    // dp[i-1][j] contributes to
    // dp[i][j-1], dp[i][j], dp[i][j+1].
*/
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

  ll N, M;
  cin >> N >> M;
  vector<ll> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];
  vector<vector<ll>> dp(N + 1, vector<ll>(M + 2, 0));
  // base case
  if (V[0] == 0) {
    // all are possible
    for (int j = 1; j <= M; j++)
      dp[1][j] = 1;
  } else {
    dp[1][V[0]] = 1;
  }
  for (int i = 2; i <= N; i++) {
    int val = V[i - 1];
    if (val != 0) {
      dp[i][val] = (dp[i - 1][val - 1] % MOD + dp[i - 1][val] % MOD +
                    dp[i - 1][val + 1] % MOD) %
                   MOD;
      continue;
    }
    for (int j = 1; j <= M; j++)
      dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1] % MOD +
                  dp[i - 1][j] % MOD) %
                 MOD;
  }

  ll res = 0;
  for (auto v : dp[N])
    res = (res + v) % MOD;
  cout << res << endl;
  return 0;
}