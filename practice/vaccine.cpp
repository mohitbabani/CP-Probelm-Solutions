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
int main(){
    
        ll d1,v1,d2,v2,p;
        cin>>d1>>v1>>d2>>v2>>p;
        ll t1 = min(d1,d2) , t2 = max(d1,d2);
        ll temp;
        if(t1 == d1)  temp = v1;
        else temp = v2; 
        ll ans = t1-1;        
        while(p > 0){
            if(t1 < t2) { p -= temp; ans++ ; t1++; }
            else {p -= (v1+v2); ans++; }
        }
        cout<<ans;
    return 0;
}