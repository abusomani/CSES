
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const ll NEG_INF = -4e18;
const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<ll> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];

  // dp[i][j][0] maximum score that Player one can get from interval [i,...j] if
  // its his turn
  // dp[i][j][1] is the maximum score that Player one can get from
  // interval [i,...j] if its 1th turn.
  // Intention of 1th player would be to minimize 0th score
  vector<vector<vector<ll>>> dp(
      N + 1, vector<vector<ll>>(N + 1, vector<ll>(2, NEG_INF)));

  // all length 1 states
  for (int i = 0; i < N; i++) {
    // Only element possible will be picked
    dp[i][i][0] = V[i];
    // Won't let 0th player pick anything
    dp[i][i][1] = 0;
  }

  for (int len = 2; len <= N; len++) {
    for (int l = 0; l + len <= N; l++) {
      int r = l + len - 1;
      dp[l][r][0] = max(V[l] + dp[l + 1][r][1], V[r] + dp[l][r - 1][1]);
      dp[l][r][1] = min(dp[l + 1][r][0], dp[l][r - 1][0]);
    }
  }

  cout << dp[0][N - 1][0] << endl;
  return 0;
}