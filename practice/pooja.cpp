#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,n) for(ll i=0;i<n;i++)
using namespace std;
int main(){
    ld x,y;
    cin>>x>>y;
    ll temp=x;
    if((y-x)>=0.5 && temp%5 == 0){
        cout<<y-x-0.5;
    }
    else 
    cout<<y;
    return 0;
}