#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
void solveOneTestcase();
int main(){
    string s;
    cin>>s;
    vector<char> v;
    for(ll i=0;i<s.length();i=i+2){
        v.push_back(s[i]);
    }
    sort(v.begin(),v.end());
    f(i,0,v.size()-1){
        cout<<v[i]<<"+";
    }
    cout<<v[v.size()-1];
    return 0;
}