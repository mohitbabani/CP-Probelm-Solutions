#include"bits/stdc++.h"
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<n+1;i++) cin>>v[i];
    set<int> s;
    vector<int> ans(n+1);
    for(int i=1;i<n+1;i++){
        int x = v[i];
        if(s.find(i) == s.end()){
            vector<int> vec;
            vec.push_back(i);
            s.insert(i);
            int val = v[i];
            while(val != i){
                vec.push_back(val);
                s.insert(val);
                val = v[val];
            }
            for(auto i: vec){
                ans[i] = vec.size();
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " "; 
    }
    cout << "\n";
}
int main(){
    int q;cin>>q;
    while(q--) solve();
    return 0;
}