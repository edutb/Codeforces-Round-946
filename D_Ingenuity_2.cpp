#include <bits/stdc++.h>

using namespace std;

void solve()
{
   int n;
   string s;
   unordered_map<char, int> dir;

   cin >> n;
   cin >> s;
   for (auto &c : s)
      dir[c]++;

   int y = abs(dir['N'] - dir['S']);
   int x = abs(dir['E'] - dir['W']);

   if (x & 1 || y & 1)
   {
      cout << "NO" << endl;
      return;
   }

   bool onevehicle = false;
   if (min(dir['N'], dir['S']) == 1)
   {
      onevehicle = true;
   }
   int roverN = ceil(min(dir['N'], dir['S']) * (onevehicle ? 1 : 0.5)) + (dir['N'] >= dir['S'] ? y / 2 : 0);
   int roverS = ceil(min(dir['N'], dir['S']) * (onevehicle ? 1 : 0.5)) + (dir['S'] > dir['N'] ? y / 2 : 0);

   onevehicle = false;
   if (min(dir['E'], dir['W']) == 1)
      onevehicle = true;
   bool usedRover = (roverN + roverS > 0);
   int roverE = ceil(min(dir['E'], dir['W']) * (onevehicle && !usedRover ? 1 : (onevehicle ? 0 : 0.5))) + (dir['E'] >= dir['W'] ? x / 2 : 0);
   int roverW = ceil(min(dir['E'], dir['W']) * (onevehicle && !usedRover ? 1 : (onevehicle ? 0 : 0.5))) + (dir['W'] > dir['E'] ? x / 2 : 0);

   if (roverN + roverS + roverE + roverW == n)
   {
      cout << "NO" << endl;
      return;
   }

   string ans(n, 'H');
   for (int i = 0; i < n; i++)
   {
      if (s[i] == 'N' && roverN)
         ans[i] = 'R', roverN--;
      else if (s[i] == 'S' && roverS)
         ans[i] = 'R', roverS--;
      else if (s[i] == 'E' && roverE)
         ans[i] = 'R', roverE--;
      else if (s[i] == 'W' && roverW)
         ans[i] = 'R', roverW--;
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