#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, x;
  cin >> N;
  vector<pii> V(N);
  for (int i = 0; i < N; i++) {
    cin >> x;
    V[i] = {x, i};
  }
  sort(V.begin(), V.end());
  int rounds = 1, curr = V[0].second;
  for (int i = 1; i < N; i++) {
    if (V[i].second < curr)
      rounds++;
    curr = V[i].second;
  }
  cout << rounds << endl;
  return 0;
}