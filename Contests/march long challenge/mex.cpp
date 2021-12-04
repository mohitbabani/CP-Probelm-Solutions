#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define ld long double
#define ull unsigned long long
#define w(t) long long t=1 ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<endl
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
void solve();
int main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--) {solve();cout<<endl;}
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
string decimalToBinary(ll n)
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
bool checkSubsequence(string mex,string s){
    
}
void solve(){
    string s;
    cin >> s;
    ll n = s.length();
    ll x = accumulate(all(s),0) - 48*n;
    vector<string> mex(n+1);
    f(i,0,n+1){
        if(i == 0) mex[i] = '0';
        else if(i == 1){
            if(*(s.end()-1) == '1') mex[i] = '0';
            else mex[i] = '1'; 
        }
        else{
            bool subsq = checkSubsequence(mex[i-1],s.substr(n-i,i));
            if(!subsq){
                mex[i] = mex[i-1];
            }
            else{
                mex[i] = find_mex();
            }
        }
    }
}