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
    string s;
    cin >> s;
    ll x=0;
    ll n=s.length();
    for(auto i:s) if(i == 'a') x+=1;
    if(x==n){
        cout << "NO";
        return;
    }
    
    if(n%2==0){
        ll m = n/2;
        string s1,s2;
        for(ll i=0;i<m;i++) s1.push_back(s[i]);
        for(ll i=n-1;i>=m;i--) s2.push_back(s[i]);
        if(s1!=s2){
            s.insert(m,"a");
            cout << "YES\n" <<  s;
            return;
        }
        cout << "YES\n" << "a" << s;
        return;
    }
    ll m = n/2;
    char ch = s[m];
    string s1,s2;
    for(ll i=0;i<=m-1;i++) s1.push_back(s[i]);
    for(ll i=n-1;i>=m+1;i--) s2.push_back(s[i]);
    if(s1!=s2){
        s.insert(m,"a");
        cout << "YES\n" << s ;
        return;
    }
    cout << "YES\n" << "a" << s;
}
