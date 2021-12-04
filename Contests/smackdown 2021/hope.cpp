#include<bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        TreeNode *a = new TreeNode(3);
        vector<TreeNode*> v;
        auto p = a;
        v.push_back(p);
        return v;
    }
};
const int mod = 1e9 + 7;
vector<int> memo((int)1e7,-1);
int catalan(int n){
    if(n <= 1) return 1;
    if(memo[n] != -1) return memo[n];
    int res = 0 ;
    for(int i=0;i<n;i++){
        int val = (catalan(i) * catalan(n-i-1)) % mod;
        res = (res + val) % mod;
    }
    memo[n] = res;
    return res % mod;
}
#define cpp_int double
class Solution
{
    vector<cpp_int> memo;
    cpp_int catalyn(int n){
        if(n <= 1) return 1;
        if(memo[n] != -1) return memo[n];
        cpp_int res = 0;
        for(int i=0;i<n;i++){
            res = res + catalyn(i)*catalyn(n-i-1);
        }
        memo[n] = res;
        return res;
    }
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        for(int i=0;i<n;i++) memo.push_back(0);
        return catalyn(n);
    }
};

signed main(){
    int n;
    cin >> n;
    cout << catalan(n) << '\n';
}