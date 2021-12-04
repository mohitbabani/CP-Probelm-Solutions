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
string attribute_value(vector<string> tags,string tag,string name){
    ll n = tags.size();
    ll tl = tag.length();
    ll nl = name.length();
    f(i,0,n){
        string s = tags[i];
        if(s.substr(1,tl) == tag){
            f(j,0,s.length()) if(s.substr(j,j+nl-1) == name) return s.substr(j+nl+4,s.length()-3);
        }
    }
    return "Not Found!";
}
int main(){
    ll n,q;cin>>n>>q;
    vector<string> tags,queries;
    f(i,0,n) {
        string stemp; 
        getline(cin,stemp);
        tags.push_back(stemp);
        }
    f(i,0,q) {
        string stemp;
        cin>>stemp;
        queries.push_back(stemp);
        }
    f(i,0,q) {
        string s = queries[i];
        ll j = 0;
        while(s[j] != '~')  j++;
        string name = s.substr(j+1,s.length()-1);
        ll temp = j-1;
        while(j != 0){
            if(s[j] == '.') { j++; break; }
            j--;
        }
        string tag = s.substr(j,temp);
        cout << attribute_value(tags,tag,name) << "\n" ; 
    }
    return 0;
}