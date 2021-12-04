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
    ll a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    ll n = a+b;
    for(ll i=0;i<n;i++){
        if(s[i] != '?' && s[n-i-1] != '?'){
            if(s[i] != s[n-i-1]) {cout << -1;return;}
        }
        if(s[i] == '?' && s[n-i-1] != '?'){
            s[i] = s[n-i-1];
        }
        if(s[i] != '?' && s[n-i-1] == '?'){
            s[n-i-1] = s[i];
        }
    }
    ll ques=0;
    for(auto i : s){
        if(i == '0') a-=1;
        if(i == '1') b-=1;
        if(i == '?') ques+=1;
    }
    bool eM = n%2 && s[n/2]=='?';
    if(a < 0 || b < 0 || a+b != ques || (eM && a%2==0 && b%2==0)){
        cout << -1;
        return;
    }
    if(a%2 == 1 || b%2 == 1){
        if(s[n/2] != '?'){
            cout << -1;return;
        }
        s[n/2] = (a%2 == 1 ? '0' : '1');
        if(a%2 == 1){
            a--;
        }
        else{
            b--;
        }
    }
    if(a%2 == 1 || b%2 == 1){
        cout << -1;
        return;
    }
    f(i,0,n){
        if(s[i] == '?'){
            if(a>0){    
                s[i] = s[n-i-1] = '0';
                a-=2;
            }
            else if(b>0){
                s[i] = s[n-i-1] = '1';
                b-=2;
            }
        }
    }
    cout << s;
}