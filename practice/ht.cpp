#include<bits/stdc++.h>
using namespace std;
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
const long long int mod = 1000000007;
bool negposcollide(vector<pair<ll,ll>> arr,vector<pair<ll,ll>> &pos,vector<pair<ll,ll>> &neg){
    ll idx=arr.size();
    f(i,0,arr.size()){
        ll val = arr[i].second;
        if(val > 0){ 
            idx=i;
            break;
        }   
        neg.push_back(arr[i]);
    }
    f(i,idx,arr.size()){
        ll val = arr[i].second;
        if(val < 0){
            return true;
        }
        pos.push_back(arr[i]);
    }
    return false;
}
bool poscollide(vector<pair<ll,ll>> pos,ll right){
    vector<ld> time(pos.size());
    f(i,0,pos.size()){
        ld dis = right - pos[i].first;
        ld speed = pos[i].second;
        ld t = dis/speed;
        time[i] = t;
    }
    f(i,0,time.size()-1){
        if(time[i] < time[i+1]) return true;
    } 
    return false;
}
bool negcollide(vector<pair<ll,ll>> neg,ll left){
    vector<ld> time(neg.size());
    f(i,0,neg.size()){
        ld dis = (left - neg[i].first);
        ld speed = neg[i].second;
        ld t = dis/speed;
        time[i] = t;
    }
    f(i,0,time.size()-1){
        if(time[i] > time[i+1]) return true;
    }
    return false;
}
bool collide(vector<pair<ll,ll>> arr,pair<ll,ll> range){
    if(arr.size() <= 1) return false;
    vector<pair<ll,ll>> pos,neg;
    bool chk_np = negposcollide(arr,pos,neg);
    if(chk_np) return true;
    ll left = range.first;
    ll right = range.second;
    bool chk_pos=0,chk_neg=0;
    if(neg.size() > 1) chk_neg = negcollide(neg,left);
    if(pos.size() > 1) chk_pos = poscollide(pos,right);
    if(chk_neg || chk_pos) return true;
    return false;
}
void solve(){
    ll m,n;cin>>m>>n;
    vector<ll> chkpnts = _in(m);
    vector<pair<ll,ll>> cars(n,{0,0});
    f(i,0,n){
        cin >> cars[i].first;
    }
    f(i,0,n){
        cin >> cars[i].second;
    }
    sort(all(cars));
    vector<vector<pair<ll,ll>>> car;
    ll cp=0;
    vector<pair<ll,ll>> temp;
    vector<pair<ll,ll>> range;
    f(i,0,n){
        ll val = cars[i].first;
        if(val >= chkpnts[cp] && val <= chkpnts[cp+1]){
            temp.push_back(cars[i]);
        }else{
            if(!temp.empty()) {
                car.push_back(temp);
                temp.clear();
                range.push_back({chkpnts[cp],chkpnts[cp+1]});
            }
            while(1){
                if(val >= chkpnts[cp] && val <= chkpnts[cp+1]) break;
                cp++;
            }
            temp.push_back(cars[i]);
        }
    }
    if(!temp.empty()) {
        car.push_back(temp);
        temp.clear();
        range.push_back({chkpnts[cp],chkpnts[cp+1]});
    }
    for(int i=0;i<car.size();i++){
        bool check = collide(car[i],range[i]);
        if(check){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    
}
int main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}