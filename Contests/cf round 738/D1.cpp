#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define inf LLONG_MAX
#define all(vec) vec.begin(),vec.end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,b,a) for(ll i=b;i>=0;i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const long long mod = 1e9 + 7; // 998244353;
const char nl = (char)10;
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
ll _gcd(ll a,ll b) { return b?_gcd(b,a%b):a;}
ll _max(ll a,ll b){ if(a>b){return a;}else{ return b;}}
ll _modI(ll a, ll m){ return _power(a, m - 2, m);}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<nl;}
void _out(vector<pair<ll,ll>> v) {for(auto i:v) cout<<i.first<<' '<<i.second<<nl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<nl;}
vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
bool isPrime(ll n){
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(n%2==0 || n%3==0) return 0;
    for(ll i=5;i*i<=n;i=i+6) 
        if(n%i==0 || n%(i+2)==0) 
            return 0;
    return 1;
}
ll binaryToDecimal(string n){
    string num = n;
    ll dec_value = 0; 
    ll base = 1;
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
string decimalToBinary(ll n){
    string s(0,' ');
    while(n != 0){
        if(n%2) s.push_back('1');
        else s.push_back('0');
        n /= 2;
    }
    reverse(s.begin(),s.end());
    if(s.size() == 0) s.push_back('0');
    return s;
}
void heapify(int vec[], int n){
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
void rearrange(int vec[], int &last){
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
void mySort(int vec[], int n){
    heapify(vec,n);
    int last = n;
    f(i,0,n-1){
        rearrange(vec,last);
    }
}
void solve(){
    // int n;
    // int* vec;
    // cin >> n;
    // vec = new int[n+1];
    // f(i,1,n+1){
    //     cin >> vec[i];
    // }
    // mySort(vec,n);
    // f(i,1,n+1) cout << vec[i] << ' ';
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({1,5});
    q.push({5,2});
    q.push({5,6});
    q.push({1,2});
    cout << q.top().first << ' ' << q.top().second ;
}
int main(){
    IOS
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}