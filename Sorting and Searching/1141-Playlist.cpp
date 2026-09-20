/*
    Longest subarray with distinct characters - Sliding Window

    OPTIMIZATION (HashMap):
    1. perform less hashing operations and referencing/dereferencing operations
    2. Use &cnt = Mp[y] where y = V[start] and then do cnt--
    3. Do a reserve(2 * N) elements on Map
    4. Do a max_load_factor of 0.7 for lesser collisions

    OPTIMIZATION (Algorithm):
    1. We only need to know the last position of the seen value as the window
   will shrink till there
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

  int N;
  cin >> N;
  unordered_map<int, int> Mp;
  Mp.reserve(2 * N);
  Mp.max_load_factor(0.7);
  //   int start = 0, end = 0, marker = 0, res = 0;
  //   while (end < N) {
  //     int x = V[end++];
  //     if (++Mp[x] > 1)
  //       marker = 1;
  //     while (marker) {
  //       int y = V[start];
  //       int &cnt = Mp[y];
  //       cnt--;
  //       if (cnt == 1)
  //         marker = 0;
  //       else if (cnt == 0)
  //         Mp.erase(y);
  //       start++;
  //     }
  //     res = max(res, end - start);
  //   }
  int left = 0, res = 0, x;
  for (int i = 0; i < N; i++) {
    cin >> x;
    if (Mp.count(x))
      left =
          max(left, Mp[x] + 1); // new window starts from beyond the last seen
    Mp[x] = i;
    res = max(res, i - left + 1);
  }
  cout << res << endl;

  return 0;
}