#include<bits/stdc++.h>
#define ll long long
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,n) for(ll i=0;i<n;i++)
using namespace std;
int main(){
    w(t){
        ll n,k;
        cin>>n>>k;
        vector<ll> v;
        set<ll> s;
        f(i,n){
            ll x;
            cin>>x;
            v.push_back(x);
            s.insert(x);
        }
        ll rfm = v.size() - s.size() + 1 ;
        set<ll> e;
        for(int i=1;i<=rfm;i++){
            ll eff = (i*k) + (rfm+1) - i;
            e.insert(eff);
        }
        auto itr = e.begin();
        cout<<*itr<<"\n";       
    }
}