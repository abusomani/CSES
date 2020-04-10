#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Longest substring with only one character
int main()
{
    string s;
    cin >> s;
    int begin = 0, end = 0, ans = 0, N = s.size(), counter = 0;
    unordered_map<char, int> Mp;
    while (end < N)
    {
        Mp[s[end++]]++;
        if (Mp.size() > 1)
            counter++;
        while (counter)
        {
            Mp[s[begin++]]--;
            if (Mp[s[begin - 1]] == 0)
                Mp.erase(s[begin - 1]);
            if (Mp.size() <= 1)
                counter--;
        }
        ans = max(ans, end - begin);
    }
    cout << ans << endl;

    return 0;
}