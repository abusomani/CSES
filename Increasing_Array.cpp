#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int N, x;
    cin >> N;
    vector<int> V;
    for (int i = 0; i < N; i++)
        cin >> x, V.push_back(x);

    ll ans = 0;
    for (int i = 1; i < N; i++)
    {
        if (V[i] < V[i - 1])
        {
            ans += (V[i - 1] - V[i]);
            V[i] = V[i - 1];
        }
    }

    cout << ans << endl;

    return 0;
}