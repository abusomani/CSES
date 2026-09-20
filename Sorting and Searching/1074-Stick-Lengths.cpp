/*
    Minimization of sum of the absolute deviations (Median selection):
        1. Sort the array
        2. Minimum difference will happen when we choose the Median
        3. (N-1)/2 and N/2 th position (excluding size 1)

    KEEP IN MIND:
        1. Sum of absolute deviations -> Median selection
        2. Sum of squared deviations -> Mean selection
*/
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
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  sort(V.begin(), V.end());
  long sm1 = 0, sm2 = 0, mid1 = V[(N - 1) / 2], mid2 = V[N / 2];
  for (auto v : V)
    sm1 += abs(mid1 - v);
  for (auto v : V)
    sm2 += abs(mid2 - v);
  cout << min(sm1, sm2) << endl;
  return 0;
}