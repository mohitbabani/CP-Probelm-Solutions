#include<bits/stdc++.h>
using namespace std;
int main(){
    int two[5][2];
    memset(two,0,sizeof(two));
    int start = 1;
    for(auto &p: two){
        for(auto &val: p){
            val = start;
            start++;
        }
    }
    for(auto &p: two){
        for(auto &val: p){
            cout << val << " ";
        }cout << "\n";
    }
}