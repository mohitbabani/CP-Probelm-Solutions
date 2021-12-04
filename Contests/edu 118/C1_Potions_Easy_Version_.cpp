#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii(T) pair<T,T>
#define pb push_back
#define set_bits __builtin_popcountll
#define all(vec) vec.begin(),vec.end()
#define f(i,a,b) for(int i=a;i<b;i++)
const long long inf = 1e17;
const long long mod = 1e9 + 7;
//const long long mod = 998244353;
const char nline = (char)10;
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
ll _modI(ll a, ll m){ return _power(a, m - 2, m);}
template<typename T>
void _out(vector<T> v) {for(T i:v) cout<<i<<' '; cout<<nline;}
template<typename T>
void _out(vector<pair<T,T>> v) {for(pair<T,T> i:v) cout<<i.first<<' '<<i.second<<nline;}
template<typename T>
void _out(set<T> s) {for(T i:s) cout<<i<<' '; cout<<nline;}


void solve(){
    
}   


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}