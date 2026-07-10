#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

// N * (N-1) * (N-2) .... * 1
// We need to find how many times 5 occurs.
// 1 time for all direct divisors of 5.
// 1 time for all direct divisors of 25. As the N is static.
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N, res = 0;
  cin >> N;
  for (ll p = 5; p <= N; p *= 5)
    res += N / p;
  cout << res << endl;

  return 0;
}