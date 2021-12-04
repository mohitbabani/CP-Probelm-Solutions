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
    cin >> t;
    while(t--){
    solve();
    }
    return 0;
}
// ANSWER IS FROM HERE //
void solve(){
    ll n;cin>>n;
    string s;cin>>s;
    ll cntt=0,cntm=0;
    vector<ll> t,m;
    for(ll i=0;i<n;i++){
        if(s[i] == 'T'){
            cntt++;
            t.push_back(i);
        }
        else{
            cntm++;
            m.push_back(i);
        }
    }
    if(cntm*2 != cntt) {cout <<"NO\n";return;}
    for(ll i=0;i<(cntt/2);i++){
        ll f = t[i];
        ll l = t[cntt-i-1];
        auto itr = lower_bound(all(m),f+1);
        if(itr == m.end()){
            cout << "NO\n";
            return;
        }
        auto idx = itr - m.begin();
        if(m[idx] > l){
            cout << "NO\n";
            return;
        }
        m.erase(itr);
    }
    cout << "YES\n";

}