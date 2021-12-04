#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
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
    ll n;cin>>n;
    vector<pair<pair<ll,ll>,ll>> pr;
    vector<ll> nat(n,0);
    f(i,0,n){
        ll a,l,r;cin>>a>>l>>r;
        nat[i]=a;
        pr.push_back({{l,r},i});
    }
    sort(all(pr));
    ll cnt=0;
    f(i,0,n-1){
        f(j,i+1,n){
            ll l1=pr[i].first.first,r1=pr[i].first.second;
            ll l2=pr[j].first.first,r2=pr[j].first.second;
            ll one = pr[i].second;
            ll two = pr[j].second;
            if(l2 < r1){
                cnt++;
            }else if(r1 == l2){
                if((nat[one] == 1 || nat[one] == 3) && (nat[two] == 1 || nat[two] == 2))
                    cnt++;
            }
        }
    }
    cout << cnt ;
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