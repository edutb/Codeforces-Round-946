#include <bits/stdc++.h>

using namespace std;



void solve()
{
    int n, salary;
    cin >> n >> salary;
    vector<int> cost(n, 0);
    for (auto &v : cost)
        cin >> v;
    priority_queue<int> pq;
    int budget = 0;
    int ans = 0;

    for (auto &c : cost)
    {
        if (c <= budget)
        {
            pq.push(c);
            budget -= c;
            ans += 1;
        }
        else if (pq.size() && pq.top() > c)
        {
            budget += pq.top();
            pq.pop();
            budget -= c;
            pq.push(c);
        }
        budget += salary;
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