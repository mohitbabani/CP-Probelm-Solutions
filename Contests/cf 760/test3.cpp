#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchClosest(int target,vector<int> nums,int l,int r){
        if(target <= nums[l]) return nums[l];
        if(target >= nums[r]) return nums[r];
        
        int i = l, j = r, mid = 0;
        while(i < j){
            mid = (i+j)/2;
            
            if(nums[mid] == target) return nums[mid];
            
            if(target < nums[mid]){
                
                if(mid > l && target > nums[mid-1]) 
                    return getClosest(nums[mid-1],nums[mid],target);
                
                j = mid;
            }else{ // target > nums[mid]
                
                if(mid < r-1 && target < nums[mid+1])
                    return getClosest(nums[mid+1],nums[mid],target);
                
                i = mid+1;
            }
        }
        return nums[mid];
    }
    int getClosest(int val1,int val2,int target){
        if(abs(target-val1) <= abs(target-val2)) 
            return val1;
        return val2;
    }
    auto threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans = -1;
        vector<int> ans2 ;
        for(int i=0;i<n;i++){
            int x = nums[i];
            for(int j=i+1;j<n;j++){
                int y = nums[j];
                for(int k=j+1;k<n;k++){
                    int z = nums[k];
                    int curr = abs(target - x - y - z);
                    if(curr < diff){
                        diff = curr;
                        ans = x+y+z;
                        ans2 = {x,y,z};
                    }
                }
            }
        }
        return ans2;
    }
};
int main(){
    Solution obj;
    vector<int> c = {-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33}; // 1 2 5 7 7 8
    auto ans =  obj.threeSumClosest(c,28);
    // cout << obj.threeSumClosest(c,0) << '\n';
    for(auto i : ans) cout << i << ' ';

}