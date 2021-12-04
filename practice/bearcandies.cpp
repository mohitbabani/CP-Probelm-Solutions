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
        ll a,b;
        cin>>a>>b;
        ll i=1,j=2;
        string winner;
        while(a>=0 && b>=0){
            a -= i;
            if(a<0){ winner="Bob"; break;}
            b -= j;
            if(b<0){ winner="Limak"; break;}
            i += 2;
            j += 2;
        }
        cout<<winner<<"\n";
    }
    return 0;
}