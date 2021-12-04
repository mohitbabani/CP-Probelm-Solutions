#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//#define int long long
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;
#define all(arr) arr.begin(), arr.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1e16
#define ll long long

void solve(){
    int n;
    cin >> n;
    multiset<int> ms;
    ll cnt = 0;
    while(n--){
        ll x;cin>>x;
        auto less = ms.lower_bound(x);
        if(ms.find(x) != )
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t t = 1;
    cin >> t;
    for(int32_t test=1;test<=t;test++){
        solve();
    }
    return 0;
}