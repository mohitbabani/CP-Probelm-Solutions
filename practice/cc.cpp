#include<bits/stdc++.h>
#define ll long long
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,n) for(ll i=0;i<n;i++)
using namespace std;
int main(){
    w(t){
        ll n,k;
        cin>>n>>k;
        vector<ll> p;
        f(i,n){
        ll x;
        cin>>x;
        p.push_back(x);}
        set<ll> s;
        f(i,n){
            if(k%p[i]==0)
            s.insert(k/p[i]-1);
        }
        if(s.empty())
        cout<<-1<<endl;
        else{
            auto itr = s.begin();
            cout<<k/(*itr+1)<<endl;
        }
    }
    return 0;
}