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
// ANSWER IS FROM HERE //
void solve(){
    string a,b;
    cin >> a >> b;
    vector<string> an,bn;
    f(i,0,a.length()){
        f(j,1,a.length()+1-i){
            an.push_back(a.substr(i,j));
        }
    }
    f(i,0,b.length()){
        f(j,1,b.length()+1-i){
            bn.push_back(b.substr(i,j));
        }
    }
    ll max_size = 0;
    f(i,0,an.size()){
        f(j,0,bn.size()){
            if(an[i] == bn[j]){
                ll t = an[i].length();
                max_size = max(max_size,t);
            }
        }
    }
    ll ans = a.length() + b.length() - 2*max_size;
    cout << ans << "\n";
}