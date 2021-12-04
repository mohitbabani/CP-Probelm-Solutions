#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define ld long double
#define pb push_back
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
vector<vector<int>> arr;
int n,c;
vector<vector<int>> ss;
void generate(vector<int> arr, int index=0,
                       vector<int> subarr={})
{
    // Print the subsequence when reach
    // the leaf of recursion tree
    if (index == arr.size())
    {
        int l = subarr.size();
 
        // Condition to avoid printing
        // empty subsequence
        if (l != 0)
            ss.pb(subarr);
    }
    else
    {
        // Subsequence without including
        // the element at current index
        generate(arr, index + 1, subarr);
 
        subarr.push_back(arr[index]);
 
        // Subsequence including the element
        // at current index
        generate(arr, index + 1, subarr);
    }
    return;
}
vector<int> compute(vector<int> v,vector<int> v1,vector<int> v2){
    for(int del : v1){
        for(auto it=v.begin();it!=v.end();it++){
            if(*it == del){
                v.erase(it);
                break;
            }
        }
    }
    for(int i: v2){
        v.pb(i);
    }
    return v;
}
vector<int> ans;
void recursion(vector<int> vis,vector<int> changes,int node){
    if(count(all(vis),0) == 0){
        ans = vis;
        return;
    }
    ss.clear();
    generate(changes);
    auto css = ss;
    for(int i=0;i<n;i++){
        if(vis[i] == 0){
            ss.clear();
            generate(arr[i]);
            auto iss = ss;
            for(auto v1: css){
                int cc = c;
                for(auto i: v1) cc+=i;
                for(auto v2: iss){
                    int ava = 0;
                    for(auto j: v2) ava+=j;
                    if(cc == ava){
                        vis[i] = node;
                        auto newc = compute(changes,v1,v2);
                        recursion(vis,newc,node+1);
                    }
                }
            }
        }
    }
}
int32_t main(){
    cin >> c >> n;
    f(i,0,n){
        int h;cin>>h;
        vector<int> v(h);
        f(j,0,h) cin >> v[j];
        arr.pb(v);
    }
    vector<int> vis(n,0);
    vector<int> changes = {0};
    recursion(vis,changes,1);
    for(int f=1;f<=n;f++){
        int idx = -1;
        for(int i=0;i<ans.size();i++){
            if(ans[i] == f){
                idx = i;
            }
        }
        char ch = (char)(65+idx);
        cout << ch ;
    }
}