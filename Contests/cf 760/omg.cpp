#include<bits/stdc++.h>
using namespace std;
#define ll long 
#define pii pair<ll,ll>
#define ld long double
#define pb push_back
#define ull unsigned long long
const ll inf = LLONG_MAX;
#define all(vec) vec.begin(),vec.end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,b,a) for(ll i=b;i>=0;i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const long long mod = 1e9 + 7; // 998244353;
const char nl = (char)10;
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
ll _gcd(ll a,ll b) { return b?_gcd(b,a%b):a;}
ll _max(ll a,ll b){ if(a>b){return a;}else{ return b;}}
ll _modI(ll a, ll m){ return _power(a, m - 2, m);}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<nl;}
void _out(vector<pair<ll,ll>> v) {for(auto i:v) cout<<i.first<<' '<<i.second<<nl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<nl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
bool isPrime(ll n){
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(n%2==0 || n%3==0) return 0;
    for(ll i=5;i*i<=n;i=i+6) 
        if(n%i==0 || n%(i+2)==0) 
            return 0;
    return 1;
}
ll binaryToDecimal(string n){
    string num = n;
    ll dec_value = 0; 
    ll base = 1;
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
string decimalToBinary(ll n){
    string s(0,' ');
    while(n != 0){
        if(n%2) s.push_back('1');
        else s.push_back('0');
        n /= 2;
    }
    reverse(s.begin(),s.end());
    if(s.size() == 0) s.push_back('0');
    return s;
}
class DSU{
    public:
        vector<ll> par,sz;
        DSU(ll n){
            par.resize(n+2);
            sz.resize(n+2);
            f(i,1,n+1) par[i] = i, sz[i] = 1;
        }
        void merge(ll a,ll b){
            ll Pa = find(a);
            ll Pb = find(b);
            if(sz[Pa] > Pb) swap(Pa,Pb);
            par[Pa] = Pb;
            sz[Pb]+=sz[Pa];
        }
        ll find(ll node){
            while(par[node] != node){
                node = par[node];
            }
            return node;
        }
        bool is_same(ll a,ll b){
            return find(a) == find(b);
        }
};
ll n,k,s;
vector<vector<ll>> g;
map<pii,ll> edges;
vector<ll> dis;
void dijistra(ll sc){

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis.resize(k+1,inf);
    pq.push({0,sc});
    dis[sc] = 0;
    
    while(!pq.empty()){

        ll u = pq.top().second;
        pq.pop();

        for(auto v: g[u]){
            
            ll w = edges[{u,v}];

            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({dis[v],v});
            }
        }
    }
}
int32_t main(){
    IOS
    cin >> n >> k >> s;
    
    vector<ll> base(n+1);
    f(i,1,n+1) cin >> base[i];
    
    g.resize(k+1,vector<ll>());
    
    f(i,1,n+1){
        ll u = base[i];
        f(v,1,k+1){
            ll cost;
            cin >> cost;
            if(u == v || cost == -1) continue;
            pii p = {u,v};
            if(edges.find(p) != edges.end()){
                edges[p] = min(edges[p],cost);
            }else{
                edges[p] = cost;
                g[u].pb(v);
            }
        }
    }
    dijistra(base[s]);
    //_out(dis);
    for(int i=1;i<=n;i++){
        ll bs = base[i];
        if(dis[bs] == inf) dis[bs] = -1;
        cout << dis[bs] << ' ';
    }
    cout << '\n';
    return 0;
}