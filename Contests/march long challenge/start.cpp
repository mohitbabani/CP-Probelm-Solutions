#include<bits/stdc++.h>
using namespace std;
#define YES cout << "YES\n" 
#define NO cout << "NO\n"
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
    cin>>n;
    vector<ll> x(n);
    f(i,0,n) cin >> x[i];
    ll ans = x[n-1];
    f(i,1,n){
        ll a = x[i] - (x[i-1]-1);
        if(a > 0) ans += a;
    }
    
}