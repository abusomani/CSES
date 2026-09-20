/*

SUFFIX DP (Top Down):
    dp(i, money)= maximum pages obtainable using books from i to N-1 with budget
    = money.

    dp(i,money) = max( dp(i+1,money), pages[i] + dp(i+1,money-price[i]))


PREFIX DP (Bottom Up):
    dp(i, money)= maximum pages obtainable using books from 0 to i-1 with budget
    = money.

    dp(i,money) = max( dp(i-1,money), pages[i] + dp(i-1,money-price[i]))

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
  vector<pii> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i].first;
  for (int i = 0; i < N; i++)
    cin >> V[i].second;

  vector<vector<int>> dp(
      N + 1, vector<int>(
                 X + 1,
                 0)); // dp[i][j] is the maximum pages that can be
                      // bought using the first [0,i) books and at most j rupees

  // if we select the book then and not select then
  // dp[i][j] = max(dp[i][j], pages[i-1] + dp[i-1][j-prices[i-1]], dp[i-1][j])

  // Incorrect for 0/1 Knapsack.
  //
  // Since j increases, dp[j - price] may already include
  // the current book from this same iteration.
  // This allows the current book to be chosen multiple times,
  // turning the transition into Unbounded Knapsack.
  //   for (int i = 0; i < N; i++) {
  //     int price = V[i].first, pages = V[i].second;
  //     for (int j = price; j <= X; j++) {
  //       dp[i] = max(dp[i], pages + dp[j - price]);
  //     }
  //   }

  for (int i = 1; i <= N; i++) {
    int price = V[i - 1].first, pages = V[i - 1].second;
    for (int j = 1; j <= X; j++) {
      // if we do not buy then whatever was optimal for (i-1) books holds true
      dp[i][j] = dp[i - 1][j];
      // we go to dp[i-1] to ensure this book only used at most once
      if (price <= j)
        dp[i][j] = max(dp[i][j], pages + dp[i - 1][j - price]);
    }
  }

  cout << dp[N][X] << endl;

  return 0;
}