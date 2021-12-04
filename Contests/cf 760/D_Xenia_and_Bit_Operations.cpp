#include<bits/stdc++.h>
using namespace std;
vector<int> arr,st;
void construct(int si,int sl,int sr,int op){
    if(sl == sr){
        st[si] = arr[sl];
        return;
    }
    int mid = (sl+sr)/2;
    int left = 2*si+1;
    int right = 2*si+2;
    construct(left,sl,mid,!op);
    construct(right,mid+1,sr,!op);
    if(op)
        st[si] = (st[left] | st[right]);
    else 
        st[si] = (st[left] ^ st[right]);
}
void update(int si,int sl,int sr,int idx,int val,int op){
    if(sl == sr){
        if(sl == idx) st[si] = val;
        return;
    }
    int mid = (sl + sr)/2;
    int left = 2*si+1;
    int right = 2*si+2;
    if(idx >= sl && idx <= mid){
        update(left,sl,mid,idx,val,!op);
    }
    if(idx >= (mid+1) && idx <= sr){
        update(right,mid+1,sr,idx,val,!op);
    }
    if(op)
        st[si] = (st[left] | st[right]);
    else 
        st[si] = (st[left] ^ st[right]); 
}
int main(){
    int pw,m;
    cin >> pw >> m;
    int n = 1 << pw;
    arr.resize(n,0);
    st.resize(4*n,0);
    for(int i=0;i<n;i++) cin >> arr[i];
    construct(0,0,n-1,pw%2);
    // cout << st[0] << '\n';
    while(m--){
        int p,b;
        cin >> p >> b;
        p--;
        update(0,0,n-1,p,b,pw%2);
        cout << st[0] << '\n';
    }
}