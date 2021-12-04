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
    
    ll n;cin>>n;
    vector<ll> arr(n); f(i,0,n) cin>>arr[i];
    sort(arr.begin(),arr.end());

    if(n % 2 != 0){
        cout<<arr[n/2];
    }
    else{
        cout<<max(arr[n/2],arr[n/2 - 1]);
    }
    return 0;
}