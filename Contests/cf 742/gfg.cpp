#include<bits/stdc++.h>
using namespace std;
int n,*arr,*st,k;
void construct(int si=0,int sl=0,int sr=n-1){
    if(sl == sr){
        st[si] = (arr[sl] == k);
        return;
    }
    int mid = (sl+sr)/2;
    construct(2*si+1,sl,mid);
    construct(2*si+2,mid+1,sr);
    st[si] = st[2*si+1] + st[2*si+2];
}
int getCount(int si,int sl,int sr,int L,int R){
    if(sl >= L && sr <= R){
        return st[si];
    }
    if(sr < L || sl > R){
        return 0;
    }
    int mid = (sl+sr)/2;
    return getCount(2*si+1,sl,mid,L,R) + 
           getCount(2*si+2,mid+1,sr,L,R);
}
void change(int si,int sl,int sr,int P,int ch){
    if(P < sl || P > sr) return;

    st[si]+=ch;
    int mid = (sl+sr)/2;
    if(sl != sr){
        change(2*si+1,sl,mid,P,ch);
        change(2*si+2,mid+1,sr,P,ch);
    }
}
void query(){
    int type;
    cin >> type;
    if(type == 1){
        int L,R;
        cin >> L >> R;
        L--;R--;
        int count = getCount(0,0,n-1,L,R);
        cout << count << '\n';
    }else{
        int P,X;
        cin >> P >> X;
        P--;
        if(arr[P] != X){
            if(arr[P] == k) change(0,0,n-1,P,-1);
            else if(X == k) change(0,0,n-1,P,1);
        }
        arr[P] = X;
    }
}
int main(){
    cin >> n >> k;
    arr = new int[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    st  = new int[4*n];
    construct();
    int q;
    cin >> q;
    while(q--){
        query();
    }
}