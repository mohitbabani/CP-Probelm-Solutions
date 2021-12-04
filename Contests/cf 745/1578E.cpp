#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve(){
    ll h,p;
    cin >> h >> p ;
    ll ans = 0;
    ll rem = 0;
    for(ll i=0;i<h;i++){
        ll val = (1LL << i);
        if(val <= p) ans++;
        else{
            rem += val;
        }
    }
    ans += rem / p;
    if(rem % p != 0) ans++;
    cout << ans << '\n';
}
int32_t main(){
    IOS
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}