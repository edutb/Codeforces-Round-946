#include <bits/stdc++.h>

using namespace std;

void solve()
{

    int n;
    string s, r;
    vector<char> encode(26);

    cin >> n;
    cin >> s;
    r = s;
    sort(r.begin(), r.end());
    auto it = unique(r.begin(), r.end());
    r.resize(distance(r.begin(), it));

    int m = r.size();

    for (int i = 0; i <= m / 2; i++)
    {
        encode[r[i] - 'a'] = r[m - i - 1];
        encode[r[m - i - 1] - 'a'] = r[i];
    }

    for (auto &c : s)
        c = encode[c - 'a'];
    cout << s << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}