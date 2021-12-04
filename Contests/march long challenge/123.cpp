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
}
    return 0;
}
// ANSWER IS FROM HERE //
bool isPrime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return 0;return 1;}

void solve(){
    ll n,y;
    cin>>n>>y;
    if(y > (n*(n+1))/2) {cout << -1<<"\n";return;}
    vector<ll> vec;
    for(ll i=1;i<=n;i++){
        vec.push_back(i);
    }
    vector<ll> ans;
    for(ll i=n-1;i>=0;i--){
        ll val = y - i;
        ll sz = vec.size();
        if(val <= vec[sz-1] && val >= vec[0]){
            auto itr = lower_bound(all(vec),val);
            ans.push_back(*itr);
            y -= (*itr);
            vec.erase(itr);
        }
        else if(val > vec[sz-1]){
            auto itr = vec[sz-1];
            ans.push_back(itr);
            y -= vec[sz-1];
            vec.erase(vec.end()-1);
        }
        else{
            break;
        }
    }
    for(ll i=vec.size()-1;i>=0;i--){
        ans.push_back(vec[i]);
    }
    for(auto i : ans){
        cout << i << " ";
    }
    cout << "\n";
}