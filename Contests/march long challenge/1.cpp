#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
// #define max(a,b,c) max(max(a,b),c) 
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main(){
    IOS
    ll n,h,x;
    cin>>n>>h>>x;
    ll t[n];
    ll MAX = 0;
    f(i,0,n) {
        cin>>t[i];
        MAX = max(MAX,t[i]);
    }
    (MAX + x) >= h ? cout << Y : cout << N;  
}