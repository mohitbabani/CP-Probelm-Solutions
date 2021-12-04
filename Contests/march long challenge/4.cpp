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
bool winner(ll arr[],ll n){
    bool flag = 0;
    f(i,0,n-1){
        if(arr[i] == 2 && arr[i+1] == 0){
            flag = 1;
            arr[i] = arr[i+1] = -1;
            break;
        }
    }
    f(i,0,n){
        if(arr[i] != -1){
            if(arr[i] != 1){
                flag = 0;
            }
        }
    }
    return flag;
}
int main(){
    IOS
    w(t){
        ll n;
        cin>>n;
        ll a[n];
        ll cnt[n]={0};
        f(i,0,n){
            cin>>a[i];
            cnt[ a[i]-1 ]++;
        }
        winner(cnt,n) == 1 ? cout << "First" : cout << "Second";
        cout << "\n";
    }
}