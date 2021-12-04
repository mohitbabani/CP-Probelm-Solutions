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
while(t--){
    solve();
}
    return 0;
}
// ANSWER IS FROM HERE //
void solve(){
    ll n,e;
    cin >> n >> e;
    ll distance[n] = {0};
    set<pair<ll,ll>> path;
    bool flag = 0;
    f(i,0,e){
        ll x,y;cin>>x>>y;
        pair<ll,ll> p;
        p.first = min(x,y);
        p.second = max(x,y);
        if(p.first == 0) flag = 1;
        path.insert(p);
    }
    if(flag = 0) {cout << 0 << " " << 0;return;}
    for(auto i : path){
        ll x = i.first;
        ll y = i.second;
        distance[i.second] = max(distance[i.first] + 1,distance[i.second]);
    }
    ll val = INT_MIN;
    f(i,0,n){
        cout << distance[i] << " ";
        val = max(distance[i],val);
    }
    ll idx = -1;
    f(i,0,n){
        if(distance[i] == val) {idx = i;break;}
    }
    // cout << idx << " " << val ;
}