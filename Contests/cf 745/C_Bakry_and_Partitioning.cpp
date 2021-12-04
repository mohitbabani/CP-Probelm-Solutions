#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define ld long double
#define pb push_back
#define all(vec) vec.begin(),vec.end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


#define yes() cout << "YES\n" 
#define no() cout << "NO\n"
vector<ll> dis;
vector<vector<ll>> g;
vector<ll> a;
vector<ll> par;
vector<ll> level;
ll x;
int dfs(ll node,ll parent){
    ll X = a[node];
    for(auto i: g[node]){
        if(i != parent && i != -1){
            if(dfs(i,node)) return i;
            X = dis[i] ^ X;
        }
    }
    dis[node] = X;
    if(X == x){
        for(auto &i: g[node]) if(i == parent) i = -1;
        for(auto &i: g[parent]) if(i == node) i = -1;
        return node;
    }
    return 0;
}
void solve(){
    ll n,k;
    cin >> n >> k;
    a.resize(n+1);
    g.resize(n+1);
    dis.resize(n+1);
    par.resize(n+1);
    level.resize(n+1);
    x = 0;
    f(i,1,n+1) {
        cin >> a[i];
        dis[i] = a[i];
        x = x ^ a[i];
    }
    f(i,0,n-1){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(x == 0) {
        yes();
        return;
    }
    if(k == 2){
        no();
        return;
    }
    int node = dfs(1,-1);
    if(node == 1){
        no();
        return;
    }
    node = dfs(1,-1);
    if(node == 1){
        no();
        return;
    }
    yes();
}
// k - 1 edges delete only
int32_t main(){
    IOS
    int t = 1;
    cin >> t;
    while(t--){
        dis.clear();
        g.clear();
        a.clear();
        par.clear();
        level.clear();
        solve();
    }
    return 0;
}