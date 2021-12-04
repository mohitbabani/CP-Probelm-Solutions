#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define matrix vector<vector<ll>>
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
    ll n;
    cin >> n;
    vector<ll> vec = _in(n);
    vector<vector<ll>> mat;
    vector<ll> t;
    f(i,0,n){
        if(i != n-1 && vec[i] <= vec[i+1]) t.push_back(vec[i]);
        else{
            t.push_back(vec[i]);
            mat.push_back(t);
            t.clear();
        }
    }
    ll sz = mat.size();
    if(sz==1) {cout << "YES" << "\n" << 0;return;}
    if(sz==2) {
        ll first = vec[0];
        ll last = vec[n-1];
        if(last <= first) {cout << "YES" << "\n" << 1;return;}
    }
    cout << "NO";
}