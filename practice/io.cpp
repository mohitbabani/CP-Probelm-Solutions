#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main(){
    ll n,k;
    cin>>n>>k;
    ll count=0;
    f(i,0,n){
    ll x;
    cin>>x;
    if(x%3==0)
    count++;
    }
    cout<<count;
    return 0;
}