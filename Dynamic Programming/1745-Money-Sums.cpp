/*
    Here the future requires to know which coin has been used already.

    We can choose an element at most once. So, we add another state that
   represents the first i elements.

   dp[i][s] denotes if we could make a sum of s with first i elements by
   choosing them at most once
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
  vector<int> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];
  sort(V.begin(), V.end());

  int sm = accumulate(V.begin(), V.end(), 0);

  vector<vector<int>> dp(N + 1, vector<int>(sm + 1, 0));
  // sum 0 can be made by choosing nothing
  dp[0][0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int s = 0; s <= sm; s++) {
      // if we do not take the element
      dp[i][s] = dp[i - 1][s];
      if (V[i - 1] <= s)
        dp[i][s] |= dp[i - 1][s - V[i - 1]];
    }
  }

  // sum of 0 should not be considered
  int res = accumulate(dp[N].begin(), dp[N].end(), 0) - 1;
  cout << res << endl;
  for (int i = 1; i <= sm; i++)
    if (dp[N][i])
      cout << i << " ";

  return 0;
}