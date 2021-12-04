#include"bits/stdc++.h"
using namespace std;
bool isLongcat(int x){
    x++;
    while(x != 1){
        if(x%2) return false;
        x /= 2;
    }
    return true;
}
int MSB(int x){
    int msw = 0;
    while(x != 1){
        x/=2;
        msw++;
    }
    return msw;
}
int main(){
    int x;
    cin>>x;
    int i=0;
    vector<int> ans;
    while(!isLongcat(x)){
        i = i + 1;
        if(i%2 == 0) {x++; continue;}
        int r = MSB(x);
        if((1 << r) != x) r+=1;
        x ^= ((1 << r) - 1);
        ans.push_back(r);
    }
    x=0;
    cout << i << "\n";
    for(auto val: ans) cout << val << " ";
    cout << "\n";
}
