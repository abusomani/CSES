/*
    Maximum Non-Overlapping intervals count.
    Trick and intuition is to sort ascending based on the end-times. It's like
   scheduling meetings We would want the meeting ending early to be chosen for
   freeing up schedule for more meetings that could be accomodated later.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vpii V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i].first >> V[i].second;
  sort(V.begin(), V.end(),
       [&](const pii &A, const pii &B) { return A.second < B.second; });

  int res = 0, pre = -1;
  for (auto P : V) {
    int s = P.first, e = P.second;
    if (pre <= s) {
      res++;
      pre = e;
    }
  }
  cout << res << endl;
  return 0;
}