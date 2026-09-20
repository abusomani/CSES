/*
  Difference between Ordered DP and Unordered DP is simply the loops being
  exchanged.

  In ordered DP, at every sum i, we have all the options available to create
  Permutations

  While, in unordered DP, we need to find all the Combinations and not
  Permutations, so, we go coin by coin i.e. first through option and then the
  sum i

  By doing so, we ensure that 2,1 can never happen as 1 is processed before 2
  thereby creating sequences like [1,2] or [1,1....,1,2] but 2 never comes in
  the middle

  This problem could also be solved using 2D DP dp[i][s] which means the number
  of ways to make a sum of s by using the first i coins (each available
  unlimited times)
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

  int N, X;
  cin >> N >> X;
  vector<int> coins(N);
  for (int i = 0; i < N; i++)
    cin >> coins[i];

  sort(coins.begin(), coins.end());
  vector<ll> dp(X + 1, 0); // number of sequences to make the sum of exactly i

  dp[0] = 1; // only one sequence to make sum of 0, empty sequence
  for (auto c : coins) {
    for (int i = c; i <= X; i++) {
      dp[i] = (dp[i] + dp[i - c] % MOD) % MOD;
    }
  }
  cout << dp[X] % MOD << endl;
  return 0;
}