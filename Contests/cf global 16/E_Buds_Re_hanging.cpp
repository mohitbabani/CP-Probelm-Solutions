#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> bud;
void assign_bud(int node,int par){
    int ok = 0;
    for(auto i: g[node]){
        if(i != par){
            if(bud[i] == -1) assign_bud(i,node);
            if(bud[i] == 0) ok = 1;
        }
    }
    bud[node] = ok;
}
void solve(){
    int n;
    cin >> n;
    g.clear();
    g.resize(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n == 2) {cout << 1 << '\n'; return;}

    // for(int i=1;i<=n;i++) {
    //     for(auto j: g[i]) cout << j << ' ';
    //     cout << '\n';
    // }
    bud.clear();
    bud.resize(n+1,-1);

    assign_bud(1,-1);

    int ans = 1;
    for(int i=1;i<=n;i++) {
        // cout << bud[i] << ' ';
        // if(i == 1)
        if(bud[i] == 1) ans-=1;
        if(bud[i] == 0 && i != 1) ans+=1;
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}