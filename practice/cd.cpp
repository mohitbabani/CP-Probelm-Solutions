#include<bits/stdc++.h>
#define ll long long
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,n) for(ll i=0;i<n;i++)
using namespace std;
ll soi(ll x){
    ll soi;
    if(x%9 == 0)
    soi = x/9;
    else
    soi = (x/9) + 1;
    return soi;
}
int main (){
    w(t){
        ll pc,pr;
        cin>>pc>>pr;
        if(soi(pc)<soi(pr))
        cout<<0<<" "<<soi(pc)<<"\n";
        else
        cout<<1<<" "<<soi(pr)<<"\n";
    }
}