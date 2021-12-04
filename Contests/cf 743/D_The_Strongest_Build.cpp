#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define ll long long
#define piv pair<ll,vector<int>> 
int n,m;
vector<ll> a[11];
set<vector<int>> b;
set<vector<int>> vis;
priority_queue<piv> pq;
void Bfs(ll cost,vector<int> v){
    for(int i=0;i<n;i++){
        if(v[i] > 1){
            v[i]--;
            if(1){
                ll new_cost = cost + a[i][v[i]] - a[i][v[i]-1];
                pq.push({-new_cost,v});
                vis.insert(v);
            }
            v[i]++;
        }
    }
}
int main(){
    fast_io
    // <input>
    cin>>n;
    for(int i=0;i<n;i++){
        int sz;
        cin>>sz;
        for(int j=0;j<sz;j++){
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    cin>>m;
    while(m--){
        vector<int> v;
        for(int i=0;i<n;i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        b.insert(v);
    }
    // </input>
    vector<int> tmp;    
    for(int i=0;i<n;i++) tmp.push_back(a[i].size());
    pq.push({0LL,tmp});
    vis.insert(tmp);

    while(!pq.empty()){
        int cost = -pq.top().first;
        auto v = pq.top().second;
        pq.pop();
        if(b.find(v) == b.end()){
            for(int i: v) cout << i << ' ';
            cout << '\n';
            return 0;
        }
        Bfs(cost,v);
    }
    return 0;
}