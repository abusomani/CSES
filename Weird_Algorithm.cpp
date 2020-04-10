#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll N;
    cin >> N;
    while (true)
    {
        cout << N << " ";
        if (N == 1)
            break;
        N = (N & 1) ? 3 * N + 1 : N / 2;
    }
    return 0;
}