/*
    dp[i][j] = number of ways to reach cell (i,j)
    dp[i][j] = dp[i-1][j] + dp[i][j-1]
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

  int N;
  cin >> N;
  vector<vector<char>> V(N, vector<char>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cin >> V[i][j];
  }

  // number of ways to reach square [i][j] if we come from top and left
  vector<vector<ll>> dp(N, vector<ll>(N, 0)); // initially no path to any square

  dp[0][0] = V[0][0] != '*'; // 1 way if it's not a trap or else 0 ways
  for (int i = 1; i < N; i++) {
    // neither this square should be a trap
    // nor the previous transitioning dp should have 0 ways
    dp[i][0] = (V[i][0] != '*' and dp[i - 1][0] != 0);
    dp[0][i] = (V[0][i] != '*' and dp[0][i - 1] != 0);
  }

  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (V[i][j] == '*') {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }
  cout << dp[N - 1][N - 1] % MOD << endl;
  return 0;
}