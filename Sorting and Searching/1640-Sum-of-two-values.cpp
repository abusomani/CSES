/*
    Another example where Hashmap will TLE on adverse cases where the random
   numbers beat the hash to push it to O(N) per case due to collisions
   Hence, sorting and binary searching makes it deterministic O(NlogN)
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int alternate_main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N, X;
  cin >> N >> X;
  vector<ll> V(N);
  unordered_map<ll, int> Mp;
  bool possible = false;
  for (int i = 0; i < N; i++)
    cin >> V[i];
  for (int i = 1; i <= N; i++) {
    if (Mp.count(X - V[i - 1])) {
      possible = true;
      cout << Mp[X - V[i - 1]] << " " << i << endl;
      break;
    }
    Mp[V[i - 1]] = i;
  }
  if (!possible) {
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N, X, y;
  cin >> N >> X;
  vector<pii> V(N);
  bool possible = false;
  for (int i = 0; i < N; i++) {
    cin >> y;
    V[i] = {y, i + 1};
  }
  sort(V.begin(), V.end());
  auto search = [&](int dest, int pos) -> int {
    int l = 0, r = N - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (V[mid].first == dest) {
        if (V[mid].second != pos)
          return V[mid].second;
        int i = mid - 1, j = mid + 1;
        if (i >= 0 and V[i].first == dest)
          return V[i].second;
        else if (j < N and V[j].first == dest)
          return V[j].second;
        return -1;
      } else if (V[mid].first < dest)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return -1;
  };

  for (int i = 0; i < N; i++) {
    int v = V[i].first, p = V[i].second, d = search(X - v, p);
    if (d != -1) {
      cout << min(p, d) << " " << max(p, d) << endl;
      possible = true;
      break;
    }
  }

  if (!possible) {
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}