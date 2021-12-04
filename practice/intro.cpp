#include<bits/stdc++.h>
using namespace std;
vector<int> rotateLeft(int,vector<int>);
int main(){
    int n,d;
    cin>>n>>d;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    vector<int> rotatedVector=rotateLeft(d,v);
    
    for(auto itr=rotatedVector.begin();itr!=rotatedVector.end();itr++)
    cout<<*itr<<" ";

    return 0;
}
vector<int> rotateLeft(int x,vector<int> y){
    vector<int> temp;
    for(int i=0;i<y.size();i++){
        if((i-x)>=0)
        temp[i-x]=y[i];
        else
        temp[i+x]=y[i];
    }
    return temp;
}