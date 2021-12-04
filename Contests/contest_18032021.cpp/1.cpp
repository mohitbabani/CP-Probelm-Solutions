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
        stack<ll> st;
        ll arr[k];
        f(i,0,k) cin >> arr[i];
        for(ll i=k-1;i>=0;i--){
            st.push(arr[i]);
        }
        m.push_back(st);
    }
    vector<vector<ll>> sum(n,vector<ll> (k+1));
    f(i,0,n){
        stack<ll> temp = m[i];
        sum[i][0] = 0;
        ll j = 1;
        while(!temp.empty()){
            sum[i][j] = sum[i][j-1] + temp.top();
            temp.pop();
            j++;
        }
    }
    // f(i,0,n) {f(j,0,k+1) cout << sum[i][j] << " "; cout << "\n";}
    vector<vector<ll>> dp(n+1,vector<ll> (p+1));
    f(i,1,n+1){
        f(j,0,p+1){
            dp[i][j] = 0;
            f(x,0,min(j,k)+1) dp[i][j] = max(dp[i][j],sum[i-1][x]+dp[i-1][j-x]);       
        }
    }
    cout << dp[n][p] << "\n";
}
int main(){
    IOS
    long long test = 1;
    cin >> test;
    ll i = 1;
    while(test--){
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }
    return 0;
}
// f(i,0,n) {
    //     stack<ll> temp = m[i];
    //     while(!temp.empty()) { cout << temp.top() << " "; temp.pop(); }
    //     cout << "\n";
    // }