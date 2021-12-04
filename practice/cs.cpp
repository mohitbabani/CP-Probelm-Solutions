#include<bits/stdc++.h>
#define ll long long
#define w(t) long long t ; cin>>t ; while(t--)

using namespace std;
int main(){
    w(t){
        ll h,p;
        cin>>h>>p;
        ll ans;
        while(p!=0){
            h -= p;
            p = p/2;
            if(h<0){
            ans = 1;break;}
            else{
            ans=0;}
        }
        cout<<ans<<endl;
    }
}