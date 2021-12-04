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
ll M = 1000000007;
int main(){
    IOS
    long long t = 1;
    cin >> t;
while(t--){
    solve();
    cout << "\n";
}
    return 0;
}
// ANSWER IS FROM HERE //
ll P(ll n,ll r){
    ll ret = 1;
    for(ll i=n;i>=(n-r+1);i--){
        ret = (ret*i)%M;
    }
    return ret;
}
string decimalToBinary(int n)
{
    //finding the binary form of the number and
    //coneverting it to string.
    string s = bitset<64> (n).to_string();
     
    //Finding the first occurance of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');
     
    if(loc1 != string::npos)
        return s.substr(loc1);
     
    return "0";
}
void solve(){
    ll n;cin>>n;
    vector<ll> v = _in(n);
    ll cnt = count(all(v),0);
    if(cnt == 1){
        cout << 0;
        return;
    }
    if(cnt > 1){
        ll ans = P(n-1,cnt-1);
        ans = (ans*cnt)%M;
        cout << ans ;
        return;
    }
    
}