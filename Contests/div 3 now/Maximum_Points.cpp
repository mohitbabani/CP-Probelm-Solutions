#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//#define int long long
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;
#define all(arr) arr.begin(), arr.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007LL
#define inf 1e16

void solve(){
    int a,b,c,x,y,z;
    int n = 20;
    cin >> a >> b >> c >> x >> y >> z;
    int points = -1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                int time = i*a + j*b + k*c;
                if(time > 240) continue;
                int pnts = i*x + j*y + k*z;
                points = max(points,pnts);
            }
        }
    }
    cout << points << '\n';
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