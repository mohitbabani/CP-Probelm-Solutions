#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[6][6];
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cin>>a[i][j];
        }
    }
    set<int> b;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            b.insert(a[i][j]+a[i][j+1]+a[i][j+2]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2]+a[i+1][j+1]);
        }
    }
    int max_element; 
    if (!b.empty()) 
        max_element = *(b.rbegin());
    cout<<max_element;
    return 0;
}