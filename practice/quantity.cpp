#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main(){
    w(t){
        ld q,p;
        ll temp = q;
        cin>>q>>p;
        if(q>1000)
        p = p*0.9;
        cout<<q*p<<"\n";
    }
    return 0;
}