#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//#define int long long
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;
#define all(arr) arr.begin(), arr.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1e16

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> g[n+5];
    vector<int> deg(n+1,0);
    f(i,0,n-1){
        int u,v;
        cin >> u >> v;
        deg[u]++; deg[v]++;
        g[u].pb(v); g[v].pb(u);
    }
    vector<bool> vis(n+1,0);
    set<pii> s;
    f(i,1,n+1) {
        s.insert({deg[i],i});
    }
    while(s.size()){
        if(k <= 0) break;
        auto it = s.begin();
        vector<int> temp;

        if(it->first == 0){
            cout << "0\n";
            return;
        }
        while(it -> first == 1){
            vis[it -> second] = 1;
            temp.pb(it->second);
            s.erase(it);
            it = s.begin();
        }

        for(int i: temp){
            for(int j: g[i]){
                if(!vis[j]){
                    s.erase({deg[j],j});
                    
                    deg[j] -= 1;
                    
                    if(deg[j] >= 0)
                        s.insert({deg[j],j});
                }
            }
        }

        k -= 1;
    }

    cout << s.size() << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    for(int test=1;test<=t;test++){
        solve();
    }
    return 0;
}