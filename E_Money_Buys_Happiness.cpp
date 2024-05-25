#include <bits/stdc++.h>

using namespace std;

int n;
long long salary;
int maxHappinnes;
vector<int> c, h;

long long memo[51][100001];

long long f(int i, int j)
{
    if (j <= 0)
        return 0;
    if (i < 0)
        return 1e11;
    if (memo[i][j] != -1)
        return memo[i][j];
    long long ans = f(i - 1, j);
    if (i * salary >= c[i] + f(i - 1, j - h[i]))
        ans = min(ans, f(i - 1, j - h[i]) + c[i]);
    return memo[i][j] = ans;
}

void solve()
{

    cin >> n >> salary;
    memset(memo, -1, sizeof memo);
    c.assign(n, 0);
    h.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> c[i] >> h[i];

    maxHappinnes = accumulate(h.begin(), h.end(), 0);

    for (int j = maxHappinnes; j > 0; j--)
    {
        if (f(n - 1, j) <= salary * (n - 1))
        {
            cout << j << endl;
            return;
        }
    }

    cout << 0 << endl;
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