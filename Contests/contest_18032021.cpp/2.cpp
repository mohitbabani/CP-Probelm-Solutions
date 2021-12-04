#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    while(t--) solve();
    return 0;
}
bool checkSored(string s){
    f(i,0,s.length()-1) if(s[i] > s[i+1]) return 0;
    return 1;
}
// ANSWER IS FROM HERE //
void solve(){
    string s;
    cin >> s;
    int i = s.find("11");
    int j = s.rfind("00");
    if(i != -1 && j != -1 && j > i){
        cout << "NO\n" ;
        return;
    }
    cout << "YES\n";
}