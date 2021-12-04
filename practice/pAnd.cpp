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
void printSeq(ll n){
    vector<ll> v(n,0);
    f(i,0,n)
    v[i]=i+1;
    ll d=1;
    ll i=0;
    while(i<n-1){
        swap(v[i],v[i+1]);
        i += d;
        d *= 2;
    }
    f(i,0,n)
    cout<<v[i]<<" ";
}
bool isPowerOfTwo(ll n) {
    if(n==1)
    return 0;
    while (n != 1) { 
        if (n%2 != 0) 
            return 0; 
        n = n/2; 
    } 
    return 1; 
}
int main(){
    IOS
    w(t){
        ll n;cin>>n;
        if( isPowerOfTwo(n) )
        cout<<-1;
        else{
            printSeq(n);
        }
        cout<<"\n";
    }
    return 0;
}