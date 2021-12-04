#include<bits/stdc++.h>
using namespace std;
#define inf LONG_LONG_MAX
#define all(vec) vec.begin(),vec.end()
#define ll long long
#define ld long double
#define ull unsigned long long
#define w(t) long long t=1 ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;++i)
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
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll a = inf,b = -1; // first,last
    for(ll i=0;i<n;i++) if(s[i] == '*') a = min(a,i), b = max(b,i);
    if(b==a) {cout<<1<<"\n";return;}
    ll ans=inf;
    ll val=0;
    ll p=1;
    ll idx=-1;
    for(ll i=a+1;i<b;i++){
        if(s[i] == '*') idx = max(i,idx);
        if(p>=k){
            val++;
            p = i-idx;
        }
        p++;
    }
    ans = val+2;
    val = 0;
    p = 1;
    for(ll i=b-1;i>a;i--){
        if(s[i] == '*') idx = min(i,idx);
        if(p>=k){
            val++;
            p = idx-i;
        }
        p++;
    }
    cout << min(ans,val+2) << "\n";
}