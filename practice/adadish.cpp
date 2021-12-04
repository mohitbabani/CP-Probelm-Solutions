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
    w(t){
        ll n;cin>>n;
        vector<ll> c(n);
        ll s=0,MX=0,MN=INT_MAX;
        f(i,0,n){
        cin>>c[i];
        s += c[i];
        MX = max(MX,c[i]);
        MN = min(MN,c[i]);
        }
        if(n==1) cout<<c[0]; 
        else if(n==2) cout<<max(c[0],c[1]);
        else if(n==3) cout<<max(MX,s-MX);
        else {
        ll a = MX + MN;
        ll b = s - a;
        if(MX == max(MX,s-MX)) cout<<MX;
        else cout<<max(a,b);
        }
        cout<<"\n";
    }
    return 0;
}