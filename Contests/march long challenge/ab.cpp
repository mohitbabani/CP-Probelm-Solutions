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
    ll n,q;
    cin >> n >> q;
    vector<ll> a = _in(n);
    vector<ll> t = _in(q);
    ll top[51] = {0};
    for(ll i=n-1;i>=0;i--){
        ll x = a[i];
        top[x] = i+1;
    }
    f(i,0,q){
        ll x = t[i];
        cout << top[x] << " ";
        ll val = top[x];
        f(i,1,51){
            if(i==x) top[i] = 1;
            else{
                if(top[i] != 0 && top[i] < val) top[i]++;
            }
        }
    }
}