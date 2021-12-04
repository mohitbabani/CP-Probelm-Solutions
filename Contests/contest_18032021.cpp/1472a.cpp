#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    ll w,h,n;
    cin >> w >> h >> n;
    ll ans = 1;
    while(w > 0){
        if(w%2 == 1) break;
        w /= 2;
        ans *= 2;
    }
    while(h > 0){
        if(h%2 == 1) break;
        h /= 2;
        ans *= 2;
    }
    if(ans >= n) {cout << "YES\n"; return;}
    cout << "NO\n"; 
}