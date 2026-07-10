#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string dna;
  cin >> dna;
  int res = 1, cnt = 1, N = (int)dna.size();
  for (int i = 1; i < N; i++) {
    if (dna[i] != dna[i - 1]) {
      res = max(res, cnt);
      cnt = 1;
    } else
      cnt++;
  }
  cout << max(res, cnt) << endl;
  return 0;
}