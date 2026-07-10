/*
The sorting solution is generally the preferred approach because its
performance is deterministic, while unordered_set depends heavily on hash
quality, bucket growth, and the specific implementation of the C++ standard
library.
Sorting is surely NlogN. While Hashset and Hashmap can still TLE because of
adverse test cases are generated to beat the standard hash to make it O(N)
worst case
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

  int N, x;
  cin >> N;
  vector<int> V;
  for (int i = 0; i < N; i++) {
    cin >> x;
    V.push_back(x);
  }
  sort(V.begin(), V.end());
  int res = 1;
  for (int i = 1; i < N; i++) {
    if (V[i] != V[i - 1])
      res++;
  }
  cout << res << endl;
  return 0;
}
/*
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
  unordered_set<int> St;
  St.reserve(N);
  St.max_load_factor(0.7);
  for (int i = 0; i < N; i++) {
    cin >> x;
    St.insert(x);
  }
  cout << (int)St.size() << endl;
  return 0;
}
*/