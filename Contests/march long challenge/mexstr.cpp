#include"bits/stdc++.h"
using namespace std;
#define ll long long int
#define inf 1e17
void solve(){
    string s;
    cin>>s;
    ll n = s.length();
    vector<ll> next0(n,inf),next1(n,inf);
    ll n0,n1;
    n0=n1=inf;
    for(ll i=n-1;i>=0;i--){
        next0[i] = n0;
        next1[i] = n1;
        if(s[i] == '1') n1 = i;
        else n0 = i;
    }
    if(n0 == inf){
        cout << 0 << "\n";
        return;
    }
    if(n1 == inf){
        cout << 1 << "\n";
        return;
    }
    vector<ll> len(n);
    bool one,zero;
    one=zero=false;
    ll cnt=0;
    for(ll i=n-1;i>=0;i--){
        len[i] = cnt;
        if(s[i]=='1') one = true;
        else zero = true;
        if(one && zero) cnt+=1,one=zero=false; 
    }
    string res = "";
    ll curr = n1;
    while(1){
        res.push_back(s[curr]);
        ll p0 = next0[curr];
        ll p1 = next1[curr];
        if(p0 == inf) {res.push_back('0');break;}
        if(p1 == inf) {res.push_back('1');break;}
        if(len[p0] <= len[p1]){
            curr = p0;
        }
        else curr = p1;
    }
    cout << res << "\n";
}
int main(){
    ll t=1;cin>>t;
    for(ll i=0;i<t;i++) solve();
    return 0;
}