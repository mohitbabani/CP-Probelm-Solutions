#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define ld long double
#define ull unsigned long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool isPrime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return 0;return 1;}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
void solve();
int main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--){
    solve();
    }
    return 0;
}
// ANSWER IS FROM HERE //
void solve(){
    ll n;
    cin>>n;
    vector<ld> vec;
    ld avg=0;
    for(ll i=0;i<n;i++){
        ld x;cin>>x;
        avg += x;
        vec.push_back(x);
    }
    if(n==1){
        cout << vec[0] << " " << 0 << "\n";
        return;
    }
    avg /= n;
    vector<ld> diff;
    for(ll i=0;i<n;i++){
        diff.push_back(abs(avg-vec[i]));
    }
    ld mx = INT_MIN;
    ll idx=-1;
    for(ll i=0;i<n;i++){
        if(diff[i] > mx){
            mx = diff[i];
            idx = i;
        }
        else if(diff[i] == mx){
            if(vec[i] < vec[idx]) idx = i; 
        }
    }
    ll ans1 = vec[idx];
    vec.erase(vec.begin()+idx);
    sort(all(vec));
    n--;
    vector<ll> presum(n);
    presum[0] = vec[0];
    for(ll i=1;i<n;i++){
        presum[i] = presum[i-1] + vec[i];
    }
    ll ans2 = INT_MAX;
    ll last = presum[n-1];
    for(ll i=0;i<n;i++){
        ll val;
        val = vec[i]*(i+1) - presum[i];
        val += last - presum[i] - vec[i]*(n-i-1);
        ans2 = min(ans2,val); 
    }
    cout << ans1 << " " << ans2 << "\n";










    // avg=0;
    // avg = accumulate(all(vec),0);
    // avg /= (n-1);
    // ld fl = floor(avg);
    // ld ce = ceil(avg);
    // ll cost1=0,cost2=0;
    // for(ll i=0;i<n-1;i++){
    //     cost1 += abs(vec[i] - fl);
    //     cost2 += abs(vec[i] - ce);
    // }
    // cout << ans1 << " ";
    // cout << min(cost1,cost2);
    // cout << "\n";
}