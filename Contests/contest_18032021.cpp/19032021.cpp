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
ll depth(vector<ll> a,ll l,ll r,ll v){
    if(r >= l){
        int mid = max_element(a.begin()+l,a.begin()+r+1) - a.begin();
        if(mid == v) return 0;
        if(mid > v) return 1 + depth(a,l,mid-1,v);
        return 1 + depth(a,mid+1,r,v);
        }
    return 0;
}
void solve(){
    ll n;
    cin >> n;
    vector<ll> vec(n);
    f(i,0,n) cin >> vec[i];
    vector<ll> d(n);
    f(i,0,n){
        d[i] = depth(vec,0,n-1,i);
    }
    _out(d);
}
int main(){
    IOS
    long long t;
    cin >> t;
    while(t--) solve();
    return 0;
}