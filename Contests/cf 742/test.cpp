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
int getSum(int st[],int si,int sl,int sr,int l,int r){
    if(sl >= l && sr <= r){
        return st[si];
    }
    if(sr < l || sl > r){
        return 0;
    }
    int mid = (sl+sr)/2;
    return getSum(st,2*si+1,sl,mid,l,r) + 
           getSum(st,2*si+2,mid+1,sr,l,r);
}
void update(int st[],int si,int sl,int sr,int pos,int diff){
    if(pos < sl || pos > sr) return;

    st[si] += diff;
    int mid = (sl+sr)/2;
    if(sl != sr){
        update(st,2*si+1,sl,mid,pos,diff);
        update(st,2*si+2,mid+1,sr,pos,diff);
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int st[4*n];
    memset(st,0,sizeof(st));
    construct(st,0,arr,0,n-1);
    while(1){
        int q,x,y;
        cin >> q;
        if(q == 0) return 0;
        cin >> x >> y;
        if(q == 1) {
            cout << getSum(st,0,0,n-1,x,y) << '\n';
        }else{
            int diff = y - arr[x];
            update(st,0,0,n-1,x,diff);
        }
    }
}