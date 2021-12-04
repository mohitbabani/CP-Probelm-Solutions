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
vector<ll> sideSize(vector<ll> x){      
    
    vector<ll> temp(1005,0);
    for(ll i=1;i<x.size();i++){
        for(ll j=i-1;j>=0;j--){
            temp[abs(x[i]-x[j])] = 1;
        }
    }
   
    return temp;  // for any array output no of possible unique differences except 0 
}
                                          // return size of set  with max size

int main(){
    IOS
    ll w,h,n,m;
    cin>>w>>h>>n>>m;

	bool bw[w+1] = {0} , bh[h+1] = {0};
   
    f(i,0,n){
    ll x;cin>>x;
	bw[x] =1;
    }

    f(i,0,m){
    ll x;cin>>x;
	bh[x] = 1;
    }
   	
	if(n==1){
        cout<<0;
		return 0;
    }
    
    bool bk[h+1] = {0};

	vector<ll> def;
	f(i,0,w+1){
		if(bw[i]==1){
			def.push_back(i);
		}
	}

	def = sideSize(def);

	ll ans = 0;;
    f(i,0,h+1){
		if(!bh[i]){
			bh[i] =1;
			vector<ll> vec;
			f(j,0,h+1){
				if(bh[j] ==1 ){
					vec.push_back(j);
				}
			}
			vec = sideSize(vec);
			ll cnt= 0;
			f(kk,0,1001){
				if(vec[kk]==1 && def[kk] == 1){
					cnt++;
				}
			}
			ans = max(cnt,ans);
            cout<<cnt<<" ";
			bh[i] =0; 

		}
    }
    
    cout<<"\n"<<ans;
    return 0;
}