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
void solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    map<ll,pair<ll,ll>> m;
    f(i,0,l){
        ll x;cin>>x;
        m[x].first++;
    }
    f(i,0,r){
        ll x;cin>>x;
        m[x].second++;
    }
    ll d = n/2 - min(l,r);
    ll ans = d;
    if(l == min(l,r)){
        for(auto i: m){
            if(d>0){
                auto p = i.second;
                if(p.first < p.second){
                    ld diff = (p.second+p.first);
                    diff = ceil(diff/2);
                    if(d > diff){
                        p.first += diff;
                        p.second -= diff;
                        d -= diff;
                        m[i.first] = p;
                    }else{
                        p.first += d;
                        p.second -= d;
                        d = 0;
                        m[i.first] = p;
                    }
                }
            }
        }
    }else{
        for(auto i: m){
            if(d>0){
                auto p = i.second;
                if(p.first > p.second){
                    ld diff = (p.second+p.first);
                    diff = ceil(diff/2);
                    diff -= p.second;
                    if(d > diff){
                        p.first -= diff;
                        p.second += diff;
                        d -= diff;
                        m[i.first] = p;
                    }else{
                        p.first -= d;
                        p.second += d;
                        d = 0;
                        m[i.first] = p;
                    }
                }
            }
        }
    }
    ll val=0;
    for(auto i: m){
        auto p = i.second;
        val += abs(p.first - p.second);
    }
    ans += val/2;
    cout << ans << "\n";
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