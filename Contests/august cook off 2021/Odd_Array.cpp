#include<bits/stdc++.h>
using namespace std;
#define _fast_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int findm(int n){
    int pw=0;
    while((1<<pw) <= n){
        ++pw;
    }
    return pw;
}
void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    int m = findm(n);
    vector<string> s = {"0","1"};
    int size = 1;
    while(size != m){
        vector<string> front,back;
        for(auto str: s){
            front.push_back("0"+str);
            back.push_back("1"+str);
        }
        for(int i=back.size()-1;i>=0;i--){
            front.push_back(back[i]);
        }
        s = front;
        size++;
    }
    vector<int> ans;
    for(int i=1;i<s.size();i++){
        for(int j=0;j<m;j++){
            if(s[i-1][j] != s[i][j]){
                ans.push_back(j+1);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int32_t main(){
    _fast_

    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}   