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
void solve(){
    ll n;
    cin>>n;
    if(n%4==0){
        ll x = n-4;
        cout << (11*x + 60);
        return;
    }
    if(n%4==1){
        if(n==1) {cout<<20;return;}
        ll x = n-5;
        cout << (11*x + 76);
        return;
    }
    if(n%4==2){
        if(n==2) {cout<<36;return;}
        ll x = n-6;
        cout << (11*x + 88);
        return;
    }
    if(n%4==3){
        if(n==3) {cout<<51;return;}
        ll x = n-7;
        cout << (11*x + 99);
    }
}