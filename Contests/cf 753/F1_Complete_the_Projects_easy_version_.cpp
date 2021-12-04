#include"bits/stdc++.h"
using namespace std;
using pii = pair<int,int>;
int n, r;
vector<pii> replace(int idx,vector<pii> arr){
    vector<pii> res;
    for(int i=0;i<arr.size();i++) 
        if(i != idx) res.push_back(arr[i]);
    return res;
}
map<pair<int,vector<pii>>,bool> mp;
bool fun(int rem,vector<pii> arr){
    if(mp.find({rem,arr}) != mp.end()) return mp[{rem,arr}];
    if(arr.size() == 0) {
        return true;
    }
    bool res = false;
    for(int i=0;i<arr.size();i++){
        pii p = arr[i];
        if(rem >= p.first && rem+p.second >= 0){
            res |= fun(rem+p.second,replace(i,arr));
        }
    }
    mp[{rem,arr}] = res;
    return res;
}
void solve(){
    cin >> n >> r;
    vector<pii> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr.push_back({a,b});
    }
    bool ans;
    ans = fun(r,arr);
    if(ans){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}