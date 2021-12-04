#include"bits/stdc++.h"
using namespace std;
void solve(){
    string s;
    cin>>s;
    s = "R" + s + "R";
    int cnt = 0;
    int mx=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'L'){
            cnt++;
            if(s[i] == s[i+1]) continue;
            else mx = max(cnt,mx);
        }
        else{
            cnt=0;
        }
    }
    cout << mx+1 << "\n";
}
int main(){
    int t;cin>>t;
    while(t--) solve();
    return 0;
}