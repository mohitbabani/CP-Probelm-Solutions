#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
using namespace std;
ll bwMul(ll x,ll y){
     ll t=0,a=1;
     while(x != 0 && y != 0){
         ll rem = (x%10) * (y%10);
         x /= 10; y /= 10;
         t = rem*a + t;
         a *= 10;
     }
     return t;
}
int main(){
    w(t){
        ll n;
        cin>>n;
        ll a[n];
        f(i,0,n)
        cin>>a[i];
        if(n==1)
        cout<<0<<endl;
        else{
        ll ans=0;
        f(i,0,n){
            f(j,i+1,n){
            ll temp=bwMul(a[i],a[j]);
            if(a[j] == temp)
            ans++;
            }
        }
        cout<<ans<<endl;
        }
    }
}
       
