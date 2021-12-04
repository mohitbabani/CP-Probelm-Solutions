#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<"\n";
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void _out(vector<ll> arr) {f(i,0,arr.size()) cout<<arr[i]<<" "; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<" "; cout<<endl;}
void solve();
int main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
// ANSWER IS FROM HERE //
void solve(){
        ll n,k;
        cin >> n >> k;
        n -= (k-3);
        f(i,0,k-3) cout << 1 << " ";

        if(n % 2){
            ll ans = (n-1)/2;
            cout << ans << " " << ans << " " << 1 ;
        }
        else{
            ll val = n/2;
            if(val % 2){
                cout << val - 1 << " " << val - 1 << " " << 2;
            }
            else{
                cout << val << " " << val/2 << " " << val/2;
            }
        }
        cout << "\n";
}