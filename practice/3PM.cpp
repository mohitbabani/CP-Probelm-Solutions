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
    IOS
    ll n,m;
    ld a,b;
    cin>>n>>m>>a>>b;
    ll ans;
    if(b/m < a){
        if( (n%m)*a < b )    ans = (n/m)*b + (n%m)*a;
        else ans = ( (n/m)+1 ) * b ;
    }
    else
        ans = a*n;
        
    cout<<ans;
    return 0;
}