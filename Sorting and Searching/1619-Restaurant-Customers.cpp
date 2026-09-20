/*
    Simulating the line sweep algorithm using Map.
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
  ll N, a, b;
  cin >> N;
  map<long, long> Mp;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    Mp[a]++;
    Mp[b]--;
  }
  ll res = 0, sm = 0;
  for (auto p : Mp) {
    sm += p.second;
    res = max(res, sm);
  }
  cout << res << endl;
  return 0;
}