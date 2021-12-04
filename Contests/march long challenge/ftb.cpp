#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define ld long double
#define ull unsigned long long
#define w(t) long long t=1 ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<endl;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
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
    ll n;cin>>n;
    string a,b;
    cin >> a >> b;
    ll count = 0;
    bool ans = 1;
    f(i,0,n){
        count += (a[i] == '1') - (a[i] == '0');
        if(i == n-1 && a[i] != b[i] && count != 0) {ans = 0;break;}
        else if((a[i] == b[i]) != (a[i+1] == b[i+1]) && count != 0) {ans = 0;break;}
    }
    cout << (ans == 1 ? "YES" : "NO") ;
}