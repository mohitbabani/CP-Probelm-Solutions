#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define pb push_back
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n*m);
    for(int i=0;i<n*m;i++) cin >> a[i];
    auto b = a;
    sort(b.begin(),b.end());

    int pos[n][m];
    map<int,vector<pii>> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            pos[i][j] = b[m*i+j];
            mp[pos[i][j]].pb({i,j});
            // cout << pos[i][j] << ' ';
        }
        // cout << '\n';
    }
    map<int,queue<pii>> idx;
    for(auto p: mp){
        int x = p.first;
        auto v = p.second;
        vector<vector<pii>> vv;
        vector<pii> temp(1,v[0]);
        for(int i=1;i<v.size();i++){
            if(v[i].first != v[i-1].first){
                vv.pb(temp);
                temp = vector<pii>(1,v[i]);
            }else{
                temp.pb(v[i]);
            }
        }
        vv.pb(temp);
        queue<pii> nv;
        for(auto vec: vv){
            for(int i=vec.size()-1;i>=0;i--){
                nv.push(vec[i]);
            }
        }
        idx[x] = nv; 
    }
    int occ[n][m];
    memset(occ,0,sizeof(occ));
    // cout << '\n';
    int ans = 0;
    for(int val: a){
        auto p = idx[val].front();
        idx[val].pop();
        int i = p.first;
        int j = p.second;
        for(int k=0;k<j;k++){
            ans += occ[i][k];
        }
        occ[i][j] = 1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout << occ[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    cout << ans << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}