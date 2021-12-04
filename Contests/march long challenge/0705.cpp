#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
ll _gcd(ll a,ll b) { return b?_gcd(b,a%b):a;}
ll _max(ll a,ll b){ if(a>b){return a;}else{ return b;}}
ll _modI(ll a, ll m){ return _power(a, m - 2, m);}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(vector<pair<ll,ll>> v) {for(auto i:v) cout<<i.first<<' '<<i.second<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
const long long int mod = 1000000007;
const long long int mod2 = 1000000207;
struct vals{
    ll arr[4];
};
inline void print(vals val){
    f(i,0,4) cout << val.arr[i] << " ";
    cout << "\n";
}
void solve(){
    ll n;cin>>n;
    vector<ll> a = _in(n);
    bool fluc=1;
    vector<vals> ans;
    f(i,0,n-1){
        if(__gcd(a[i],a[i+1]) != 1){
            ll mn = min(a[i],a[i+1]);
            if(fluc) a[i] = mod;
            else a[i] = mod2;
            fluc = !fluc;
            a[i+1] = mn;
            ans.push_back({i+1,i+2,a[i],a[i+1]});
        }
    }
    ll k = ans.size();
    cout << k << "\n";
    f(i,0,k){
        print(ans[i]);
    }
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