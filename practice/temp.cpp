#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
using namespace std;

bool checkaz(string s){
    bool temp;
    f(i,0,s.length()){
        char ch = s.at(i);
        if(int(ch) >= 97 && int(ch) <= 122)
        temp=1;
        else{
        temp=0;
        break;
        }
    }
    return temp;
}
bool checkaz(char ch){
    if(int(ch) >= 97 && int(ch) <= 122)
        return 1;
        else
        return 0;
}
int main(){
    string str;
    vector<char> v;
    ll n;
    cin>>n;
    f(i,0,n){
        char ch;
        cin>>ch;
        v.push_back(ch);
    }
    f(i,0,v.size()){
    if(checkaz(v[i]))
    cout<<v[i];
    }
    return 0;
}
