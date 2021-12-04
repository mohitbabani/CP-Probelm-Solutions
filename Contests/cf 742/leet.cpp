#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<int> nums,memo;
    vector<vector<int>> graph;
    void construct(){
        n = nums.size();
        memo.resize(n,-1);
        graph.resize(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] < nums[j]){
                    graph[i].push_back(j);
                }
            }
        }
    }
    int height(int node){
        if(memo[node] != -1) return memo[node];
        
        int mx = 0;
        for(auto i: graph[node]){
            int current = height(i);
            if(current > mx){
                mx = current;
            }
        }
        memo[node] = mx+1;
        return memo[node];
    }
    int count(int node,int size){
        bool not_available = true;
        int cnt = 0;
        for(int i: graph[node]){
            if(memo[i] == (size-1)){
                not_available = false;
                cnt += count(i,size-1);
            }    
        }
        if(not_available){
            return 1;
        }
        return cnt;
    }
    int findNumberOfLIS(vector<int> nums) {
        this->nums = nums;
        construct();
        int mx = -1;
        for(int i=0;i<n;i++){
            memo[i] = height(i);
            mx = max(mx,memo[i]);
        }
        int cnt = 0;
        // for(int i=0;i<n;i++){
        //     if(memo[i] == mx){
        //         int curr_cnt = count(i,mx);
        //         cnt += curr_cnt;
        //     }
        // }
        return cnt;
    }
};
// int main(){
//     vector<int> v = {1,3,5,4,7};
//     Solution obj;
//     obj.findNumberOfLIS(v);
//     auto g = obj.graph;
//     for(auto i: g){
//         for(auto j: i){
//             cout << j << ' '; 
//         }cout << '\n';
//     }
//     for(auto i: obj.memo) cout << i << ' ';
// }
int main(){
    vector<int> c  = {0,2,1,4,3,6,5,8,7,10,9,12,11,14,13,16,15,18,17,20,19,22,21,24,23,26,25,28,27,30,29,32,31,34,33,36,35,38,37,40,39,42,41,44,43,46,45,48,47,50,49,52,51,54,53,56,55,58,57,60,59,61};
    vector<int> big;
    for(int i=1;i<=1000;i++){
        big.push_back(i);
    }
    for(int i=1000;i>=1;i--){
        big.push_back(i);
    }
    Solution obj;
    int ans = obj.findNumberOfLIS(big);
    cout << ans << '\n';
}