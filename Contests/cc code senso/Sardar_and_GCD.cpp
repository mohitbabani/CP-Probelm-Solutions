#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
struct Tree{
    int n;
    vector<vector<int>> graph;
    vector<int> arr;
    vector<int> euler;
    vector<int> parent;
    vector<int> subgcd;
    vector<int> extra;
    Tree(int N,vector<vector<int>> g,vector<int> a){
        n = N;
        graph = g, arr = a;
        parent.resize(n+1); 
        subgcd.resize(n+1);
        extra.resize(n+1);
        Dfs(1,0);
        pre_req();
    }
    void Dfs(int node,int par){
        euler.push_back(node);
        parent[node] = par;
        subgcd[node] = arr[node];
        for(int i: graph[node]){
            if(i == par) continue;
            Dfs(i,node);
            subgcd[node] = __gcd(subgcd[node],subgcd[i]); 
            euler.push_back(node);
        }
    }
    void pre_req(){
        int N = euler.size();
        vector<int> start(n+1,-1), end(n+1,-1);
        for(int i=0;i<N;i++){
            end[euler[i]] = i;
            if(start[euler[i]] == -1) 
            start[euler[i]] = i;   
        }
        vector<int> pre(N), suf(N);
        for(int i=0;i<N;i++){
            if(i == 0) pre[i] = arr[euler[i]];
            else pre[i] = __gcd(pre[i-1],arr[euler[i]]);
        }
        for(int i=N-1;i>=0;i--){
            if(i == N-1) suf[i] = arr[euler[i]];
            else suf[i] = __gcd(suf[i+1],arr[euler[i]]);
        }
        for(int i=1;i<=n;i++){
            int temp = 0;
            if(start[i] != 0) 
                temp = __gcd(temp,pre[start[i]-1]);
            if(end[i] != N-1) 
                temp = __gcd(temp,suf[end[i]+1]);
            
            extra[i] = temp;
        }
    }
};
void solve(){
    int n;
    scanf("%d",&n);
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> a(n+1);
    for(int i=0;i<n;i++) scanf("%d",&a[i+1]);
    Tree obj(n,g,a);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll curr = obj.extra[i];
        for(int v: g[i]){
            if(v == obj.parent[i]) continue;
            curr += (ll)obj.subgcd[v];
        }
        ans = max(ans,curr);
    }
    printf("%lld\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}