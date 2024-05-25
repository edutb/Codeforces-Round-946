#include<bits/stdc++.h>

using namespace std;

set< pair<int, int> > selected_points;

int earned_points(int& position, int qtd, deque< pair<int, int> >& points, bool x, bool first){

    int ans = 0;
    int cut = (first ? position + qtd: position - qtd);

    if(first){
        while(points.size() && points[0].first < cut){
            if(!x) swap(points[0].first, points[0].second);
            if(selected_points.find(points[0]) == selected_points.end()){
                selected_points.insert(points[0]);
                ans++;
            }
            points.pop_front();
        }
    }
    else{
        while(points.size() && points.back().first > cut){
            if(!x) swap(points.back().first, points.back().second);
            if(selected_points.find(points.back()) == selected_points.end()){
                selected_points.insert(points.back());
                ans++;
            }
            points.pop_back();
        }
    }
    
    position = cut;
    return ans;
}

void solve(){
    
    int n, m, k, q;
    cin>>n>>m>>k>>q;
    
    int x_a, x_b, y_a, y_b;
    x_a = 1, x_b = n;
    y_a = 1, y_b = m;
    char move;
    int qtd, turn = 0;
    int x, y;

    selected_points.clear();
    deque< pair<int, int> > points_x;
    deque< pair<int, int> > points_y;

    for(int i = 0; i < k; i++){
        cin>>x>>y;
        points_x.push_back({x, y});
        points_y.push_back({y, x});
    }

    sort(points_x.begin(), points_x.end());
    sort(points_y.begin(), points_y.end());

    int alice = 0, bob = 0;
    int p;

    while(q--){
        cin.ignore();
        cin>>move>>qtd;
        if(move == 'U') p = earned_points(x_a, qtd, points_x, 0, 1);
        else if(move == 'D') p = earned_points(x_b, qtd, points_x, 0, 0);
        else if(move == 'L') p = earned_points(y_a, qtd, points_y, 1, 1);
        else p = earned_points(y_b, qtd, points_y, 1, 0);
        
        if(turn&1) bob+=p;
        else alice+=p;
        turn++;
    } 

    cout<<alice<<" "<<bob<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
 
    return 0;
}