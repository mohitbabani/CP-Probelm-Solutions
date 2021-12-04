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
        ll n,d;
        cin>>n>>d;
        vector<ll> r,nr;
        f(i,0,n) {
            ll age;cin>>age;
            if(age >= 80 || age <= 9) r.push_back(age);
            else nr.push_back(age);
        }
        ll ans = r.size()/d + nr.size()/d;
        if(r.size() % d != 0) ans++;
        if(nr.size() % d != 0) ans++;
        cout<<ans<<"\n";
    }
}