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
    ll n;
    cin >> n;
    vector<vector<ll>> vv;
    f(i,0,n){
        ll sz;cin>>sz;
        vector<ll> v(sz);
        f(j,0,sz) cin >> v[j];
        vv.pb(v);
    }
    // for(auto vec: vv){
    //     _out(vec);
    // }
    vector<vector<ll>> ans;
    f(i,0,n){
        vector<ll> v = vv[i];
        ll sz = v.size();
        vector<ll> chgs;
        ll cnt=1;
        f(j,1,v.size()){
            if(v[j] >= v[j-1]){
                cnt++;
            }else{
                chgs.pb(cnt);
                cnt=1;
            }
        }
        if(cnt != 0) chgs.pb(cnt);
        ans.pb(chgs);
    }
    // for(auto vecot: ans){
    //     _out(vecot);
    // }
    ll answer = 0;
    vector<ll> vec;
    f(i,0,n){
        ll temp = 0;
        ll mx = -1;
        f(j,0,ans[i].size()){
            temp += ans[i][j];
            vec.pb(ans[i][j]);
            mx = max(mx,ans[i][j]);
        }
        temp -= mx;
        answer += temp;
    }
    // for(auto i : vec){
    //     cout << i << ' ';
    // }cout << '\n';
    // cout << answer << "\n";
    // priority_queue<ll,vector<ll>, greater<ll>> q;
    // f(i,0,vec.size()) q.push(vec[i]);
    // while(q.size() >= 2){
    //     ll one = q.top();
    //     q.pop();
    //     ll two = q.top();
    //     q.pop();
    //     answer += (one+two);
    //     q.push((one+two));
    // } 
    multiset<ll> st;
    f(i,0,vec.size()) st.insert(vec[i]);
    while(st.size() >= 2){
        ll one = *st.begin();
        st.erase(st.begin());
        ll two = *st.begin();
        st.erase(st.begin());
        answer += (one+two);
        st.insert(one+two);
    }
    cout << answer << "\n";
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