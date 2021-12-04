#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
using namespace std;
int main(){
    w(t){
        ll n,k,l;
        cin>>n>>k>>l;
        if(n <= (k*l)){
            if(k==1 && n==1)
            cout<<1;
            else if(k==1 && n>1)
            cout<<-1;
            else if(k>1)
            f(i,1,n+1){
                if(i%k != 0)
                cout<<i%k<<" ";
                else
                cout<<k<<" ";
            }
        }
        else 
        cout<<-1;
        cout<<"\n";
    }
}