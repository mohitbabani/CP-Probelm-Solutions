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
            if(sz[Pa] > sz[Pb]) swap(Pa,Pb);
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
#define int ll
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    f(i,0,n-1) 
    if(s[i] == 'a' && s[i+1] == 'a'){
        cout << 2 << '\n';
        return;
    }
    vector<int> a(n,0),b(n,0),c(n,0);
    if(s[0] == 'a') a[0] = 1;
    else if(s[0] == 'b') b[0] = 1;
    else c[0] = 1; 
    f(i,1,n){
        if(s[i] == 'a') {
            a[i] = a[i-1] + 1;
        }else{
            a[i] = a[i-1];
        }
        if(s[i] == 'b') {
            b[i] = b[i-1] + 1;
        }else{
            b[i] = b[i-1];
        }
        if(s[i] == 'c') {
            c[i] = c[i-1] + 1;
        }else{
            c[i] = c[i-1];
        }
    }
    vector<int> idx;
    f(i,0,n){
        if(s[i] == 'a') idx.pb(i);
    }
    if(idx.size() < 2) {
        cout << -1 << '\n';
        return;
    }
    ll sz = idx.size();
    ll ans = INT_MAX;
    // _out(idx);
    // _out(a);
    // _out(b);
    // _out(c);
    f(i,0,sz){
        f(j,i+1,min(sz,i+20)){
            ll A = j - i + 1;
            ll B = b[idx[j]] - b[idx[i]];
            ll C = c[idx[j]] - c[idx[i]];
            // cout << A << ' ' << B << ' ' << C << '\n';
            if(B < A && C < A){
                // cout << A << " " << B << " " << C << '\n'; 
                // cout << i << ' ' << j << '\n';
                ll curr = idx[j] - idx[i] + 1;
                ans = min(ans,curr);
            }
        }
    }
    if(ans == INT_MAX){
        cout << -1 << '\n';
    }else{
        cout << ans << '\n';
    }
}
int32_t main(){
    IOS
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}