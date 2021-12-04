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
ll primeFactors(ll n)
{
    ll cnt=0;
	while (n % 2 == 0)
	{
		cnt++;
		n = n/2;
	}
	for (ll i = 3; i*i <= n; i = i + 2)
	{
		while (n % i == 0)
		{
			cnt++;
			n = n/i;
		}
	}
	if (n > 2)
		cnt++;
    return cnt;
}
void solve(){
    ll a,b,k;
    cin>>a>>b>>k;
    if(a==b){
        if(k == 1){
            cout << "NO\n";
            return;
        }
    }
    if(k==1){
        if(a%b == 0 || b%a == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        return;
    }
    ll cnt=0;
    cnt += primeFactors(a);
    cnt += primeFactors(b);
    // cout << cnt << "\n";
    if(k > cnt){
        cout << "NO\n";
    }else{
        cout << "YES\n";
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