#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define w(t) long long t=1 ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<endl
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
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
    ll n;
    cin >> n;
    vector<ll> even,odd;
    f(i,0,n){
        ll x;cin>>x;
        if(i%2) odd.push_back(x);
        else even.push_back(x);
    }
    ll min_even = *min_element(even.begin(),even.end());
    ll cnt_even = 0;
    f(i,0,even.size()){
        if(even[i] == min_even) break;
        else{
            cnt_even++;
        }
    }
    ll min_odd = *min_element(odd.begin(),odd.end());
    ll cnt_odd = 0;
    f(i,0,odd.size()){
        if(odd[i] == min_odd) break;
        else{
            cnt_odd++;
        }
    }
    ll ans = 0;
    if(cnt_odd >= cnt_even){
        f(i,0,cnt_odd+1){
            if(odd[i] == min_odd) ans += (n-cnt_odd)*min_odd;
            else ans += odd[i];
        }
        f(i,0,cnt_odd+1){
            if(even[i] == min_even) ans += (n-cnt_odd)*min_even;
            else ans += even[i];
        }
    }
    else{
        f(i,0,cnt_even+1){
            if(even[i] == min_even) ans += (n-cnt_even)*min_even;
            else ans += even[i];
        }
        f(i,0,cnt_even){
            if(odd[i] == min_odd) ans += (n-(cnt_even-1))*min_odd;
            else ans += odd[i];
        }
    }
    cout << ans << "\n";
}