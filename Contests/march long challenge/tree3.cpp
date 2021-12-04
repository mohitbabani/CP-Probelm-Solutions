#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
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
vector<ll> d;
void dfs(ll node,ll par,vector<vector<ll>> g){
    for(auto i: g[node]){
        if(i!=par){
            d[i] = d[node] + 1;
            dfs(i,node,g);
        }
    }
}
void solve(){
    ll n,k,a;
    cin>>n>>k>>a;
    vector<vector<ll>> g(n+1);
    set<ll> s;
    f(i,0,k) {
        ll x;
        cin>>x;
        s.insert(x);
    }
    f(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<pair<ll,ll>> ans;
    d.clear();
    f(i,0,n+1) d.push_back(0);
    dfs(a,0,g);
    vector<ll> disA = d;
    // f(i,1,n+1) cout << i << " " << disA[i] << "\n";
    f(b,1,n+1){
        d.clear();
        f(i,0,n+1) d.push_back(0);
        dfs(b,0,g);
        auto disB = d;
        // f(i,1,n+1) cout << i << " " << disB[i] << "\n";
        ll val=INT_MIN;
        ll idx=-1;
        for(auto i: s){
            ll temp = disA[i] - disB[i];
            if(val < temp){
                val = temp;
                idx = i;
            }
        }
        ans.push_back({val,idx});
    }
    for(auto i: ans){
        cout << i.first << " ";
    }
    cout << "\n";
    for(auto i: ans){
        cout << i.second << " ";
    }
    cout << "\n";
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