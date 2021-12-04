#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define f(n) for(ll i=0;i<n;i++)
#define inf 1e17
#define _fast_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
ll _gcd(ll a,ll b) { return b?_gcd(b,a%b):a;}
ll _max(ll a,ll b){ if(a>b){return a;}else{ return b;}}
ll _modI(ll a, ll m){ return _power(a, m - 2, m);} 
void _out(vector<ll> arr){ for(auto i:arr){cout<<i<<' ';}cout<<"\n";}
void _out(vector<pair<ll,ll>> par ){for(auto i:par){cout<<i.first<<" "<<i.second<<"\n";}}
void _out(set<ll> arr){ for(auto i:arr){cout<<i<<' ';}cout<<"\n";}

// ll mod = 998244353; 
ll mod = 1000000007;
const ll N = 1e6 + 7;

void solve(){
    ll n, m;
    cin >> n >> m;

    vector<pair<ll,ll>> pos(n);
    vector<ll> ans(n, -1);

    f(n){
        cin >> pos[i].first;
        pos[i].second = i;
    }

    sort(pos.begin(), pos.end());

    stack<int> od, ev;

    vector<char> dir(n);

    f(n){
        cin >> dir[i];
    }

    vector<int> odl, odr, evl, evr;


    f(n){
        if(pos[i].first % 2){
            if(dir[pos[i].second] == 'R'){
                od.push(i);
            }
            else{
                if(od.size()){
                    ll ind = od.top();
                    od.pop();

                    ll time = (pos[i].first - pos[ind].first) / 2;

                    ans[pos[i].second] = time;
                    ans[pos[ind].second] = time; 
                }
                else{
                    odl.push_back(i);
                }
            }
        }
        else{
            if(dir[pos[i].second] == 'R'){
                ev.push(i);
            }
            else{
                if(ev.size()){
                    ll ind = ev.top();

                    ev.pop();

                    ll time = (pos[i].first - pos[ind].first) / 2;

                    ans[pos[i].second] = time;
                    ans[pos[ind].second] = time; 
                }
                else{
                    evl.push_back(i);
                }
            }
        }
    }


    // Case 2

    while(od.size()){
        ll ind = od.top();
        od.pop();

        odr.push_back(ind);
    }

    while(ev.size()){
        ll ind = ev.top();
        ev.pop();

        evr.push_back(ind);


    }

    sort(odr.begin(), odr.end());

    sort(evr.begin(),evr.end());

    ll i = odr.size();

    i--;

    while(i > 0 ){
        ll ind = odr[i];
        ll pre = odr[i - 1];

        ll time = m - pos[ind].first;

        time += (pos[ind].first - pos[pre].first) / 2;

        ans[pos[ind].second] = time;
        ans[pos[pre].second] = time;
        i-= 2;

    }

    i = evr.size();
    i--;
    
    while(i > 0 ){
        ll ind = evr[i];
        ll pre = evr[i - 1];

        ll time = m - pos[ind].first;

        time += (pos[ind].first - pos[pre].first) / 2;

        ans[pos[ind].second] = time;
        ans[pos[pre].second] = time;
        i-= 2; 
    }

    i = 0;
    while(evl.size() && i < evl.size() - 1){
        ll ind = evl[i];
        ll pre = evl[i + 1];

        ll time = pos[ind].first;

        time += (pos[pre].first - pos[ind].first) / 2;

        ans[pos[ind].second] = time;
        ans[pos[pre].second] = time;
        i += 2; 
    }

    i = 0;

    while(odl.size() && i < odl.size() - 1){
        ll ind = odl[i];
        ll pre = odl[i + 1];
        ll time = pos[ind].first;

        time += (pos[pre].first - pos[ind].first) / 2;

        ans[pos[ind].second] = time;
        ans[pos[pre].second] = time;
        i += 2;
    }


    // Case 3
    if(evl.size() % 2 + evr.size() % 2 > 1){
        ll i1 = evl.back();
        ll i2 = evr[0];

        ll time = 2*pos[i1].first + 2*(m -  pos[i2].first) + (pos[i2].first - pos[i1].first);
        time /=2;

        ans[pos[i1].second] =  ans[pos[i2].second] = time;
    }

    if(odl.size() % 2 + odr.size() % 2 > 1){
        ll i1 = odl.back();
        ll i2 = odr[0];

        ll time = 2*pos[i1].first + 2*(m -  pos[i2].first) + (pos[i2].first - pos[i1].first);
        time /=2;

        ans[pos[i1].second] =  ans[pos[i2].second] = time;
    }

    _out(ans);
}

   
int main(){
    _fast_ 

    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }

} 
