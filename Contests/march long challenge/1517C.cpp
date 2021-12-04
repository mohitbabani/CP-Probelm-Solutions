#include"bits/stdc++.h"
using namespace std;
int n,val,cnt;
void dfs(int i,int j,vector<vector<int>> &graph){
    if(i >= n or j < 0 or graph[i][j] != 0 or cnt <= 0) return;
    graph[i][j] = val;
    cnt--;
    dfs(i,j-1,graph);
    dfs(i+1,j,graph);
}
int main(){
    cin>>n;
    vector<vector<int>> graph;
    for(int i=0;i<n;i++){
        vector<int> v(i,0);
        int x;cin>>x;
        v.push_back(x);
        graph.push_back(v);
    }
    for(int i=0;i<n;i++){
        val = cnt = graph[i][i];
        graph[i][i] = 0;
        dfs(i,i,graph);
    }
    for(auto i: graph){
        for(auto j: i){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}