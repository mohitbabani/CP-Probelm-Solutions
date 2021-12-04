#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define MAX 100
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main(){
    IOS
    w(t){
        ll n;
        cin>>n;
        vector<ll> v(n,0);
        bool temp=1;
        f(i,0,n)
        cin>>v[i];
        f(i,0,n){
            if(v[i] != i+1){
                if((i+1) % v[i] != 0){
                    temp=0;
                    break;
                }
            }
        }
        cout<<(temp == 1 ? Y : N);
    }
    return 0;
}