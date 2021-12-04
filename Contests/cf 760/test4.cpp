#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(bool vis[],vector<int> adj[],int idx,stack<int>& stk){
	    vis[idx] = true;
	    
	    for(auto i: adj[idx]){
	        if(vis[i] == false) dfs(vis,adj,i,stk);
	    }
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    bool *vis;
        vis = new bool[V];
	    for(int i=0;i<V;i++) vis[i] = false;
	    stack<int> stk;
	    
	    for(int i=0;i<V;i++)
	        if(vis[i] == false)
	            dfs(vis,adj,i,stk);
	   
	   vector<int> ans;
	   while(stk.size()){
	       ans.push_back(stk.top());
	       stk.pop();
	   }
	   return ans;
	}
};
void print(vector<int> v){
    for(int i: v) cout << i << ' ';
    cout << '\n';
}
vector<int> ans;
int n,m;
vector<vector<int>> graph;
vector<bool> vis;
void dfs(int node){
    vis[node] = true;
    ans.push_back(node);
    for(auto v: graph[node]){
        if(vis[v] == false) dfs(v);
    }
}
vector<int> bfs(){
    bool *visited = new bool[n+1];
    for(int i=0;i<n;i++) visited[i] = false;

    queue<int> q;
    q.push(1);

    while(q.size()){
        int x = q.front();
        q.pop();
        visited[x] = true;
        ans.push_back(x);
        for(auto i: graph[x]){
            if(visited[i] == false) q.push(i); 
        }
    }
    return ans;
}
int main(){
    cin >> n >> m;
    graph.resize(n+1,vector<int>());
    vis.resize(n+1,false);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // dfs(1);
    bfs();
    for(int i: ans) cout << i << ' ';
}
/*
int main(){
    int e,v;
    cin >> e >> v;
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Solution obj;
    auto ans = obj.topoSort(v,adj);
    print(ans);
}
*/