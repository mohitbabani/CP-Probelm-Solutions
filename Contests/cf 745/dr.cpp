#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,d;
    cin >> n >> d;
    ll f = n;
    while(1){
        ll temp = f;
        bool nf = 1; //
        ll fac = 1;
        while(temp != 0){
            ll rem = temp % 10;
            if(rem == d) {
                f = (temp+1)*fac;
                nf = 0;
            }
            temp /= 10;
            fac *= 10;
        }
        if(nf) break;
    }
    ll ans = f - n;
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
