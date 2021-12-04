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
bool strIncr(vector<ll> vec){
    for(ll i=0;i<vec.size()-1;i++){
        if(vec[i] >= vec[i+1]) return false;
    }
    return true;
}
void solve(){
    ll n;cin>>n;
    ll b[501] = {0};
    f(i,0,n){
        ll x;cin>>x;
        b[x]++;
    }
    f(i,0,501) if(b[i] != 0) cout << i << " " << b[i] << "\n";
    vector<ll> vec;
    ll mx=-1;
    for(ll i=1;i<=500;i++){
        if(b[i]){
            vec.push_back(i);
            b[i]--;
            mx = max(mx,i);
        }
    }
    bool flag = 0;
    for(ll i=500;i>=1;i--){
        if(b[i]){
            if(i != mx){
                vec.push_back(i);
                b[i]--;
            }
        }
    }
    bool ch = strIncr(vec);
    if(ch) reverse(all(vec));
    _out(vec);
}