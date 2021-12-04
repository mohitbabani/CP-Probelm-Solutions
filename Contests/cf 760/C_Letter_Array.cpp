#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    public:
    int n;
    string s;
    vector<vector<int>> st;
    void construct(int ch,int si,int l,int r){
        if(l == r){
            st[ch][si] = (s[l] == char(ch+65));
            return;
        }
        int mid = (l+r)/2;
        int left_child = 2*si+1;
        int right_child = 2*si+2;
        construct(ch,left_child,l,mid);
        construct(ch,right_child,mid+1,r);
        st[ch][si] = st[ch][left_child] + st[ch][right_child];
    }
    SegmentTree(string s){
        this->s = s;
        this->n = s.length();
        this->st.resize(26,vector<int>(4*n));
        for(int i=0;i<26;i++){
            this->construct(i,0,0,n-1);
        }
    }
    int count(int ch,int si,int sl,int sr,int l,int r){
        if(l > sr || r < sl){
            return 0;
        }
        if(sl >= l && sr <= r){
            return st[ch][si];
        }
        int mid = (sl + sr)/2;
        int left_child = 2*si+1;
        int right_child = 2*si+2;
        return count(ch,left_child,sl,mid,l,r) + 
               count(ch,right_child,mid+1,sr,l,r);
    }
    void printFreq(int l,int r){
        for(int i=0;i<26;i++){
            int val = count(i,0,0,n-1,l,r); 
            cout << val << ' ';
        }
        cout << '\n';
    }
    void update(int ch,int si,int sl,int sr,int idx,int diff){
        if(idx > sr || idx < sl){
            return;
        }
        st[ch][si] += diff;
        if(sl == sr) return;
        int mid = (sl+sr)/2;
        int left_child = 2*si+1;
        int right_child = 2*si+2;
        update(ch,left_child,sl,mid,idx,diff);
        update(ch,right_child,mid+1,sr,idx,diff);
    }
    void sortPlease(int l,int r){
        string temp = s.substr(l,r-l+1);
        sort(s.begin()+l,s.begin()+(r+1));
        string incr = s.substr(l,r-l+1);
        for(int i=0;i<temp.length();i++){
            update(int(temp[i])-65,0,0,n-1,l+i,-1);
            update(int(incr[i])-65,0,0,n-1,l+i,1);
        }
    }
};
void solve(){
    string s;
    cin >> s;
    SegmentTree obj(s);
    int q;
    cin >> q;
    while(q--){
        char ch;
        int l,r;
        cin >> ch >> l >> r;
        if(ch == 'g'){
            obj.printFreq(l,r);
        }else{
            obj.sortPlease(l,r);
        }
    }
}
int main(){
    int t;
    cin >> t;
    for(int test=1;test<=t;test++){
        cout << "Case #" << test << ":\n";
        solve();
    }
    return 0;
}