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
    ll n; cin>>n;
    vector<ll> a(n);
    ll sum=0,maxEven=0,maxOdd=0,mei,moi;
    f(i,0,n){
        cin>>a[i];
        sum += a[i];
        if(a[i]%2 == 0){
            if(maxEven < a[i])
            maxEven = a[i];
            mei = i;
        }
        else{
            if(maxOdd < a[i])
            maxOdd = a[i];
            moi = i;
        }
    }
    if(sum%2 == 0 && maxEven != 0 ){
        a[mei] = 0;
        sum -= maxEven;
        ll temp = 0;
        f(i,0,n){
            if(temp == sum){
            cout<<Y;
            break;
            }
            temp += a[i];
            sum -= a[i];
        }
    }
    return 0;
}










