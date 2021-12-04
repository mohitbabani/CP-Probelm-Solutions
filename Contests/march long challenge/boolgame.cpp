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
    cin >> t;
while(t--){
    solve();
    cout<<'\n';
}
    return 0;
}
// ANSWER IS FROM HERE //
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    ll base = 1;
 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> g = _in(n);
    vector<vector<ll>> D;
    f(i,0,m){
        vector<ll> vec;
        f(j,0,3){
            ll x;cin>>x;
            vec.push_back(x);
        }
        D.push_back(vec);
    }
    ll last = pow(2,n) - 1;
    vector<string> s;
    for(ll i=0;i<=last;i++){
        string str = decimalToBinary(i);
        string pre_zero;
        f(i,0,n-str.size()) pre_zero.push_back('0');
        str = pre_zero + str;
        // cout << str << "\n";
        s.push_back(str);
    }
    vector<ll> ans;
    for(auto str : s){
        ll t = 0;
        f(i,0,n){
            if(str[i] == '1') t += g[i];
        }
        f(i,0,m){
            ll u = D[i][0];
            ll v = D[i][1];
            ll d = D[i][2];
            bool check = 1;
            for(ll i=u-1;i<v;i++) if(str[i] == '0') {check = 0;break;}
            if(check) t += d;
        }
        ans.push_back(t);
        // cout << str << " " << t << "\n";
    }
    vector<ll> test = ans;
    sort(all(ans),greater<ll>());
    f(i,0,ans.size()) {if(test[i] == ans[0]) {cout << s[i] << "\n"; break;}}
    f(i,0,k) cout << ans[i] << " ";

}