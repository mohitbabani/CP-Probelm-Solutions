#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define pb push_back
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
ll n,m,k;
bool check(vector<vector<char>> mat,char ch){
    vector<vector<ll>> play(n,vector<ll>(m,0));
    f(i,0,n){
        if(mat[i][0] == ch) play[i][0]=1;
    }
    f(i,0,n){
        f(j,1,m){
            if(mat[i][j]==ch){
                play[i][j] = play[i][j-1]+1;
            } else{
                play[i][j]=0;
            }
        }
    }
    ll cnt=0;
    f(col,0,m){
        f(row,0,n){
            if(play[row][col] == k){
                cnt++;
            }else{
                cnt=0;
            }
            if(cnt==k) return true;
        }
    }
    return false;
}
bool COMPARE(vector<vector<char>> one,vector<vector<char>> two){
    f(i,0,k){
        f(j,0,k){
            if(one[i][j] != two[i][j]) return false;
        }
    }
    return true;
}
void solve(){
    cin>>n>>m>>k;
    vector<vector<char>> mat(n,vector<char>(m,'.'));
    ll ans=-1; // 0 - alice // 1 - bob
    ll idx;
    f(i,0,n*m){
        ll x,y;cin>>x>>y;
        x--;y--;
        if(i%2==0){
            mat[x][y]='A';
        }else{
            mat[x][y]='B';
        }
        // if(i == 9){
        //     cout << mat[x][y] << "\n";
        //     compare(mat,mat[x][y]);
        // }
        if(ans == -1){
            if(check(mat,mat[x][y])){
                ans=i%2;
                idx=i;
            }
        }
    }
    // cout << idx << "\n";
    if(ans==-1) cout << "Draw";
    else if(ans == 0) cout << "Alice";
    else cout << "Bob";
    cout << "\n";
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