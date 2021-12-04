#include"bits/stdc++.h"
using namespace std;
int n,m,c;
void dfs(int x,int y,vector<string> &graph,vector<vector<bool>> &vis){
    if(x < 0 or x >= n or y < 0 or y >= m or vis[x][y] or graph[x][y] == '0')
        return;
    vis[x][y] = 1;
    c++;
    dfs(x-1,y,graph,vis);
    dfs(x,y-1,graph,vis);
    dfs(x+1,y,graph,vis);
    dfs(x,y+1,graph,vis);
}
void solve(){
    cin>>n>>m;
    vector<string> graph(n);
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++) cin >> graph[i];
    vector<int> val;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                c=0;
                dfs(i,j,graph,vis);
                val.push_back(c);
            }
        }
    }
    sort(val.begin(),val.end(),greater<int>());
    int ans=0;
    for(int i=1; i<val.size(); i+=2){
        ans += val[i];
    }
    cout << ans << "\n";
}
int main(){
    int t;cin>>t;
    while(t--) solve();
    return 0;
}