#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
// #define max(a,b,c) max(max(a,b),c) 
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main(){
    IOS
    w(t){
        ll n,e,h,a,b,c;
        cin>>n>>e>>h>>a>>b>>c;
        if(e < n && h < n){
            cout << -1;
        }
        else if (e >= n && h < n){
            if( (h + (e-h)/2) >= n ){

            }
            else cout << -1;
        }
        else if (e < n && h >= n){
            if( (e + (h-e)/3) >= n ){

            }
            else cout << -1;
        }
        else{
            
        }
    }
    return 0;
}