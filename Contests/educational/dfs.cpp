#include<bits/stdc++.h>
using namespace std;
int nodeLevel(int V, vector<int> adj[], int X) 
	{
        if(X > V-1) return -1;
	    vector<int> visited(V+1,false);
	    vector<int> level(V+1,-1);
	    queue<int> q;
	    q.push(0);
	    level[0] = 0;
	    while(q.size()){
	        int x = q.front();
	        q.pop();
	        visited[x]=true;
	        for(auto i: adj[x]){
	            if(!visited[i]){
	                level[i] = level[x] + 1;
	                q.push(i);
	            }
	        }
	    }
	    return (level[X]);
	}
int main(){
    int V;cin>>V;
    int X;cin>>X;
    vector<int> graph[V];
    for(int i=0;i<V-1;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << nodeLevel(V,graph,X);
}