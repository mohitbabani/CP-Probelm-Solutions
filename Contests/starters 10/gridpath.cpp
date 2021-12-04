#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
void solve(){
    int n,k;
    cin >> n >> k;
    string s[n+1];
    for(int i=1;i<=n;i++){
        cin >> s[i];
        s[i] = 'x' + s[i];
    }
    int arr[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    int dp[n+1][n+1];
    int rem[n+1][n+1];
    memset(dp,-inf,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][0] = dp[0][i] = 0;
        rem[i][0] = rem[0][i] = k;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int mx = -inf;
            if(s[i][j] == '#'){
                if(rem[i-1][j] != 0 || rem[i][j-1] != 0){
                    if(rem[i-1][j] == 0){
                        dp[i][j] = dp[i][j-1] + arr[i][j];
                        rem[i][j] = rem[i][j-1] - 1;
                    }
                    else if(rem[i][j-1] == 0){
                        dp[i][j] = dp[i-1][j] + arr[i][j];
                        rem[i][j] = rem[i-1][j] - 1;
                    }
                    else{
                        if(dp[i-1][j] > dp[i][j-1]){
                            dp[i][j] = dp[i-1][j] + arr[i][j];
                            rem[i][j] = rem[i-1][j] - 1;
                        }else{
                            dp[i][j] = dp[i][j-1] + arr[i][j];
                            rem[i][j] = rem[i][j-1] - 1;
                        }
                    }
                }else{
                    dp[i][j] = -inf;
                    rem[i][j] = 0;
                }
            }else{ // s[i][j] == '.'
                if(dp[i-1][j] > dp[i][j-1]){
                    dp[i][j] = dp[i-1][j] + arr[i][j];
                    if(rem[i-1][j] == k) rem[i][j] = k;
                    else rem[i][j] = max(0,rem[i-1][j]-1);
                }else{
                    dp[i][j] = dp[i][j-1] + arr[i][j];
                    if(rem[i][j-1] == k) rem[i][j] = k;
                    else rem[i][j] = max(0,rem[i][j-1]-1);
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout << rem[i][j] << ' ';
        }
        cout << '\n';
    }
    int ans = dp[n][n];
    if(ans < 0) ans = -1;
    cout << ans << '\n';

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}