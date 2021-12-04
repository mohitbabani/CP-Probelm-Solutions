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
void solve();
int main(){
    IOS
    long long t = 1;
    // cin >> t;
    while(t--){
    solve();
    }
    return 0;
}
// ANSWER IS FROM HERE //
void solve(){
    ll n;
    cin>>n;
    vector<ll> p = _in(n);
    ll q;cin>>q;
    for(ll i=0;i<q;i++){
        ll dis=0;
        ll x,k;
        cin>>x>>k;
        for(ll i=x-1;i<n;i++){
            if(k <= 0) break;
            if(k <= p[i]){
                dis += (i - (x-1))*k; 
                p[i] -= k;
                k = 0;
            }
            else{
                dis += (i - (x-1))*p[i]; 
                k -= p[i];
                p[i] = 0;
            }
        }
        cout << dis << "\n";
    }
}