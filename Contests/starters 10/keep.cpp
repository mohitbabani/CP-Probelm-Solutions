#include<bits/stdc++.h>
using namespace std;
#define _fast_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int MAXN = 150;
const int MAXK = 2*MAXN;
const int inf = INT_MAX;
int n,k;
string s[MAXN];
int coins[MAXN][MAXN];
int memo[MAXN][MAXN][MAXK];
int minimum_cost(int i,int j,int rem){
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
                right = minimum_cost(i,j+1,rem-1);
            }
        }else{
            if(rem == k) right = minimum_cost(i,j+1,rem);
            else right = minimum_cost(i,j+1,max(0,rem-1));
        }
    }
    if(i < n-1){
        if(s[i+1][j] == '#'){
            if(rem > 0){
                down = minimum_cost(i+1,j,rem-1);
            }
        }else{
            if(rem == k) down = minimum_cost(i+1,j,rem);
            else down = minimum_cost(i+1,j,max(0,rem-1));
        }
    }

    memo[i][j][rem] = max(right,down) + current;
    return memo[i][j][rem];
}
int main(){
    _fast_
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> s[i];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> coins[i][j];
            
        
        for(int i=0;i<n;i++) 
            for(int j=0;j<n;j++) 
                for(int x=0;x<=k;x++) 
                    memo[i][j][x]=-1;

        int ans = minimum_cost(0,0,k);
        cout << (ans < 0 ? -1 : ans) << '\n';
    }
    return 0;
}