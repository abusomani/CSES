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
  vector<ll> dp(X + 1, 0); // number of sequences to make the sum of exactly i

  dp[0] = 1; // only one sequence to make sum of 0, empty sequence
  for (int i = 1; i <= X; i++) {
    for (auto c : coins) {
      if (c > i)
        break;
      dp[i] = (dp[i] + dp[i - c] % MOD) % MOD;
    }
  }
  cout << dp[X] % MOD << endl;
  return 0;
}