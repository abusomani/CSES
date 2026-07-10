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
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (N <= 3) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }
  for (int i = 2; i <= N; i += 2)
    cout << i << " ";
  for (int i = 1; i <= N; i += 2)
    cout << i << " ";

  return 0;
}