#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define f(n) for(ll i=0;i<n;i++)
#define inf 1e17
#define _fast_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
ll _gcd(ll a,ll b) { return b?_gcd(b,a%b):a;}
ll _max(ll a,ll b){ if(a>b){return a;}else{ return b;}}
ll _modI(ll a, ll m){ return _power(a, m - 2, m);} 
void _out(vector<ll> arr){ for(auto i:arr){cout<<i<<' ';}cout<<"\n";}
void _out(vector<pair<ll,ll>> par ){for(auto i:par){cout<<i.first<<" "<<i.second<<"\n";}}
void _out(set<ll> arr){ for(auto i:arr){cout<<i<<' ';}cout<<"\n";}

// ll mod = 998244353; 
ll mod = 1000000007;
const ll N = 1e5 + 7;

ll cnt = 0;

vector<pair<ll,ll>> graph[N];
vector<ll> ans;


void dfs(ll node, ll par){

    if(graph[node].size() == 1 && cnt != 0){
        ans.push_back(node);
        cnt = 0;
    }

    for(auto i: graph[node]){
        if(i.first != par){
            if(i.second == 2){
                cnt ++;
            }
            dfs(i.first, node);
        }
    }
}

void solve(){

    ll n;
    cin >> n;

    f(n-1){
        ll x,y,t;
        cin >> x>> y >> t;
        graph[x].push_back({y, t});
        graph[y].push_back({x, t});
    }

    dfs(1, 0);
    
    cout << ans.size() <<" \n";

    _out(ans);
}

   
int main(){
    _fast_ 

    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }

} 
