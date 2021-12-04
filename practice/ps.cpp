#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
bool is_prime(ll n){
    if (n == 0 || n == 1)  return 0;
    else {
        for (ll i = 2; i <= n / 2; ++i) 
            if (n % i == 0) return 0;
    }
    return 1;
}
int main(){
    w(t){
        string s;
        cin>>s;
        unordered_map<char,ll> m;
        for(ll i=0; s[i] ; i++){
            if(m.find(s[i]) == m.end()) { m.insert(make_pair(s[i],1)); }
            else m[s[i]]++;
        }
        ll ans = 0;
        if(  ! is_prime ( m.size() )  ) cout<<N;
        else {
            for(auto& it : m) {
                if( is_prime(it.second) ) ans = 1;
                else {ans =0 ; break ;}
                }
            ans == 1 ? cout<<Y : cout<<N ;
        }
    }
    return 0;
}