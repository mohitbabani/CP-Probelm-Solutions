#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf = INT_MAX;
int n,k;
vector<string> s;
vector<vector<int>> coins;
vector<vector<vector<int>>> memo;
int rec(int i,int j,int rem){
    if(memo[i][j][rem] != -1) return memo[i][j][rem];
    if(i == n-1 && j == n-1){
        memo[i][j][rem] = coins[i][j];
        return coins[i][j];
    }

    int current = coins[i][j];
    int right = -inf, down = -inf;
    if(j < n-1){
        if(s[i][j+1] == '#'){
            if(rem > 0){
                right = rec(i,j+1,rem-1) + current;
            }
        }else{
            if(rem == k) right = rec(i,j+1,rem) + current;
            else right = rec(i,j+1,max(0,rem-1)) + current;
        }
    }
    if(i < n-1){
        if(s[i+1][j] == '#'){
            if(rem > 0){
                down = rec(i+1,j,rem-1) + current;
            }
        }else{
            if(rem == k) down = rec(i+1,j,rem) + current;
            else down = rec(i+1,j,max(0,rem-1)) + current;
        }
    }

    memo[i][j][rem] = max(right,down);
    return max(right,down);
}
void solve(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        s.push_back(str);
    }
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            v.push_back(x);
        }
        coins.push_back(v);
    }
    memo.resize(n,vector<vector<int>>(n,vector<int>(2*n,-1)));
    int ans = rec(0,0,k);
    cout << (ans < 0 ? -1 : ans) << '\n';
}
int32_t main(){
    IOS
    int t = 1;
    cin >> t;
    while(t--){
        s.clear();
        coins.clear();
        memo.clear();
        solve();
    }
    return 0;
}