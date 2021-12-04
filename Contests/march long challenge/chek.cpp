#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define endl "\n"
#define ld long double
#define ull unsigned long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool isPrime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return 0;return 1;}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
void precal();
void solve();
int main(){
    IOS
    precal();
    long long t = 1;
    cin >> t;
    while(t--){
    solve();
    }
    return 0;
}
// ANSWER IS FROM HERE //
vector<ll> primes;
void precal(){
    for(ll i=1;i<=1000;i++){
        if(isPrime(i)) primes.push_back(i);
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> arr;
    map<ll,ll> cnt;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        arr.push_back(x);
        for(auto p : primes){
            if(x % p == 0) cnt[p]++;
        }
    }
    // for(auto i : cnt){
    //     cout << i.first <<" "<< i.second<<"\n";
    // }
    for(ll i=0;i<m;i++){
        ll x;cin>>x;
        ll y = cnt[x];
        ll ans = y*n - ((y*(y+1))/2);
        cout << ans << " ";
    }
    cout << "\n";
}