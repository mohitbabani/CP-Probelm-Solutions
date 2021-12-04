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
ll cntMagnets(string v,ll k){
    if(v.size() == 0) return 0;
    set<ll> s;
    f(i,0,v.size()) if(v[i] == 'M') s.insert(i);
    ll temp=0; 
    f(i,0,v.size()){
        if (s.size() == 0) break;
        if(v[i] == 'I'){ 
            auto it2 = s.lower_bound(i); 
            auto it1 = it2;
            bool flag=0;
            if( it2 != s.begin() ){
            it1--;
            if( abs(*it1 - i) < k+1 ) { temp++; s.erase(*it1); flag = 1; }
            }
            if(it2 != s.end() && abs(*it2 - i) < k+1 && !flag ){
             temp++; s.erase(*it2);
            }
        }
    }
    return temp;
}
int main(){
    w(t){
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        ll ans=0,ini=0,cnt=0;
        f(i,0,n){
			if(s[i]=='X'){
				string subs = s.substr(ini,cnt);
				ans += cntMagnets(subs,k);
				ini = i+1;
				cnt=0;
			}
			else{
				cnt++;
			}
		}
        string subs = s.substr(ini,cnt);
		ans += cntMagnets(subs,k);
        
        cout<<ans<<"\n";
    }
    return 0;
}