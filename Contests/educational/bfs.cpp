#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<vector<int>> graph(n+1);
    vector<int> parent(n+1,-1);
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        parent[i] = x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
    vector<int> level(n+1,0);
    queue<int> q;
    q.push(1);
    level[1]=0;
    while(q.size()){
        int x = q.front();
        q.pop();
        for(auto i: graph[x]){
            if(i != parent[x]){
                level[i] = level[x] + 1;
                q.push(i);
            }
        }
    }
    vector<int> count(n+1,0);
    for(int i=1;i<=n;i++){
        if(level[i] != NULL) count[level[i]]++;
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans += count[i] % 2;
    }
    cout << ans << "\n";
    return 0;
}