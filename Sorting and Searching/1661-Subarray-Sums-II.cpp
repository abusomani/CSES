#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// Custom hash function to prevent hash collisions
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N, X;
  cin >> N >> X;
  ll res = 0, sm = 0, v;
  //   gp_hash_table<ll, int, custom_hash> Mp;
  map<ll, int> Mp;
  Mp[0] = 1;
  for (int i = 0; i < N; i++) {
    cin >> v;
    sm += v;
    auto it = Mp.find(sm - X);
    if (it != Mp.end())
      res += it->second;
    Mp[sm]++;
  }
  cout << res << endl;
  return 0;
}