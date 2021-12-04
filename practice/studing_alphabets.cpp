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
bool ans(string s,string w){

    f(i,0,w.length()){
        bool temp=0;
        f(j,0,s.length()){
            if(w[i] == s[j]) { temp = 1; break; }  
        }
        if(temp == 0) return 0;
    }
    return 1;

}
int main(){
    IOS
    string s;cin>>s;
    ll n;cin>>n;
    vector<string> w;
    f(i,0,n){
        string ss;cin>>ss;
        w.push_back(ss);
    }

    f(i,0,n){
        ans(s,w.at(i)) == 1 ? cout<<Y : cout<<N;
    }
    return 0;
}