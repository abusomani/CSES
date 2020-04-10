#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Permutation from 1 to N, no adjacent numbers
int main()
{
    int N;
    cin >> N;
    if (N == 1)
        cout << 1 << endl;
    else if (N <= 3)
        cout << "NO SOLUTION" << endl;
    else
    {
        int i = 1, j = (N >> 1) + 1, cnt = 0;
        while (cnt < N)
        {
            if (cnt & 1)
                cout << i++ << " ";
            else
                cout << j++ << " ";
            cnt++;
        }
    }
    return 0;
}