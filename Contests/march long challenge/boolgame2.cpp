#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define ld long double
#define ull unsigned long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<endl;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
    cout<<'\n';
}
    return 0;
}
// ANSWER IS FROM HERE //
bool present(vector<bool> vec,pair<ll,ll> p){
    ll x = p.first-1;
    ll y = p.second-1;
    for(ll i=x;i<=y;i++){
        if(vec[i] == 0) return 0;
    }
    return 1;
}
ll summation(vector<ll> vec,pair<ll,ll> p){
    ll sum = 0;
    ll x = p.first-1;
    ll y = p.second - 1;
    for(ll i=x;i<=y;i++) if(vec[i] < 0) sum += vec[i];
    return sum;
}
vector<bool> makeOne(vector<bool> vec,pair<ll,ll> p){
    ll x = p.first - 1;
    ll y = p.second - 1;
    for(ll i=x;i<=y;i++){
        vec[i] = 1;
    }
    return vec;
}
ll sum_val_with(vector<ll> vec,vector<bool> vec2,pair<ll,ll> p){
    ll x = p.first;
    ll y = p.second;
    ll sum=0;
    for(ll i=x;i<=y;i++){
        vec2[i] = 1;
    }
    for(ll i=0;i<vec.size();i++){
        if(vec2[i]) sum += vec[i];
    }
    return sum;
}
ll sum_val_without(vector<ll> vec,vector<bool> vec2){
    ll sum = 0;
    f(i,0,vec.size()){
        if(vec2[i]) sum += vec[i]; 
    }
    return sum;
}
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> g = _in(n);
    map<pair<ll,ll>,ll> d;
    f(i,0,m){
        ll x,y,z;
        cin >> x >> y >> z;
        d[{x,y}] = z; 
    }
    ll ans = 0;
    vector<bool> g_flag(n);
    for(ll i=0;i<n;i++){
        if(g[i] > 0){
            g_flag[i] = 1;
            ans += g[i];
        }
    }
    map<pair<ll,ll>,ll> f_d;
    for(auto i : d){
        pair<ll,ll> p = i.first;
        f_d[p] = 0; 
    }
    for(auto tri : d){
        pair<ll,ll> p = tri.first;
        ll x = p.first;
        ll y = p.second;
        ll t = tri.second;
        vector<pair<ll,ll>> uvs;
        for(ll i=x;i<=y;i++){
            for(ll j=i;j<=y;j++){
                uvs.push_back({i,j});
            }
        }
        for(auto uv : uvs){
            if(d.find(uv) != d.end()){
                if(uv == p) f_d[p] += d[uv];
                else if(d[uv] < 0) f_d[p] += d[uv];
            }
        }
    }
    for(auto i : f_d){
        pair<ll,ll> uv = i.first;
        ll val = i.second;
        bool prt = present(g_flag,uv);
        bool grt = (val >= 0);
        if(grt && prt) ;
        else if(!prt && grt){
            ll with = sum_val_with(g,g_flag,uv) + grt;
            ll without = sum_val_without(g,g_flag);
            if(with > without){
                ans += (with-without);
                g_flag = makeOne(g_flag,uv);
            }
        }   
        else if(prt && !grt){
            ll min_g = *min_element(g.begin()+uv.first-1,g.begin()+uv.second);
            if(min_g + grt >= 0){
                ans += grt;
            } 
            else{
                if(min_g >= 0){
                    ll itr = min_element(g.begin()+uv.first-1,g.begin()+uv.second) - g.begin();
                    
                }
            }
        }
    }
}