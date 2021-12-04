#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define inf LLONG_MAX
#define all(vec) vec.begin(),vec.end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,b,a) for(ll i=b;i>=0;i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const long long mod = 1e9 + 7; // 998244353;
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
ll _gcd(ll a,ll b) { return b?_gcd(b,a%b):a;}
ll _max(ll a,ll b){ if(a>b){return a;}else{ return b;}}
ll _modI(ll a, ll m){ return _power(a, m - 2, m);}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(vector<pair<ll,ll>> v) {for(auto i:v) cout<<i.first<<' '<<i.second<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
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
    string zero(32-(s.length()),'0');
    s = zero + s;
    return s;
}
void solve(){
    int n,k;
    cin>>n>>k;
    int a[n];
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    vector<vector<int>> pre(n,vector<int>(mx+1,0));
    vector<vector<int>> suff(n,vector<int>(mx+1,0));
    f(i,0,n){
        if(i == 0){
            pre[i][a[i]] = 1;
            continue;
        }
        f(j,0,mx){
            if(j != a[i]){
                pre[i][j] = pre[i-1][j];
            }
        }
        pre[i][a[i]] = pre[i-1][a[i]]+1;
    }
    for(int i=n-1;i>=0;i--){
        if(i == n-1){
            suff[i][a[i]]=1;
            continue;
        }
        f(j,0,mx){
            if(j != a[i]){
                suff[i][j] = suff[i+1][j];
            }
        }
        suff[i][a[i]] = suff[i+1][a[i]]+1;
    }k++;
    ll ans = 0;
    f(i,0,n){
        
    }
}
int main(){
    IOS
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}