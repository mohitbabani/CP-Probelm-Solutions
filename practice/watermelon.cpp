#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define N "NO\n"
#define Y "YES\n"
using namespace std;
int main(){
    w(t){
        ll n; cin>>n;
        vector<ll> v(n,0);
        ll sum=0;
        f(i,0,n){
        cin>>v[i];
        sum += v[i];
        }
        cout<<(sum < 0  ? N : Y );
    }
    return 0;
}