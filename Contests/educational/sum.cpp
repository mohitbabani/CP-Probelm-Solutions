#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {1,3,45,6,5,43,2};
    for(int i: a){
        if(i % 2) i = 2;
    }
    for(int i: a){
        cout << i << " ";
    }
}