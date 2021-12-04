#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
using namespace std;
ll answer(string x,string y){
    vector<ll> s1(26,0),s2(26,0);
    f(i,0,x.length()){
        s1[x.at(i)-97]++;
    }
    f(i,0,y.length()){
        s2[y.at(i)-97]++;
    }
    ll ans=0;
    f(i,0,26)
    ans += abs(s1[i]-s2[i]);
    return ans;
}
int main(){
    w(t){
        string a,b;
        cin>>a>>b;
        cout<<answer(a,b)<<"\n";
    }
    return 0;
}