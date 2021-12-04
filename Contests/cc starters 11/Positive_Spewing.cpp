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
void solve(){
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    bool flag = 1;
    f(i,0,n){
        cin >> v[i];
        if(v[i] != 0) flag = 0;
    }
    if(flag){
        cout << 0 << '\n';
        return;
    }
    if(k == 0){
        ll ans = 0;
        f(i,0,n) ans += v[i];
        cout << ans << '\n';
        return;
    }
    vector<ll> l(n,-1),r(n,-1);
    ll can = 0;
    f(i,0,2*n){
        if(l[i%n] != -1) continue;
        if(can != 0){
            l[i%n] = can;
            can++;
        }
        if(v[i%n] > 0) can=1;
    }
    can=0;
    for(int i=2*n-1;i>=0;i--){
        if(r[i%n] != -1) continue;
        if(can != 0){
            r[i%n] = can;
            can++;
        }
        if(v[i%n] > 0) can=1;
    }
    vector<ll> lr(n);
    f(i,0,n){
        lr[i] = min(l[i],r[i]);
    } 
    ll ans = 0;
    f(i,0,n){
        if(v[i] > 0){
            ans += v[i];
            if(l[i] == 1) ans++;
            if(r[i] == 1) ans++;
            ans += (k-1)*2;
        }else{
            if(l[i] == r[i]){
                if(k >= l[i]){
                    ans += (k-l[i]+1)*2;
                }
            }else if(abs(l[i] - r[i]) != 1){
                if(k >= lr[i]){
                    ll rem = k-lr[i]+1;
                    if(rem == 1){
                        ans++;
                    }else{
                        ans+=2;
                        ans += (rem-2)*2;
                    }
                }
            }else{ // l[i] - r[i] == 1
                if(k >= lr[i]){
                    ll rem = k-lr[i]+1;
                    ans++;
                    ans += (rem-1)*2;
                }
            }
        }
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