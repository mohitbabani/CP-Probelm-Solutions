#include"bits/stdc++.h"
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<string> s(n,string(n,'.'));
    for(int i=0;i<n;i++){
        s[i][i] = 'Q';
    }
    s[n-1][n-1] = s[n-3][n-3] = '.';
    for(int i=0;i<n;i++) cout << s[i] << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}