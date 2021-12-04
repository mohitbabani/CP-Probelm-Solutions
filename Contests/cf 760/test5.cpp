#include<bits/stdc++.h>
using namespace std;
map<int,bool> memo;
bool canSum(int sum, vector<int> coins){
    if(memo.find(sum) != memo.end()) return memo[sum];
    if(sum == 0) return true;
    if(sum < 0) return false; 
    
    for(int coin: coins){
        int rem = sum - coin;
        if(canSum(rem,coins)){
            memo[rem] = true;
            return true;
        }
    }

    memo[sum] = false;
    return false;
}
int main(){
    int n,sum;
    cin >> n >> sum;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int coin;cin>>coin;
        coins.push_back(coin);
    }    
    bool ans = canSum(sum,coins);
    cout << ans << '\n';
}