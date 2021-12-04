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
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(vector<pair<ll,ll>> v) {for(auto i:v) cout<<i.first<<' '<<i.second<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
const long long int mod = 1000000007;
vector<vector<ll>> mat(1000,vector<ll>(1000,0));
void prereq(){
    ll val=1;
    mat[0][0] = 1;
    f(i,1,1000){
        mat[0][i] = mat[0][i-1] + val;
        val++;
    }
    val=2;
    f(j,1,1000){
        mat[j][0] = mat[j-1][0] + val;
        val++;
    }
    val=2;
    f(i,1,1000){
        ll val2 = val;
        f(j,1,1000){
            mat[i][j] = mat[i][j-1] + val2;
            val2++;
        }
        val++;
    }
}
void solve(){
    ll n,k;cin>>n>>k;
    vector<ll> arr = _in(n);
    vector<vector<ll>> g(k);
    f(i,0,n){
        g[i%k].push_back(arr[i]);
    }
    ll ans = 0;
    f(i,0,k){
        map<ll,ll> cnts;
        ll cnt=0;
        for(auto j: g[i]){
            cnts[j]++;
            cnt = max(cnts[j],cnt);
        }
        ans += g[i].size() - cnt;
    }
    cout << ans  << "\n";
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