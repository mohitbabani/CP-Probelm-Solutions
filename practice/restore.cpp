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
int main(){
    w(t){
        ll n;cin>>n;
        vector<ll> b(n);
        f(i,0,n) cin>>b[i];
        ll x = INT_MAX;
        vector<ll> a(n);
        f(i,0,n) { a[i] = x; x--; }
        f(i,0,n) {
            if(b[i] != i+1) a[i] = a[ b[i]-1 ];
        } 
        f(i,0,n) cout<<a[i]<<" ";
        cout<<"\n";
    }
}