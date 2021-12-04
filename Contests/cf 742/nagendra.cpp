#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int v[n+1];
    for(int i=0;i<n;i++){
        v[i] = n-i;
    }

    long long int count = 0;
    while(1){
        if(is_sorted(v,v+n)) break;
        for(int i=0;i<n-1;i++){
            if(v[i] > v[i+1]) {
                swap(v[i],v[i+1]);
                count++;
            }
        }
    }
    cout << count << '\n';
}