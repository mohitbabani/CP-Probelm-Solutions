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
    ll n,m;
    cin>>n>>m;
    vector<ll> vec1,vec2;
    ll t=0;
    f(i,0,n){
        ll x;cin>>x;
        t += x;
        vec1.push_back(t);
    }
    t=0;
    f(i,0,m){
        ll x;cin>>x;
        t += x;
        vec2.push_back(t);
    }
    ll mx = 0;
    reverse(all(vec1));
    reverse(all(vec2));
    for(auto i : vec1){
        for(auto j : vec2){
            if(i == j) mx = max(mx,i);
        }
    }
    if(mx == 0){
        cout << "Not possible";
        return;
    }
    cout << mx;
}