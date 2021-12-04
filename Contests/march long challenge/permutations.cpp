#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define ld long double
#define ull unsigned long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<endl;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
void solve();
int main(){
    IOS
    long long t = 1;
    cin >> t;
while(t--){
    solve();
    cout<<'\n';
}
    return 0;
}
// ANSWER IS FROM HERE //
void solve(){
    ll n,s;
    cin>>n>>s;
    set<pair<ll,ll>> uvs;
    f(i,0,n-1){
        pair<ll,ll> p;
        cin >> p.first >> p.second ;
        uvs.insert(p);
    }
    vector<ll> a = _in(n);
    vector<ll> b = _in(n);
    map<ll,pair<ll,ll>> m;
    f(i,0,n){
        ll x = a[i];
        ll y = b[i];
        if(x!=y){if(m.find(x) == m.end()){
            pair<ll,ll> p = {y,1};
            m[x] = p;
        }
        else{
            pair<ll,ll> p = m[x];
            p.second+=1;
            m[x] = p;
        }}
    }
    for(auto i : m){
        ll x = i.first;
        ll y = i.second.first;
        ll z = i.second.second;
        if(m.find(y) == m.end()) {cout << 0;return;}
        if(m[y] != {x,z}) {cout << 0;return;}
    }
    for(auto i : m){
        ll x = i.first;
        ll y = i.second.first;
        ll z = i.second.second;
        ll i1,i2;
        f(i,0,n) if(a[i]==x) {}
    }
}