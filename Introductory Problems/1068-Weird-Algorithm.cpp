#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N;
  cin >> N;
  while (N != 1) {
    cout << N << " ";
    if (N % 2 == 0) {
      N /= 2;
    } else {
      N = 3 * N + 1;
    }
  }
  cout << 1 << endl;
  return 0;
}