#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n;cin>>n;
    vector<vector<int>> g(n+1);
    vector<int> level(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> v(n+1,false);
    queue<int> q;
    q.push(1);
    level[1]=0;
    while(q.size()){
        int x = q.front();
        q.pop();
        v[x] = true;
        for(int i: g[x]){
            if( !v[i] ){
                q.push(i);
                level[i] = level[x] + 1;
                v[i] = true;
            }
        }
    }
    ll even=0,odd=0;
    for(int i=1;i<=n;i++){
        if(level[i]%2) odd++;
        else even++;
    }
    ll ans = (even*odd) - (n-1);
    cout << ans << "\n"; 
}