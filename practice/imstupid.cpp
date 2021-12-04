#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define piii pair<int,pair<int,int>>
int n,m,k;
map<pii,vector<pii>> g;
int dijistra(){
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    map<pii,int> dis;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dis[{i,j}] = INT_MAX;
    dis[{1,1}] = 0;
    pq.push({0,{1,1}});
    while(!pq.empty()){
        pii u = pq.top().second;
        pq.pop();
        for(auto v: g[u]){
            if(dis[v] > dis[u] + 1){
                auto a = dis[v];
                dis[v] = dis[u] + 1;
                pq.push({dis[v],v});
            }
        }
    }

    return dis[{n,m}];
}
int main(){
    IOS
    cin >> n >> m >> k;
    vector<string> s(n+1);
    for(int i=1;i<=n;i++){
        // cin >> s[i];
        s[i] = string(m,'.');
        s[i] = 'x' + s[i];
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         g[{i,j}] = {};
    //     }
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j] == '.'){
                if(i > 1 && s[i-1][j] == '.') g[{i,j}].pb({i-1,j});
                if(i < n && s[i+1][j] == '.') g[{i,j}].pb({i+1,j});
                if(j > 1 && s[i][j-1] == '.') g[{i,j}].pb({i,j-1});
                if(j < m && s[i][j+1] == '.') g[{i,j}].pb({i,j+1});
            }
        }
    }
    int mn = dijistra();
    if(mn > k){
        cout << "No\n";
    }else{
        cout << "Yes\n";
    }
}