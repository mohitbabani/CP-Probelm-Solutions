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
    ll n,d;
    cin>>n>>d;
    vector<ll> a(n);
    f(i,0,n) cin>>a[i];
    d = d % n;
    f(i,0,n) cout<<a[(i+d) % n]<<" ";
    return 0;
}