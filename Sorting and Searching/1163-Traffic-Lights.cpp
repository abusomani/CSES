/*
    ONLINE ALGORITHM:
    We maintain two sets. One for points (set will suffice because all points
   are distinct)
   And another Multiset for gaps. Gaps can be redundant.
   When we add a point, we find the lower and upper bound to it.
   We add 0 and X as the boundaries to ensure there always exist a lower and
   upper bound.
   We calculate the current gap between upper and lower. Find it's instance in
   gaps Delete the same and add the new gaps created by upper - current and
   current - lower Last element of multiset is the longest gap.

   OPTIMIZED ALGORITHM (OFFLINE):
   Your online solution has to maintain all interval lengths in a multiset
    because inserting a light splits one interval into two, and the maximum
   interval can increase or decrease.

    The offline solution exploits a monotonic property:
    1. Removing a light only merges two adjacent intervals.
    2. The longest interval can never shrink, only stay the same or grow.

    That monotonicity eliminates the need for a multiset entirely. You only
    need:
    1. one ordered set<int> for the light positions,
    2. one integer mx for the current longest interval.
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

  int X, N, p;
  cin >> X >> N;
  multiset<int> gaps;
  set<int> points;
  points.insert(0);
  points.insert(X);
  gaps.insert(X); // initial gap of X
  for (int i = 0; i < N; i++) {
    cin >> p;
    auto it = points.upper_bound(p);
    auto pre = prev(it);
    int currentGap = *it - *pre;
    gaps.erase(gaps.find(currentGap));
    gaps.insert(p - *pre);
    gaps.insert(*it - p);
    points.insert(p);
    cout << *(gaps.rbegin()) << " \n";
  }
  return 0;
}