#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool isPrime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return 0;return 1;}
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
ll _gcd(ll a,ll b) { return b?_gcd(b,a%b):a;}
ll _max(ll a,ll b){ if(a>b){return a;}else{ return b;}}
ll _modI(ll a, ll m){ return _power(a, m - 2, m);}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(vector<pair<ll,ll>> v) {for(auto i:v) cout<<i.first<<' '<<i.second<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
const long long int mod = 1000000007;
void solve(){
    ll n;cin>>n;
    vector<vector<ll>> graph(n+7);
    vector<pair<ll,ll>> lr(1,{0,0}),edges;
    f(i,0,n){
        ll l,r;cin>>l>>r;
        lr.push_back({l,r});
    }f(i,0,n-1){
        ll u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.push_back({u,v});
    }
    vector<pair<ll,ll>> sz;
    f(i,1,n+1){
        ll s = graph[i].size();
        sz.push_back({s,i});
    }
    sort(all(sz));
    reverse(all(sz));
    vector<ll> a(n+1,-1);
    f(j,0,n){
        ll node = sz[j].second;
        auto p = lr[node];
        ll l = p.first,r = p.second;
        ll l_sum=0,r_sum=0;
        for(auto i: graph[node]){
            auto p2 = lr[i];
            ll l2 = p2.first, r2 = p2.second;
            ll v1 = abs(l2-l);
            ll v2 = abs(r2-l);
            ll add = max(v1,v2);
            if(a[i] != -1){
                add = abs(a[i]-l);
            }
            l_sum += add;
        }for(auto i: graph[node]){
            auto p2 = lr[i];
            ll l2 = p2.first, r2 = p2.second;
            ll v1 = abs(l2-r);
            ll v2 = abs(r2-r);
            ll add = max(v1,v2);
            if(a[i] != -1){
                add = abs(a[i]-r);
            }
            r_sum += add;
        }
        if(l_sum > r_sum){
            a[node] = l;
        }else{
            a[node] = r;
        }
    }
    ll ans=0;
    f(i,0,n-1){
        auto p = edges[i];
        ans += abs(a[p.first] - a[p.second]);
    }
    // f(i,0,sz.size()) cout << sz[i].first << " " << sz[i].second << "\n";
    // // _out(a);
    cout << ans  << "\n";
}   
int main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}