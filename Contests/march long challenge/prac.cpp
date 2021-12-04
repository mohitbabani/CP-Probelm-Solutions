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
void solve(){
    string s;
    ll num0[100],num1[100];
    cin >> s;
    ll n = s.length();
    ll pos = -1;
    f(i,0,n){
        if(s[i]=='0'){
            f(j,pos+1,i+1)
            num0[j] = i;
            pos = i;
        }
    }
    f(i,pos+1,n){
        num0[i] = n;
    }
    f(i,0,n) cout << num0[i] << " ";
    newline
    pos = -1;
    f(i,0,n){
        if(s[i] == '1'){
            f(j,pos+1,i+1)
            num1[j] = i;
            pos = i;
        }
    }
    f(i,pos+1,n){
        num1[i] = n;
    }
    f(i,0,n) cout << num1[i] << " ";
}