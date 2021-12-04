#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
// #define max(a,b,c) max(max(a,b),c) 
#define ld long double
#define ull unsigned long long
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
void printArray(vector<ll> vec){
    f(i,0,vec.size()) cout << vec[i] << " ";
    cout << "\n";
}
int main(){
    IOS
    w(t){
        ll n,m;
        cin >> n >> m;
        vector<ll> a(m,0);
        f(i,0,n){
            ll x;
            cin >> x;
            x = x%m;
            a[x]++;
        }
        ll cnt = 0;
        for(ll i=1;i<=((m-1)/2);i++){
            ll y = a[i];
            ll x = a[m-i];
            if(y == x && y != 0) cnt++;
            else cnt += abs(y-x);
        }
        if(m%2 == 0 && a[m/2] != 0) cnt++;
        if(a[0] != 0) cnt++;
        cout << cnt << "\n"; 
    }
    return 0;
}