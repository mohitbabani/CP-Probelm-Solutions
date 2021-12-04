#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(vec) vec.begin(),vec.end()
#define ld long double
#define ull unsigned long long
#define w(t) long long t=1 ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<endl
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
void solve();
int main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
// ANSWER IS FROM HERE //
void solve(){
    ll n;cin>>n;
    map<ll,ll> v;
    f(i,0,n){
        ll x;cin>>x;
        v[x]++;
    }
    priority_queue<ll> q;
    for(auto i : v){
        ll x = i.second;
        q.push(x);
    }
    ll ans = n;
    while(q.size() >= 2){
        ll x = q.top();
        q.pop();
        ll y = q.top();
        q.pop();
        x--;
        y--;
        ans -= 2;
        if(x != 0) q.push(x);
        if(y != 0) q.push(y);
    }
    cout << ans << "\n";
}