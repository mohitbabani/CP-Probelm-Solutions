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
ll prime[10] = {0,5,11,101,1019,10007,100129,1000003,10000019,100030001};

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
int countDigit(long long n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}
void solve(){  
    ll a,b,c;
    cin>>a>>b>>c;
    ll g = prime[c];
    ll x = g;
    ll y = g;
    while(1){
        if(countDigit(x) == a){
            break;
        }
        x *= 2;
    }
    while(1){
        if(countDigit(y) == b){
            break;
        }   
        y *= 3;
    }
    cout << x << " " << y;
}