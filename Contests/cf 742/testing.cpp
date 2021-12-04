#include<bits/stdc++.h>
using namespace std;
class NumArray {
public:
    vector<int> nums,st;
    int n;
    NumArray(vector<int>& nums){ 
        this->nums = nums;
        this->n = nums.size();
        this->st.resize(4*n,0);
        construct(0,0,n-1);
    }
    void construct(int si,int sl,int sr){
        if(sl == sr){
            st[si] = nums[sl];
            return;
        }
        
        int mid = (sl+sr)/2;
        int left = 2*si+1;
        int right = 2*si+2;
        construct(left,sl,mid);
        construct(right,mid+1,sr);
        st[si] = st[left] + st[right];
    }
    void myUpdate(int si,int sl,int sr,int index,int diff){
        if(index < sl || index > sr){
            return;
        }
        
        st[si] += diff;
        int mid = (sl+sr)/2;
        if(sl != sr){
            myUpdate(2*si+1,sl,mid,index,diff);
            myUpdate(2*si+2,mid+1,sr,index,diff);
        }
    }
    void update(int index, int val) {
        int diff = val - st[index];
        myUpdate(0,0,n-1,index,diff);
        nums[index] = val;
    }
    int mySumRange(int si,int sl,int sr,int l,int r){
        if(sl >= l && sr <= r){
            return st[si];
        }
        if(sl > r || sr < l){
            return 0;
        }
        
        int mid = (sl + sr)/2;
        int left = 2*si+1;
        int right = 2*si+2;
        return mySumRange(left,sl,mid,l,r) + 
               mySumRange(right,mid+1,sr,l,r);
    }
    int sumRange(int left, int right) {
        return mySumRange(0,0,n-1,left,right);
    }
};
int main(){
    vector<int> v = {1,3,5};
    NumArray obj(v);
    obj.update(1,2);
    for(auto i: obj.nums) cout << i << ' ';cout << '\n';
    for(auto i: obj.st) cout << i << ' ';cout << '\n';

    // cout << obj.sumRange(0,2);

}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */