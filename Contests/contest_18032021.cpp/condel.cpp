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
    vector<ll> k_sum(n-k+1);
    f(i,0,k) k_sum[0] += a[i];
    for(ll i=1;i<=n-k;i++){
        if(a[i-1] != a[i+k-1]){
            if(a[i-1] == 1) k_sum[i] = k_sum[i-1] - 1 ;
            else k_sum[i] = k_sum[i-1] + 1 ;
        }
        else k_sum[i] = k_sum[i-1];
    }
    ll min_sum = *min_element(k_sum.begin(),k_sum.end());
    ll res = sum - min_sum;
    res += (min_sum*(min_sum+1))/2;
    cout << res << "\n";
}