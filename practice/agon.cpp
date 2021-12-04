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
ll F(ll x,vector<ll> vec){
    ll n = vec.size();
    for(ll z = x+1 ; z < n ; z++) {
        if(vec[x] < vec[z]) { return z; }
    }
    return -1;
}
ll G(ll x,vector<ll> vec){
    if(x == -1) return -1;
    ll n = vec.size();
    for(ll z = x+1 ; z < n ; z++) {
        if(vec[x] > vec[z]) return z;
    }
    return -1;
}

int main(){
    ll n; cin>>n;
    
    vector<ll> a(n); f(i,0,n) cin>>a[i];

    f(i,0,n){
        
        if(G (F(i,a) , a) != -1) cout << a[G (F(i,a) , a)] << " "; 
        
        else cout << -1 << " ";
    
    }
    return 0;
}