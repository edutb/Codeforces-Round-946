#include <bits/stdc++.h>

using namespace std;

void solve()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &v : nums)
        cin >> v;
    map<vector<int>, long long> start, mid, end, triple;

    long long ans = 0;

    for (int i = 0; i < n - 2; i++)
    {
        vector<int> s = {nums[i], nums[i + 1]};
        vector<int> m = {nums[i], nums[i + 2]};
        vector<int> e = {nums[i + 1], nums[i + 2]};
        vector<int> t = {nums[i], nums[i + 1], nums[i + 2]};

        ans += start[s] + mid[m] + end[e] - 3 * triple[t];
        start[s]++;
        mid[m]++;
        end[e]++;
        triple[t]++;
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