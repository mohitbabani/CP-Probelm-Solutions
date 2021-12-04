#include"bits/stdc++.h"
using namespace std;
int main(){
    int n;cin>>n;
    list<int> l;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        l.push_front(x);
    }
    list<int>::iterator itr;
    while(1){
            if(l.empty()){
            cout << "\n" << "list finished";
            return 0;
        }
        cout << l.front() << " ";
        l.pop_front();
    }
}