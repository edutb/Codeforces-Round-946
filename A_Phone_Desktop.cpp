#include <bits/stdc++.h>

using namespace std;

void solve()
{

    int x, y;
    int ans = 0;
    int space_remaining = 0;

    cin >> x >> y;
    ans = ceil(y / 2.0);
    space_remaining = (y & 1 ? (ans - 1) * 7 + 11 : ans * 7);
    if (space_remaining < x)
    {
        x -= space_remaining;
        ans += ceil(x / 15.0);
    }

    cout << ans << endl;
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