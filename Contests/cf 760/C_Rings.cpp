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
void bruteforce(int n,string s){
    s = "x"+s;
    for(int sz = n/2;sz <= n; sz++){
        for(int i=1;i<=(n-sz+1);i++){
            ll val = stoi(s.substr(i,sz),0,2);
            for(int sz2=n/2;sz2 <= n;sz2++){
                for(int j=1;j<=(n-sz2+1);j++){
                    ll val2 = stoi(s.substr(j,sz2),0,2);
                    if(i != j || sz != sz2){
                        if(val % val2 == 0){
                            cout << i << ' ' << i+sz << ' ' << j << ' ' << j+sz2 << '\n';
                            return;
                        }
                    }
                }
            }
        }
    }
}
void solve(){
    int n;cin>>n;
    string s;
    cin >> s;
    // if(n <= 3){
    //     bruteforce(n,s);
    //     return;
    // }
    if((n == 2 && s == "11") || (n == 3 && s == "111")){
        cout << 1 << ' ' << 1 << ' ' << 2 << ' ' << 2 << '\n';
        return;
    }
    s = "x"+s;
    if(s.substr(1,n/2) == string(n/2,'0')){
        int idx = -1;
        int mid = n/2;
        for(int i=mid;i<=n;i++){
            if(s[i] == '1'){
                idx = i;
                break;
            }
        }
        cout << 1 << ' ' <<  mid << ' ' << 1 << ' ' << idx << '\n'; 
        return;
    }
    int idx = -1;
    int mid = (n/2)+1;
    for(int i=mid;i<=n;i++){
        if(s[i] == '0') {
            idx = i;
            break;
        }
    }
    if(idx != -1){
        cout << 1 << " " << idx << " " << 1 << " " << idx-1 << '\n';
        return;
    }
    while(s[mid] != '0' && mid >= 1){
        mid--;
    }
    if(mid >= 1){
        cout << mid << " " << n << " " << mid+1 << " " << n << '\n';
        return;
    }
    if(n%2 == 0){
        cout << 1 << ' ' << n << ' ' << 1 << ' ' << n-2 << '\n';
    }else{
        cout << 1 << ' ' << n-1 << ' ' << 1 << ' ' << n-3 << '\n';
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