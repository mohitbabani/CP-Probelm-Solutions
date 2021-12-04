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
        vector<ll> a(n);f(i,0,n) cin>>a[i];
        sort(a.begin(),a.end());

        ll ans=INT_MAX;       
        f(i,0,n-1)
        
        ans = min( ans, a[i]^a[i+1] );

        cout<<ans<<"\n";
    }
    return 0;
}