/*
    After sorting both desired and actual size, we try to match one-by-one.
    - If both are within the K difference, then we can match and move on in both
   arrays
   - If the actual size of apartment is beyond desired + K then there is no
   way to match for this candidate and we progess to next desired size
   - If the actual size of apartment is less than desired - K then there is no
   way to match for this apartment and we progess to next apartment size
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

  long N, M, K;
  cin >> N >> M >> K;
  vector<long> applicantDesiredSizes(N), apartmentSizes(M);
  for (int i = 0; i < N; i++)
    cin >> applicantDesiredSizes[i];
  for (int i = 0; i < M; i++)
    cin >> apartmentSizes[i];

  sort(applicantDesiredSizes.begin(), applicantDesiredSizes.end());
  sort(apartmentSizes.begin(), apartmentSizes.end());

  int res = 0, i = 0, j = 0;
  while (i < N and j < M) {
    if (abs(applicantDesiredSizes[i] - apartmentSizes[j]) <= K) {
      res++;
      i++;
      j++;
    } else if (applicantDesiredSizes[i] + K < apartmentSizes[j])
      i++;
    else if (applicantDesiredSizes[i] - K > apartmentSizes[j])
      j++;
  }
  cout << res << endl;
  return 0;
}