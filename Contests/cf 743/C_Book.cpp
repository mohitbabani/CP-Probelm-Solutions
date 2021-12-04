#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
class Tree{
    public:
    vector<vector<int>> g;
    vector<int> mn;
    int n;
    Tree(int n){
        this->n = n;
        g.resize(n+1,vector<int>());
        mn.resize(n+1,-1);
    }
    void add_edge(int u,int v){
        g[u].pb(v);
    }
    void dfs(int node){
        if(g[node].size() == 0) {
            mn[node] = 1;
            return;
        }
        int mx = -1;
        for(auto i: g[node]){
            if(mn[i] == -1) dfs(i);
            int c = mn[i];
            if(i > node) c++;
            mx = max(mx,c);
        }
        mn[node] = mx;
    }
    bool is_cyclic_util(int v,bool visited[],bool recStack[]){
        if(visited[v] == false){

            visited[v] = recStack[v] = true;

            for(auto i: g[v]){
                if(!visited[i] && is_cyclic_util(i,visited,recStack))
                    return true;
                else if(recStack[i])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }
    bool is_cyclic(){
        bool visited[n+1],recStack[n+1];
        memset(visited,0,sizeof(visited));
        memset(recStack,0,sizeof(recStack));

        for(int i=1;i<=n;i++){
            if(is_cyclic_util(i,visited,recStack))
                return true;
        }
        return false;
    }
};
void solve(){
    int n;
    cin >> n;
    Tree tree(n);
    for(int u=1;u<=n;u++){
        int m;cin>>m;
        while(m--){
            int v;cin>>v;
            tree.add_edge(u,v);
        }
    }
    if(tree.is_cyclic()){
        cout << -1 << '\n';
        return;
    }
    int ans = -1;
    for(int i=1;i<=n;i++){
        if(tree.mn[i] == -1) tree.dfs(i);
        ans = max(ans,tree.mn[i]);
    }
    cout << ans << '\n';
}
int32_t main(){
    IOS
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}