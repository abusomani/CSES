/*
    How many ways to came sum of 4?
    We care about the last throw
    Lets say the last throw = 1
    Then we must have thrown 3. Hence, all possible ways of 3 could be appended
   with a 1. Hence, all ways to make 3 becomes a sequence for 4. Contribution
   being ways(3).

   For any i, the last throw must be 1,2,3,4,5,6
   Hence,
    RECURRENCE:
   ways(i) = ways(i-1) + ways(i-2) + ..... + ways(i-6)

   Why ways(0) = 1?
    Because dp[i] is sequences whose sum is i. How many sequences sum to 0? Only
   1 i.e. empty sequence []

   The empty sequence acts like the multiplicative identity in combinatorial
   counting i.e it represents "there is exactly one way to do nothing."


   This Process is called ORDERED COUNTING / COMPOSITIONS as (1, 1, 2) is
   different way than (1, 2, 1)
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
  ll N;
  cin >> N;
  vector<ll> dp(N + 1, 0); // number of ordered sequences of dice throws whose
                           // total sum is exactly i
  dp[0] = 1;               // one sequence to get 0 i.e the empty sequence
  for (int i = 1; i <= N; i++) {
    for (int throws = 1; throws <= 6; throws++) {
      if (throws > i)
        break;
      // one more way than to get (i - throws) sum
      dp[i] += (dp[i - throws]) % MOD;
    }
  }
  cout << dp[N] % MOD << endl;
  return 0;
}