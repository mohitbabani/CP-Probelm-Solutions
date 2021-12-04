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
    if(s.size() == 0) s.push_back('0');
    return s;
}
void solve(){
    ll n;cin>>n;
    // if(n <= 6){
    //     cout << 15LL << '\n';
    //     return;
    // }
    // if(n <= 8){
    //     cout << 20 << "\n";
    //     return;
    // }
    // if(n <= 10){
    //     cout << 25 << '\n';
    //     return;
    // }
    ll a=0;
    if(n%6 == 0 || n%8 == 0 || n%10 == 0){
        if(n%6 == 0) a = (n/6)*15LL;
        else if(n % 8 == 0) a = (n/8)*20LL;
        else a = (n/10)*25LL;
        cout << a << '\n';
        return;
    }
    if((n%10) % 6 == 0){
        a = (n/10)*25LL;
        a += 15LL;
        cout << a << '\n';
        return;
    }
    if((n%10) % 8 == 0){
        a = (n/10)*25LL;
        a += 20LL;
        cout << a << "\n";
        return;
    }
    if((n%8) % 6 == 0){
        a = (n/8)*20LL;
        a += 15LL;
        cout << a << "\n";
        return;
    }
    a = (n/10LL)*25LL;
    if(n%10 <= 6){
        a += 15LL;
    }else if(n%10 <= 8){
        a += 20LL;
    }else{
        a += 25LL;
    }
    ll val = (n/8)*20LL;
    if(n%8 <= 6){
        val += 15LL;
    }else{
        val += 20LL;
    }
    a = min(a,val);
    ll val2 = ((n/6)+1)*15LL;
    a = min(a,val2);
    cout << a << '\n';
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