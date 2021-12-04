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
    IOS
    w(t){
        ll n;
        cin>>n;
        vector<ll> freq(11,0);
        f(i,0,n){
            ll x;
            cin>>x;
            freq[x]++;
        }
        vector<ll> freq_of_freq(10001,0);
        f(i,1,11){
            if(freq[i] != 0)
            freq_of_freq[freq[i]]++;
        }
        ll max=0,id;
        f(i,1,10001){
            if(freq_of_freq[i] > max){
            max = freq_of_freq[i];
            id = i;
            }
        }
        cout<<id<<"\n";
    }
    return 0;
}