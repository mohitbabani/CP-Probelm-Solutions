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
bool isEmpty(vector<ll> vec){
    f(i,0,vec.size()) if(vec[i] != 0) return 0;
    return 1;
}
int main(){
    IOS
    w(t){
        ll n;
        cin>>n;
        vector<ll> a(101,0);
        f(i,0,n){
            ll x;
            cin >> x;
            a[x]++;
        }
        while(!isEmpty(a)){
            f(i,0,101){
                if(a[i] != 0){
                    cout << i << " ";
                    a[i]--;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}