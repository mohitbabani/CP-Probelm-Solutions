#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define ld long double
#define pb push_back
#define ull unsigned long long
#define inf 1e17
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
void _out(multiset<ll> v) {for(auto i:v) cout<<i<<' '; cout<<nl;}

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
void solve(){
    ll n;
    cin >> n;
    vector<ll> v;
    multiset<ll> ms;
    set<ll> se;
    ll mn = inf, mx = -inf;
    f(i,0,n) {
        ll x;
        cin >> x;
        ms.insert(x);
        se.insert(x);
        v.pb(x);
        mn = min(mn,x); mx = max(mx,x);
    }
    sort(all(v));
    if(se.size() <= 2){
        cout << 0 << '\n';
        return;
    }
    if(n == 3){
        cout << min(v[2]-v[1],v[1]-v[0]) << '\n';
        return;
    }
    ll ans = inf;
    ll temp = 0, mid = (n-1)/2;
    f(i,0,n-1){
        temp = temp + abs(v[i]-v[mid]);
    }
    ans = min(temp,ans);
    temp = 0;
    f(i,1,n){
        temp = temp + abs(v[i]-v[mid+1]);
    }
    ans = min(temp,ans);
    ms.erase(ms.find(mn));
    ms.erase(ms.find(mx));
    for(int i=1;i<n-1;i++){
        ms.erase(ms.find(v[i]));
        ll y = mx + mn - v[i];
        if(ms.find(y) != ms.end()){
            cout << 0 << '\n';
            return;
        }
        auto itr = ms.upper_bound(y);
        if(itr != ms.end()){
            ll temp = abs(*itr - y);
            ans = min(ans,temp);
        }
        if(itr != ms.begin()){
            itr--;
            ll temp = abs(y - *itr);
            ans = min(ans,temp);
        }
        ms.insert(v[i]);
    }
    cout << ans << '\n';
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