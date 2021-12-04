#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define ld long double
#define ull unsigned long long
#define w(t) long long t=1 ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<endl
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
void solve();
int main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
// ANSWER IS FROM HERE //
void solve(){
    ll n;
    cin >> n;
    vector<ll> v;
    f(i,0,n) cin >> v[i];
    ll l,m,r;
    f(i,0,n-1){
        if(v[i] <= v[i+1]) break;
        l++;
    }
    for(ll i=n-2;i>=0;i--){
        if(v[i] <= v[i+1]) break;
        r++;
    }
    ll l_max = 0;
    
}