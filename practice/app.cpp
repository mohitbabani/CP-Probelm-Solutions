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
void solve(){
    ll n,k,p;
    cin>>n>>k>>p;
    vector<stack<ll>> m;
    f(i,0,n){
        vector<ll> vec;
        stack<ll> st;
        f(i,0,k) { ll x;cin>>x;vec.push_back(x); }
        for(ll i=n-1;i>=0;i--){
            st.push(vec[i]);
        }
        m.push_back(st);
    }
    ll ans = 0;
    while(p--){
        ll sum_max = INT_MIN;
        ll sum_max_idx;
        vector<ll> sum(n,0);
        f(i,0,n){
            stack<ll> temp = m[i];
            ll t = p;
            while(t-- && !temp.empty()){
                sum[i] += temp.top();
                temp.pop();
            }
            if(sum_max <= sum[i]) {sum_max = sum[i]; sum_max_idx = i;}
        }
        ans += m[sum_max_idx].top();
        m[sum_max_idx].pop();
    }
    cout << ans << "\n";
}
int main(){
    IOS
    long long test = 1;
    cin >> test;
    while(test--) solve();
    return 0;
}
