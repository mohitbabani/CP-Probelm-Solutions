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
    // cin >> t;
    while(t--) solve();
    return 0;
}
// ANSWER IS FROM HERE //
void solve(){
    ll n;
    cin >> n;
    vector<ll> vec(n);
    f(i,0,n) cin >> vec[i];
    vector<vector<ll>> mat;
    vector<ll> t;
    f(i,0,n){
        if(i != n-1 && vec[i] < vec[i+1]) t.push_back(vec[i]);
        else{
            t.push_back(vec[i]);
            mat.push_back(t);
            t.clear();
        }
    }
    ll sz = mat.size();
    if(sz==1) {cout << n ; return;}
    ll ans = 1;
    f(i,0,sz-1){
        vector<ll> v1 = mat[i],v2 = mat[i+1];
        ll s1 = v1.size(),s2 = v2.size();
        if(s1!=1 && s2!=1){
            if((v1[s1-1]+1 < v2[1]) || (v2[0]-1 > v1[s1-2])) ans = max(ans,s1+s2);
        }
        else{
            ans = max(ans,s1+s2);
        }
    }
    f(i,0,sz){
        ll cap = mat[i].size();
        ans = max(ans,cap+1);
    }
    cout << ans ;
}