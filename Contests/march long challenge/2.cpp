#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
// #define max(a,b,c) max(max(a,b),c) 
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main(){
    w(t){
        string s;
        cin>>s;
        s.push_back('0');
        ll ans = 0;
        f(i,0,s.length()-1){
            if(s[i]=='1' && s[i+1]=='0') ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}