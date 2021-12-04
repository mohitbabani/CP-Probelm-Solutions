#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//#define int long long
using pii = pair<int,int>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;
#define all(arr) arr.begin(), arr.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1e16
class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    int n;
    bool is_cyclic(int node){
        if(vis[node] == 2) return true;
        
        vis[node] = 2;
        for(int i: g[node]){
            if(vis[i] != 1){
                if(is_cyclic(i)) return true;
            }
        }
        vis[node] = 1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        this->n = numCourses;
        g.resize(n);
        for(auto v: prerequisites){
            g[v[0]].push_back(v[1]);
        }
        vis.resize(n,0);
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                if(is_cyclic(i))
                    return false;
            }
        }
        return true;
    }
};
void solve(){
    vector<vector<int>> pre ={
        {0,1},
        {1,2},
        {2,3}
    };
    Solution obj;
    obj.canFinish(4,pre) ? cout << "YES" : cout << "NO";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t t = 1;
    // cin >> t;
    for(int32_t test=1;test<=t;test++){
        solve();
    }
    return 0;
}