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
ll isXpresent(ll x,vector<ll> v){
    f(i,0,v.size()){
        if(x == v[i])
        return i;
    }
    return 0;
}

int main(){
    IOS
    w(t){   
        ll n,x,p,k;
        cin>>n>>x>>p>>k;
        vector<ll> a(n,0);
        f(i,0,n)
        cin>>a[i];
        sort(a.begin(),a.end());
        if(k>p){
            if(a[p-1] < x)
            cout<<-1;
            else{
                ll cnt=0;
                while(a[p-1] != x){
                    a[k-1]=x;
                    cnt++;
                    sort(a.begin(),a.end());
                }
                cout<<cnt;
            }
        }
        else{
            if(a[p-1]<x)
            cout<<-1;
            else{
                ll cnt=0;
                while(a[p-1] != x){
                    a[k-1]=x;
                    cnt++;
                    sort(a.begin(),a.end());
                }
                cout<<cnt;
            }
        }
        cout<<"\n";
    }
    return 0;
}