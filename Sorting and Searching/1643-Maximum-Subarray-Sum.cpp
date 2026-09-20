#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<ll> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];
  ll minPrefixSoFar = 0, prefixSum = 0, res = LONG_MIN;
  for (auto num : V) {
    prefixSum += num;
    res = max(res, prefixSum - minPrefixSoFar);
    minPrefixSoFar = min(minPrefixSoFar, prefixSum);
  }
  cout << res << endl;
  return 0;
}