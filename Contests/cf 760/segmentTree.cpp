#include<bits/stdc++.h>
using namespace std;
void construct(int st[], int si, int arr[], int l, int r){
    if(l == r){
        st[si] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    int left_child = 2*si+1;
    int right_child = 2*si+2;
    construct(st,left_child,arr,l,mid);
    construct(st,right_child,arr,mid+1,r);
    st[si] = st[left_child] + st[right_child];
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int st[4*n];
    memset(st,0,sizeof(st));
    construct(st,0,arr,0,n-1);
    for(int i=0;i<2*n;i++) cout << st[i] << ' ';
}