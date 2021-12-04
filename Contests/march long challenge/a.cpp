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
    ll n,m,s,k;
    cin>>n>>m>>s>>k;
    vector<pair<ll,ll>>  uv(m);
    f(i,0,m) cin >> uv[i].first >> uv[i].second;
    vector<ll> a(s);
    f(i,0,s) cin >> a[i];
    sort(all(a));
    map<ll,vector<ll>> map;
    f(i,0,m){
        pair<ll,ll> p = uv[i];
        ll f = p.first;
        ll s = p.second;
        if(binary_search(all(a),s)) map[f].push_back(s);
    }
    ll lvl = 1;
    ll ans = 0;
    ll rem = k;
    for(auto x : map){
        auto a = x.first;
        auto vec = x.second;
        if(vec.size() >= rem){
            ans += rem*lvl;
            rem = 0;
            break;
        }
        ans += vec.size()*lvl;
        rem -= vec.size();
        for(auto i : vec){
            if(map[i].size() >= rem){
                ans += map[i].size()*(lvl+1);
                rem = 0;
            }
            ans += rem*(lvl+1);
            rem -= map[i].size();
        }
    }
    cout << ans*2 << "\n";
}