#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
vector<vector<int>> graph;
int n,m;
vector<int> GraphBFS(int start){
    bool vis[n];
    f(i,0,n) vis[i] = 0;

    queue<int> q;
    q.push(start);
    vis[start] = 1;
    vector<int> ans(1,start);

    while(q.size()){
        int current = q.front();
        q.pop();

        for(int it: graph[current]){
            if(vis[it] == 0){
                ans.push_back(it);
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return ans;
}
int main(){
    int start;
    cin >> n >> m >> start;
    graph.resize(n);
    f(i,0,m){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int> ans = GraphBFS(start);
    f(i,0,ans.size()) cout << ans[i] << ' ';
    return 0;
}