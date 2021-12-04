#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define w(t) long long t=1 ; cin>>t ; while(t--)
#define n_sort(a) sort(a.begin(),a.end())
#define f(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<endl
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
void solve();
int main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
// ANSWER IS FROM HERE //
ll nc2(ll a) { return (a*(a-1))/2;}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    ll a_sum = 0;
    f(i,0,n) cin >> a[i] , a_sum += a[i];
    vector<ll> on,tw;
    f(i,0,n){
        ll x;cin>>x;
        if(x==1) on.push_back(a[i]);
        else tw.push_back(a[i]);
    }
    if(m > a_sum) {cout << -1 << "\n"; return ;}
    sort(on.rbegin(),on.rend());
    sort(tw.rbegin(),tw.rend());
    vector<ll> p1(1+on.size(),0),p2(1+tw.size(),0);
    f(i,0,on.size()){
        p1[i+1] = p1[i] + on[i];
    }
    f(i,0,tw.size()){
        p2[i+1] = p2[i] + tw[i];
    }
    // _out(p1);
    // _out(p2);
    ll ans = INT_MAX;
    f(i,0,p1.size()){
        ll left = m - p1[i];
        if(left<=0) ans = min(ans,i);
        ll j = lower_bound(p2.begin(),p2.end(),left) - p2.begin();
        if(j == p2.size()) --j;
        left -= p2[j];
        if(left<=0) ans = min(ans,i+2*j);
    }
    cout << ans << "\n";
} 