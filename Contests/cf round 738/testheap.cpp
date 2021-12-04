#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define ull unsigned long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool isPrime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return 0;return 1;}
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
ll _gcd(ll a,ll b) { return b?_gcd(b,a%b):a;}
ll _max(ll a,ll b){ if(a>b){return a;}else{ return b;}}
ll _modI(ll a, ll m){ return _power(a, m - 2, m);}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(vector<pair<ll,ll>> v) {for(auto i:v) cout<<i.first<<' '<<i.second<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
const long long  mod = 1000000007;
vector<int> vec;
int n,last;
void heapify(){
    for(int j=n;j>=1;j--){
        int i = j;
        while(1){
            int mx = INT_MIN, idx = -1;
            if(2*i <= n){
                if(vec[2*i] > mx){
                    mx = vec[2*i];
                    idx = 2*i;
                }
            }
            if(2*i+1 <= n){
                if(vec[2*i+1] > mx){
                    mx = vec[2*i+1];
                    idx = 2*i+1;
                }
            }
            if(idx == -1) break;
            if(vec[i] < mx){
                swap(vec[i],vec[idx]);
                i = idx;
            }else{
                break;
            }    
        }
    }
}
void rearrange(){
    swap(vec[1],vec[last]);
    last--;
    int i = 1;
    while(1){
        int mx = INT_MIN, idx = -1;
        if(2*i <= last){
            if(vec[2*i] > mx){
                mx = vec[2*i];
                idx = 2*i;
            }
        }
        if(2*i+1 <= last){
            if(vec[2*i+1] > mx){
                mx = vec[2*i+1];
                idx = 2*i+1;
            }
        }
        if(idx == -1) break;
        if(vec[i] < mx){
            swap(vec[i],vec[idx]);
            i = idx;
        }else{
            break;
        }
    }
}
void mySort(){
    heapify();
    f(i,0,n-1){
        rearrange();
    }
}
void solve(){
    cin>>n;
    last = n;
    n *= 2;
    vector<ll> vec = _in(n);
    if(n==2){
        _out(vec);
        return;
    }
    mySort();
    for(ll i=0;i<n/2;i++){
        cout << vec[i] << " " << vec[n-i-1] << " ";
    }
    cout << "\n";
}
int32_t main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}