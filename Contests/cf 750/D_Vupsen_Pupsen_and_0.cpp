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
void solve(){
    ll n;
    cin >> n;
    vector<ll> a;
    map<ll,ll> mp;
    f(i,0,n){
        ll x;
        cin >> x;
        a.pb(x);
        mp[x]++;
    }
    if(n % 2 == 0){
        vector<ll> b(a);
        for(int i=0;i<n;i+=2){
            swap(b[i],b[i+1]);
            b[i] = -b[i];
        }
        _out(b);
        return;
    }
    int rep = INT_MAX;
    for(auto p: mp){
        if(p.second >= 2){
            rep = p.first;
            break;
        }
    }
    if(rep != INT_MAX){
        vector<ll> b(a);
        int idx = -1;
        for(int i=0;i<n;i++){
            if(a[i] == rep) {
                idx = i;
                break;
            }
        }
        // cout << idx << ' ';
        for(int i=0;i<n;i++){
            if(idx % 2 == 0){
                if(i == idx) continue;
                swap(b[i],b[i+1]),i++;
                b[i] = -b[i];
            }else{
                if(i+1 == idx){
                    swap(b[i],b[i+2]);
                    i+=2;
                }else{
                    swap(b[i],b[i+1]);
                    i++;
                }
                b[i] = -b[i];
            }
        }
        b[idx] = 1;
        for(int i=0;i<n;i++){
            if(a[i] == rep && i != idx) {
                b[i] -= 1;
                if(b[i] == 0){
                    b[i] -= 1;
                    b[idx]++;
                }
                break;
            }   
        }
        
        // ll ans = 0;
        // f(i,0,n){
        //     ans += (b[i] * a[i]);
        // }
        // cout << ans << ' ';
        _out(b);
        return;
    }
    vector<ll> b(a);
    for(int i=0;i<n-1;i+=2){
        swap(b[i],b[i+1]);
        b[i] = -b[i];
    }   
    b[n-1] = -a[n-2];
    b[n-2] += a[n-1];
    if(b[n-2] == 0){
        b[n-2] += a[n-1];
        b[n-1] *= 2;
    }
    //  ll ans = 0;
    //     f(i,0,n){
    //         ans += (b[i] * a[i]);
    //     }
    //     cout << ans << ' ';
    _out(b);
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