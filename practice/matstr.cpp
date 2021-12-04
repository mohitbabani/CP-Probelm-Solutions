#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

bool isPowerOfTwo(ll n) 
{ 
    if (n == 0) 
        return 0; 
    while (n != 1) 
    { 
        if (n%2 != 0) 
            return 0; 
        n = n/2; 
    } 
    return 1; 
}
ll search0(vector<ll> vec){
    f(i,0,vec.size())
    if(vec[i] == 0)
    return i;
}
int main(){
    IOS
    ll n;cin>>n;
    vector<ll> v(n);
    f(i,0,n)
    cin>>v[i];
    ll i;cin>>i;
    ll k = search0(v);
    while(1){
        if(v[i] == 0){cout<<"true"; break;}
        ll diff = i - v[i] , add = i + v[i];
        if(diff < 0 && add > n-1) {cout<<"false"; break;}
        if(diff < 0 && add <= n-1){i += v[i];}
        if(diff >= 0 && add > n-1){i -= v[i];}
        if(diff >=0 && add <= n-1){
            ll temp = min(abs(k-diff),abs(k-add));
            i = temp + k;
        }
    }
}