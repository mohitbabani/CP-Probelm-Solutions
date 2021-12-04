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
pair<ll,ll> nul = {-1,-1};
void solution(vector<pair<ll,ll>> &vec,vector<ll> &ans,string &s,ll m){
    stack<pair<ll,ll>> stk;
    f(i,0,vec.size()){
        auto p = vec[i];
        if(s[p.second] == 'R') stk.push(p);
        else{
            pair<ll,ll> st;
            if(!stk.empty()) st = stk.top(); 
            if(stk.empty() || s[st.second] == 'L') stk.push(p);
            else{
                stk.pop();
                ans[p.second] = ans[st.second] = abs(st.first-p.first)/2;
            }
        }
    }
    if(stk.size()<=1) return;
    vector<pair<ll,ll>> remaining;
    while(!stk.empty()){
        remaining.push_back(stk.top());
        stk.pop();
    }
    f(i,0,remaining.size()-1){
        auto p1 = remaining[i];
        auto p2 = remaining[i+1];
        if(p1 == nul || p2 == nul) continue;
        if(s[p1.second] == 'R' && s[p2.second] == 'R'){
            ll val = m - max(p1.first,p2.first);
            val += abs(p1.first - p2.first)/2;
            ans[p1.second] = ans[p2.second] = val;
            remaining[i] = remaining[i+1] = nul;
        }
    }
    reverse(all(remaining));
    f(i,0,remaining.size()-1){
        auto p1 = remaining[i];
        auto p2 = remaining[i+1];
        if(p1 == nul || p2 == nul) continue;
        if(s[p1.second] == 'L' && s[p2.second] == 'L'){
            ll val = min(p1.first,p2.first);
            val += abs(p1.first - p2.first)/2;
            ans[p1.second] = ans[p2.second] = val;
            remaining[i] = remaining[i+1] = nul;
        }
    }
    reverse(all(remaining));
    ll left=0;
    for(auto i: remaining) if(i != nul) left++;
    if(left <= 1) return;
    pair<ll,ll> p1,p2=nul;
    for(auto i: remaining){
        if(i != nul){
            if(p2 == nul) p2 = i;
            else p1 = i;
        }
    }
    ll val = p1.first;
    val += m - p2.first;
    val += abs(p1.first-p2.first)/2;
    ans[p1.second] = ans[p2.second] = val;
}
void solve(){
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>> e,o;
    f(i,0,n){
        ll xi;cin>>xi;
        if(xi%2) o.push_back({xi,i});
        else e.push_back({xi,i});
    }
    string s="";
    f(i,0,n){
        char ch;cin>>ch;
        s.push_back(ch);
    }
    vector<ll> ans(n,-1);
    if(!o.empty()){
        sort(all(o));
        solution(o,ans,s,m);
    }
    if(!e.empty()){
        sort(all(e));
        solution(e,ans,s,m);
    }
    _out(ans);
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