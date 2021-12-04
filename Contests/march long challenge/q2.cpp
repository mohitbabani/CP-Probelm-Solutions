#include"bits/stdc++.h"
using namespace std;
#define ll long long int
ll answer(vector<ll> vec){
    ll f=1,ans=0;
    for(ll i=0;i<32;i++){
        if(vec[i]) ans += f;
        f*=2;
    }
    return ans;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    vector<ll> dp(32,0);
    for(int i=0;i<n;i++){
        ll x;cin>>x;arr[i]=x;
        ll p=0;
        while(x){
            if(x%2) dp[p]++;
            x/=2;
            p++;
        }
    }
    vector<ll> ans(q+1);
    ans[0] = answer(dp);
    for(ll i=0;i<q;i++){
        ll x,v;
        cin>>x>>v;
        ll temp = arr[x-1];
        arr[x-1] = v;
        ll p = 0;
        while(temp){
            if(temp%2) dp[p]--;
            temp/=2;
            p++;
        }
        temp = v;
        p = 0;
        while(temp){
            if(temp%2) dp[p]++;
            temp/=2;
            p++;
        }
        ans[i+1] = answer(dp);
    }
    for(ll i=0;i<=q;i++){
        cout << ans[i] << "\n";
    }
}
int main(){
    int t=1;cin>>t;
    for(int i=0;i<t;i++) solve();
    return 0;
}