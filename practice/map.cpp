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
int main(){
    IOS
    w(t){
        ll n,m;
        cin>>n>>m;
        ll a[n][m];
        f(i,0,n){
            f(j,0,m){
                cin>>a[i][j];
            }
        }

        char str[n+m-1];
        f(i,0,n+m-1)
        cin>>str[i];

        ll cnt=0;

        f(i,0,n){
            f(j,0,m){
                if( (str[i+j] == '1' && a[i][j] == 1) || (str[i+j] == '0' && a[i][j] == 0) ){
                    cnt++;
                }
            }
        }

        cout<<cnt;
    }
}