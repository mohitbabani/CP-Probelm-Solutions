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
    w(t){
      ll n;cin>>n;
      vector<ll> rupam(101) , ankit(101) ;
      f(i,0,n){
          ll weight;cin>>weight;
          rupam[weight]++;
      }
      f(i,0,n){
          ll weight;cin>>weight;
          ankit[weight]++;
      }
      ll R = *max_element(rupam.begin(),rupam.end());
      ll A = *max_element(ankit.begin(),ankit.end());
      ll max_rupam,max_ankit;
      for(ll i=100 ; i>=0 ; i--) if(rupam[i] == R) {max_rupam = i; break;}
      for(ll i=100 ; i>=0 ; i--) if(ankit[i] == A) {max_ankit = i; break;}
      if(max_rupam > max_ankit) cout<<"Rupam";
      else if (max_ankit > max_rupam) cout<<"Ankit";
      else cout<<"Tie";
      cout<<"\n";
    }
    return 0;
}