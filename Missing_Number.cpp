#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll N;
    cin >> N;
    ll ans = 0, x;
    for (int i = 1; i <= N; i++)
        ans ^= i;
    for (int i = 1; i < N; i++)
        cin >> x, ans ^= x;
    cout << ans << endl;

    return 0;
}