#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;
#define all(arr) arr.begin(), arr.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1e16

void yes(){
    cout << "YES\n";
}
void no(){
    cout << "NO\n";
}
bool brute_force(vector<int> v, int k){
    int n = v.size();
    for(int i = 0; i < (1 << n); i++){
        if(__builtin_popcount(i) != k) continue;
        int GCD = 0;
        for(int j = 0; j < n; j++){
            if((i & (1 << j)) != 0){
                GCD = __gcd(GCD,v[j]);
            }
        }
        if(GCD == 1) {return 1;}
    }
    return 0;
    auto t = v.size();
}
void solve(){
    mt19937 rng(58);
    int n;
    cin >> n;
    int k = (n + 1) / 2;
    vi even;
    int GCD = 0;
    f(i,0,n){
        int x;cin>>x;
        if(x%2) continue;
        x /= 2;
        even.pb(x);
        GCD = __gcd(GCD,x);
    }

    if(even.size() < k){
        no();
        return;
    }

    if(k <= 10){
        brute_force(even,k) ? yes() : no();
        return;
    }

    if(GCD == 1) yes();
    else no();
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