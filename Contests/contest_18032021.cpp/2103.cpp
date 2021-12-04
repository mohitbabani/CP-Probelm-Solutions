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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    f(i,0,n){
        cin >> a[i];
        sum += a[i];
    }
    ll min_sum = 0;
    f(i,0,k) min_sum += a[i];
    for(ll i=1;i<=n-k;i++){
        if(a[i-1] != a[i+k-1] && a[i-1] == 1) min_sum--;
    }
    ll res = sum - min_sum;
    res += (min_sum*(min_sum+1))/2;
    cout << res << "\n";
}