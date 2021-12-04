#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define vii vector<pair<ll,ll>>
#define sii set<pair<ll,ll>>
#define ull unsigned long long
#define inf LLONG_MAX
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
int n,m1,m2;
set<pair<int,int>> total;
int* par1;
int* par2;
void start(int n){
    f(i,1,n+1){
        f(j,1,n+1){
            if(i != j)
            total.insert({min(i,j),max(i,j)});
        }
    }
    par1 = new int[n+1];
    par2 = new int[n+1];
    f(i,1,n+1) par1[i] = par2[i] = -1;
}
int findParent(int g,int node){
    int* par;
    if(g == 1) par = par1;
    else par = par2; 

    while(par[node] >= 0){
        node = par[node];
    }
    return node;
}
void Union(int g,int u, int v){
    int* par;
    if(g == 1) par = par1;
    else par = par2; 

    int PARU = findParent(g,u);
    int PARV = findParent(g,v);
    if(par[PARU] <= par[PARV]){
        par[PARU] += par[PARV];
        par[PARV] = PARU;
        // par[v] = PARU;
    }else{
        par[PARV] += par[PARU];
        par[PARU] = PARV;
        // par[u] = PARV;
    }
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
int main(){
    IOS
    cin >> n >> m1 >> m2;
    start(n);
    f(i,0,m1){
        int u,v;
        cin >> u >> v;
        Union(1,u,v);
        if(v < u) swap(u,v);
        total.erase({u,v});
    }
    f(i,0,m2){
        int u,v;
        cin >> u >> v;
        Union(2,u,v);
        if(v < u) swap(u,v);
        total.erase({u,v});
    }
    vector<pair<int,int>> ans;
    for(auto i: total){
        int u = i.first, v = i.second;
        if(findParent(1,u) == findParent(1,v) || findParent(2,u) == findParent(2,v)){
            continue;
        } 
        Union(1,u,v);
        Union(2,u,v);
        ans.pb({u,v});
    }
    cout << ans.size() << '\n';
    for(auto i: ans){
        cout << i.first << ' ' << i.second << '\n';
    }
}