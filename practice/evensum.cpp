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
    w(t){
        ll a,b;
        cin>>a>>b;
        ll evenA = a/2, evenB = b/2;
        ll oddA = a - evenA, oddB = b - evenB;
        ll ans = (evenA * evenB) + (oddA * oddB) ;
        cout<<ans<<"\n";
    }
    return 0;
}