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

void solve(){
    string s;
    cin >> s;
    if(s == "()") {cout << 0 ; return;}
    int n = s.length();
    vector<int> level(n,-1);
    f(i,0,n){
        if(level[i] == -1){
            
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t t = 1;
    // cin >> t;
    for(int32_t test=1;test<=t;test++){
        solve();
    }
    return 0;
}