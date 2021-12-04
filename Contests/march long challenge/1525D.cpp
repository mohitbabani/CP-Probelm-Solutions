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
ll ans = 0;
ll n;
void solution(vector<ll> &arr,ll a){
    ll i1 = -1;
    ll i2 = -1;
    for(ll i=a;i<n;i++){
        if(arr[i]==0) {i1 = i;break;}
    }
    for(ll i=a;i>=0;i--){
        if(arr[i]==0) {i2 = i;break;}
    }
    if(i1==-1){
        ans += abs(i2-a);
        arr[i2] = arr[a] = -1;
        return;
    }
    if(i2==-1){
        ans += abs(i1-a);
        arr[i1] = arr[a] = -1;
        return;
    }
    ll val1 = abs(i1-a);
    ll val2 = abs(i2-a);
    if(val1 < val2){
        ans += abs(i1-a);
        arr[i1] = arr[a] = -1;
        return;
    }
    ans += abs(i2-a);
    arr[i2] = arr[a] = -1;
}
void solve(){
    cin>>n;
    vector<ll> arr = _in(n);
    f(i,0,n){
        if(arr[i]==1){
            solution(arr,i);
        }
    }
    cout << ans ;
}
int main(){
    IOS
    long long t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}