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
#define newline cout<<endl;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
void solve();
int main(){
    IOS
    long long t = 1;
    cin >> t;
while(t--){
    solve();
    cout<<'\n';
}
    return 0;
}
// ANSWER IS FROM HERE //
ll Answer(matrix mat,ll k){
    ll n = mat.size()-1;
    ll m = mat[0].size()-1;
    ll order = 1;
    ll count = 0;
    ll ans;
    while(order < n + 1){
        ll i = order;
        ll j = m;
        while(i<n+1){
            ll x = i - order + 1;
            ll y = j - order + 1;
            ll z = mat[i][j] - mat[x-1][j] - mat[i][y-1] + mat[x-1][y-1];
            if(z < order*order*k) i+=1;
            else{
                ll start = order;
                ll end = m;
                while(start <= end){
                    ll mid = (start+end)/2;
                    x = i - order + 1;
                    y = mid - order + 1;
                    z = mat[i][mid] - mat[x-1][mid] - mat[i][y-1] + mat[x-1][y-1];
                    if(z < order*order*k) start = mid+1;
                    else{
                        ans = mid;
                        end = mid-1;
                    }
                } 
                count += m - ans + 1;
                i += 1;
            }
        }
        order += 1;
    }
    return count;
}
matrix createTable(matrix mat,matrix dp){
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
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    matrix mat;
    f(i,0,n){
        vector<ll> vec(m);
        f(j,0,m) cin >> vec[j];
        mat.push_back(vec);
    }
    matrix dp;
    f(i,0,n){
        vector<ll> vec(m,0);
        dp.push_back(vec);
    }
    dp = createTable(mat,dp);
    matrix Mat(n+1,vector<ll> (m+1));
    f(i,0,n+1){
        f(j,0,m+1) Mat[i][j] = 0;
    }
    f(i,1,n+1){
        f(j,1,m+1) Mat[i][j] = dp[i-1][j-1];
    }
    ll ans = Answer(Mat,k);
    cout << ans ;
}