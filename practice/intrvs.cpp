// // #include<bits/stdc++.h>
// // using namespace std; 
// // // class MovingAverage{
// // // 	queue<int> que;
// // // 	int maxSize;
// // // 	double sum;
// // // 	public:
// // // 	MovingAverage(int size){
// // // 		maxSize = size;
// // // 		sum = 0;
// // // 	}
// // // 	double next(int value){
// // // 		if( que.size() == maxSize ){
// // //             sum -= que.front() ;
// // //             que.pop();
// // //         }
// // //         que.push(value);
// // //         sum += value;
// // //         return sum/que.size();
// // // 	}
	
// // // };
// // // int main(){
// // //     MovingAverage M(3);
// // //     int a[4];
// // //     for(int i=0;i<4;i++) cin>>a[i];
// // //     for(int i=0;i<4;i++) cout << M.next(a[i]) << "\n";
// // // }
// // struct TreeNode {
// //     int val;
// //     TreeNode *left;
// //     TreeNode *right;
// //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// // };

// // class Solution {
// // public:
// //     vector<int> inorderTraversal(TreeNode* root) {
// //         if( root == nullptr ){
// //             vector<int> emptyVector;
// // 			return emptyVector;
// //         }
// //         // int t = inorderTraversal(root);
// //     }
// // };
// // int main(){
// // 	TreeNode c(3),e(5),h(8);
// // 	TreeNode a(1,nullptr,nullptr),d(4,&c,&e),i(9,&h,nullptr);
// // 	TreeNode b(2,&a,&d),g(7,nullptr,&i);
// // 	TreeNode f(6,&b,&g);
// // 	TreeNode* root = nullptr;
// // 	Solution answer;
// // 	vector<int> print = answer.inorderTraversal(root);
// // 	for(int i=0;i<print.size();i++) cout<<print[i]<<" ";
// // }
// #include<bits/stdc++.h>
// using namespace std; 
// #define N 10
// int intArray[N];
// int itemCount = 0;
// bool isEmpty(){return itemCount==0;}
// bool isFull(){return itemCount==N;}
// void insertData(int data){
//     int i;
//     if(!isFull){
//         if(isEmpty) {
//             intArray[0] = data; 
//             itemCount++;
//         }
//         else{
//             for(i=itemCount-1; i>=0; i--){
//                 if(data > intArray[i])
//                     intArray[i+1] = intArray[i];
//                 else{
//                     break;
//                 }
//             }
//             intArray[i+1] = data;
//             itemCount++;
//         }
//     }
// }
// void printAns(){
//     for(int i=itemCount-1;i>=0;i--){
//         cout << intArray[i] << " ";
//     }
// }
// int main(){
//     insertData(3);
//     insertData(5);
//     insertData(9);
//     insertData(1);
//     insertData(12);
//     printAns();
// }
#include<bits/stdc++.h>
using namespace std; 
int factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}
int nCr(int n,int r) {
    int ans = 1;
    if(n-r > r){    
        for(int i=n;i>n-r;i--)
            ans *= i;
        ans /= factorial(r);
    }
    else{
        for(int i=n;i>r;i--)
            ans *= i;
        ans /= factorial(n-r);
    }
    return ans;
}
int main(){
    while(1)
    {
        int n,r;
        cin>>n;
        if(n==-1) break;
        cin>>r;
        cout << nCr(n,r) << endl;

    }
}