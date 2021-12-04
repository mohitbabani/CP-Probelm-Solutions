#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> v(n+1,0);
    set<int> s;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        v[i] = x;
        s.insert(x);
    }
    if(s.size() == 1){
        cout << "NO\n";
        return;
    }
    vector<int> idx;
    set<pair<int,int>> sp;
    for(int i=1;i<=n;i++){
        int x = v[i];
        if(s.find(x) != s.end()){
            v[i] = -1;
            s.erase(x);
            idx.push_back(i);
            sp.insert({x,i});
        }
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<idx.size()-1;i++){
        ans.push_back({idx[i],idx[i+1]});
    }
    for(int i=1;i<n+1;i++){
        int x = v[i];
        if(x != -1){
            auto it = sp.begin();
            auto it2 = it;it2++;
            auto val1 = (*it).first;
            auto idx1 = (*it).second;
            auto val2 = (*it2).first;
            auto idx2 = (*it2).second;
            if(val1 != x){
                ans.push_back({i,idx1});
            }
            else{
                ans.push_back({i,idx2});
            }
        }
    }
    cout << "YES\n";
    for(auto i: ans){
        cout << i.first << " " << i.second << "\n";
    }
}
int main(){
    int t;cin>>t;
    while(t--) solve();
    return 0;
}