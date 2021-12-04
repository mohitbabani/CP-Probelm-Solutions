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
// bool lt(vector<ll> v1,vector<ll> v2){
//     // is v1 less than v2
//     sort(all(v1));
//     sort(all(v2),greater<ll>());
//     ll one  = 0;
//     f(i,0,5){
//         if(v1[i] < v2[i]) one++;
//     }
//     if(one >= 3) return true;
//     return false;
// }
bool lt(vector<ll> v1,vector<ll> v2){
    // is v1 less than v2
    ll less = 0;
    f(i,0,5){
        ll idx=-1;
        ll mn=INT_MAX;
        f(j,0,5){
            if(v2[j] > v1[i] && v2[j] != -1){
                if(v2[j] < mn){
                    mn = v2[j];
                    idx=j;
                }
            }
        }
        if(idx == -1) continue;
        else{
            less++;
            v2[idx] = -1;
        }
    }
    if(less >= 3) return true;
    return false;
}
bool eq(vector<ll> v1,vector<ll> v2){
    ll g=0,e=0,l=0;
    sort(all(v1));
    sort(all(v2),greater<ll>());
    f(i,0,5){
       if(v1[i] < v2[i]) g++;
       else if(v1[i] == v2[i]) e++;
       else l++;
    }
    if(g == l) return true;
    return false;
}
void solve(){
    ll n;cin>>n;
    vector<vector<ll>> r(n,vector<ll>(5,0));
    f(i,0,n){
        f(j,0,5) cin >> r[i][j];
    }
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    vector<ll> mn(r[0]);
    ll idx = 0;
    f(i,1,n){
        if(lt(r[i],mn)){
            mn = r[i];
            idx = i;
        }
    }
   // f(i,0,5) cout << mn[i] << ' '; cout << '\n';
    // f(i,0,n){
    //     if(i != idx && lt(r[i],mn)){    
    //         // cout << idx << '\n';
    //         // f(j,0,5) cout << r[i][j] << ' ' ; cout << '\n';
    //         cout << -1 << '\n';
    //         return;
    //     }
    // }
    f(i,0,n){
        if(i != idx && lt(mn,r[i]) == false) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << idx+1 << '\n';
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