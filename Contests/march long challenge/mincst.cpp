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
while(t--){
    solve();
}
    return 0;
}
// ANSWER IS FROM HERE //
void char_front(ll k){
    for(ll i=97;i<97+k;i++){
        cout << char(i) ;
    }
}
void char_back(ll k){
    for(ll i=97+k-1;i>=97;i--){
        cout << char(i) ;
    }
}
void solve(){
    ll n,k;
    cin >> n >> k;
    if(n <= k){
        char_front(n);
        return;
    }
    ll d = n/k;
    ll rem = n%k;
    while(1){
        char_front(k);d--;
        if(d==0) break;
        char_back(k);d--;
        if(d==0) break;
    }
    ll temp = n/k;
    if(temp%2){
        char_back(rem);
    }else{
        char_front(rem);
    }
}