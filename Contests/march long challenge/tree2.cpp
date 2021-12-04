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
void _out(vector<ll> v){for(auto i:v)cout<<i<<' ';cout<<endl;}
void _out(vector<pair<ll,ll>> v) {for(auto i:v) cout<<i.first<<' '<<i.second<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
const long long int mod = 1000000007;
const long long int N = 2*(1e5) + 7;
ll b_par=-1;
vector<ll> dis(N,0);
ll a_b = 0;
ll away=-1;
ll below=-1;
ll dist=0;
void dfs(ll node,ll par,ll b,vector<vector<ll>> graph){
    if(node == b) b_par = par;
    for(auto i: graph[node]){
        if(i != par){
            dis[i] = dis[node] + 1;
            dfs(i,node,b,graph);
        }
    }
}
void dfs(ll node,ll par,vector<vector<ll>> graph){
    for(auto i: graph[node]){
        if(i != par){
            dis[i] = dis[node] + 1;
            dfs(i,node,graph);
        }
    }
}
void dfs(ll node,ll par,vector<vector<ll>> graph,map<ll,bool> special){
    if(special[node]){
        away = node;
        return;
    }
    for(auto i: graph[node]){
        if(node != par){
            dfs(i,node,graph,special);
        }
    }
}
void dfsLast(ll node,ll par,vector<vector<ll>> graph,map<ll,bool> special){
    if(special[node]){
        if(dist > dis[node]){
            dist = dis[node];
            below = node;
        }
    }
    for(auto i: graph[node]){
        if(node != par){
            dfsLast(i,node,graph,special);
        }
    }
}
void solve(){
    ll n,k,a;
    cin>>n>>k>>a;
    vector<vector<ll>> graph(n+4);
    map<ll,bool> special;
    ll s;
    f(i,0,k) {
        ll x;
        cin>>x;
        s=x;
        special[x] = true;
    }
    f(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<pair<ll,ll>> ans;
    f(b,1,n+1){
        if(a == b){
            ans.push_back({0,s});
            continue;
        }
        b_par = -1;
        dis.clear();
        f(i,0,n+1) dis.push_back(0);
        dfs(a,0,b,graph);
        a_b = dis[b];
        away = -1;
        dfs(b,b_par,graph,special);
        if(away != -1){
            ans.push_back({a_b,away});
            continue;
        }
        dis.clear();
        f(i,0,n+1) dis.push_back(0);
        dfs(b_par,b,graph);
        dist=INT_MAX;
        below=-1;
        dfsLast(b_par,b,graph,special);
        dist+=1;
        ans.push_back({a_b-dist,below});
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