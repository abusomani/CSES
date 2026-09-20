/*
    Incrementally calculate the previous violations and new violations. That
   would keep on adding on the baseRounds.
   KEEP IN MIND: to update the baseRounds with the new diff as that would be the
   base for next round.
   We would need to keep some ID mapping for finding index of positions
   KEEP IN MIND: To remove double counting when the indices are adjacent
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

  int N, M, x;
  cin >> N >> M;
  vector<pii> V(N);
  for (int i = 0; i < N; i++) {
    cin >> x;
    V[i] = {x, i + 1};
  }
  sort(V.begin(), V.end());
  vector<int> ID(N + 1);
  for (int i = 0; i < N; i++)
    ID[V[i].second] = i;
  int baseRounds = 1, curr = V[0].second;
  for (int i = 1; i < N; i++) {
    if (V[i].second < curr)
      baseRounds++;
    curr = V[i].second;
  }
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    int aIdx = ID[a], bIdx = ID[b];
    if (aIdx > bIdx)
      swap(aIdx, bIdx);
    auto countViolation = [&](int l) -> int {
      int violation = 0;
      if (l > 0 and V[l].second < V[l - 1].second)
        violation++;
      if (l < N - 1 and V[l].second > V[l + 1].second)
        violation++;
      return violation;
    };
    int prevViolations = countViolation(aIdx) + countViolation(bIdx);
    // remove extra counting if they are adjacent
    if (bIdx == aIdx + 1 and (V[bIdx].second < V[aIdx].second))
      prevViolations--;
    swap(V[aIdx], V[bIdx]);
    swap(ID[a], ID[b]);
    int newViolations = countViolation(aIdx) + countViolation(bIdx);
    // remove extra counting if they are adjacent
    if (bIdx == aIdx + 1 and (V[bIdx].second < V[aIdx].second))
      newViolations--;
    baseRounds += (newViolations - prevViolations);
    cout << baseRounds << endl;
  }
  return 0;
}