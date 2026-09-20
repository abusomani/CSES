#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N, X;
  cin >> N >> X;
  vector<ll> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];
  ll sm = 0, start = 0, end = 0, res = 0;
  while (end < N) {
    sm += V[end++];
    while (sm >= X) {
      if (sm == X)
        res++;
      sm -= V[start++];
    }
  }
  cout << res << endl;
  return 0;
}