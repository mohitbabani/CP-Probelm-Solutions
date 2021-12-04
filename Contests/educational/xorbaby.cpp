#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(){
    int n;cin>>n;
    vector<ll> arr(n);
    ll total=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total ^= arr[i];
    }
    if(total == 0LL){
        cout << "YES\n";
        return;
    }
    vector<ll> pre(n,arr[0]),suf(n,arr[n-1]);
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1]^arr[i];
    }
    for(int i=n-2;i>=0;i--){
        suf[i] = suf[i+1]^arr[i];
    }
    for(int i=0;i<n;i++){
        if(pre[i] == total){
            for(int j=i+1;j<n-1;j++){
                if(pre[j] == 0 && suf[j+1] == total){
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}