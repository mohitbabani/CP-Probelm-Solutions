#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define matrix vector<vector<ll>>
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
ll idx = 1;
int main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--) {solve();cout<<endl;}
    return 0;
}
// ANSWER IS FROM HERE //
matrix createTable(matrix mat,ll k,ll p,matrix dp){
    dp[0][0] = mat[0][0];
    ll n = mat.size();
    ll m = mat[0].size();
    f(i,1,m) dp[0][i] = mat[0][i] + dp[0][i-1];
    f(i,1,n) dp[i][0] = mat[i][0] + dp[i-1][0];

    f(i,1,n){
        f(j,1,m){
            dp[i][j] = mat[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    return dp;
}
ll countSubMatrixUtil(matrix dp,ll k,ll p){
    ll count = 0;
    ll subMatSum = 0;
    ll n = dp.size();
    ll m = dp[0].size();
    for(ll i=k-1;i<n;i++){
        for(ll j=k-1;j<m;j++){
            if(i == (k-1) || j == (k-1)){
                if(i == (k-1) && j == (k-1)) subMatSum = dp[i][j];
                else if(i == (k-1)) subMatSum = dp[i][j] - dp[i][j-k];
                else subMatSum = dp[i][j] - dp[i-k][j];
            }
            else{
                subMatSum = dp[i][j] + dp[i-k][j-k] - dp[i-k][j] - dp[i][j-k];
            }   
            if(subMatSum >= p) count++;
        }
    }
    return count;
}
ll countSubMatrix(matrix mat,ll k,ll p){
    matrix dp;
    ll n = mat.size();
    ll m = mat[0].size();
    f(i,0,n){
        vector<ll> vec(m,0);
        dp.push_back(vec);
    }
    dp = createTable(mat,k,p,dp);
    return countSubMatrixUtil(dp,k,p);
}
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    matrix mat;
    f(i,0,n){
        vector<ll> vec(m);
        f(j,0,m) cin >> vec[j];
        mat.push_back(vec);
    }
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ll sum = i*i*k;
        ans += countSubMatrix(mat,i,sum);
    }
    cout << ans ;
}