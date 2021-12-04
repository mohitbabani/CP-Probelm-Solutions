#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 10;
vector<int> g[MAXN];
vector<int> level;
int n;
int pow2[MAXN];
void preReq(){
    int pow = 1;
    for(int i=1;i<MAXN;i++){
        if(pow*2 == i) pow <<= 1;
        pow2[i] = pow;
    }
}
void Dfs(int node,int par){
    for(auto i: g[node]){
        if(i != par){
            level[i] = level[node] + 1;
            Dfs(i,node);
        }
    }
}
void solve(){
    cin >> n;
    for(int i=0;i<n+5;i++) g[i].clear();
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    level.resize(n+1,-1);
    level[1] = 0;
    Dfs(1,0);
    int black = 0 , white = 0;
    int p = 0;
    for(int i=1;i<=n;i++){
        level[i] %= 2;
        if(level[i]) black++;
        else white++;
    }
    if(white > black){
        swap(white,black);
        p = 1;
    }
    int num = 1;
    vector<int> bitVal;
    while(white != 0){
        if(num & white){
            bitVal.push_back(num);
            white -= num;
        }
        num <<= 1;
    }
    vector<int> Color(n+1,1);
    int i = 1, j = 0;
    while(j < bitVal.size() && i <= n){
        if(pow2[i] != bitVal[j]){
            i++;
            continue;
        }
        while(bitVal[j]--){
            Color[i] = 0;
            i++;
        }
        j++;
    }
    vector<int> fillWhite, fillBlack;
    for(int i=1;i<=n;i++){
        if(Color[i]) fillBlack.push_back(i);
        else fillWhite.push_back(i);
    }
    vector<int> ans(n+1,0);
    int iw = 0, ib = 0;
    for(int i=1;i<=n;i++){
        if(level[i] == p){
            ans[i] = fillWhite[iw];
            iw++;
        }else{
            ans[i] = fillBlack[ib];
            ib++;
        }
    }
    for(int i=1;i<=n;i++) 
        cout << ans[i] << ' ';
    
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    preReq();
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}