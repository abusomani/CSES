/*
    The greedy but optimized way is to use 2-pointers to match the lowest with
   highest as that ensures clubbing up the higher with lower and find lowest
   number of gondolas required.
   Because if you start clubbing the smaller ones, then all the higher ones i.e.
   > (X / 2) weights are bound to have 1 gondola each

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

  long N, X;
  cin >> N >> X;
  vector<long> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];

  sort(V.begin(), V.end());
  long gondola = 0;
  int i = 0, j = N - 1;
  while (i <= j) {
    if (V[i] + V[j] <= X) {
      gondola++;
      i++;
      j--;
    } else {
      gondola++;
      j--;
    }
  }
  cout << gondola << endl;
  return 0;
}