#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define ld long double
#define ull unsigned long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool isPrime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return 0;return 1;}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
const long long int mod = 1000000007;
void solve(){
    ll n;cin>>n;
    map<ll,vector<ll>> m;
    vector<pair<ll,ll>> vec(n,{0,0});
    f(i,0,n){
        cin>>vec[i].first;
    }
    f(i,0,n){
        cin>>vec[i].second;
    }
    f(i,0,n){
        ll x = vec[i].first;
        ll val = vec[i].second;
        m[x].push_back(val);
    }
    ll m_s = -1;
    for(auto i: m){
        vector<ll> v = i.second;
        sort(all(v),greater<ll>());
        f(i,1,v.size()){
            v[i] = v[i] + v[i-1]; 
        }
        m[i.first] = v;
        ll size = v.size();
        m_s = max(m_s,size);
    }
    vector<ll> ans(n+1,0);
    for(auto i: m){
        vector<ll> v = i.second;
        f(sz,1,v.size()+1){
            ll idx = v.size() % sz;
            ans[sz] += v[v.size() - 1 - idx];  
        }
    }
    f(i,1,n+1) cout << ans[i] << " "; cout << "\n";
    // for(auto i: m){
    //     _out(i.second);
    // }
    // f(sz,1,m_s+1){
    //     ll val=0;
    //     for(auto i: m){
    //         vector<ll> v = i.second;
    //         ll idx = v.size() % sz;
    //         idx = v.size() - idx - 1;
    //         if(idx >= 0) val += v[idx];
    //     }
    //     cout << val << " ";
    // }
    // f(sz,m_s+1,n+1){
    //     cout << 0 << " ";
    // }
    // cout << "\n";
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