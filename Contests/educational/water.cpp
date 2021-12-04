#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
ld v;
const ld scale = 1e+6;
ld ans;
struct node{
    ld c,m,p;
    node* clink;
    node* mlink;
    node(ld c,ld m,ld p){
        this->c = c;
        this->m = m;
        this->p = p;
        clink = mlink = nullptr;
    }
};
node* createNode(ld c,ld m,ld p){
    node* newNode;
    newNode->c = c;
    newNode->m = m;
    newNode->p = p;
    newNode->clink = newNode->mlink = nullptr;
    return newNode;
}
void createTree(node* root){
    ld c = root->c,m = root->m,p = root->p;
    if(c == 0 && m == 0){
        return;
    }
    if(c == 0 || m == 0){
        if(c == 0){
            node* newNode = new node(0,m-min(m,v),p+min(m,v));
            root->mlink = newNode;
            root->clink = nullptr;
            createTree(newNode);
        }else{ // m == 0
            node* newNode = new node(c-min(c,v),0,p+min(c,v));
            root->clink = newNode;
            root->mlink = nullptr;
            createTree(newNode);
        }
    }else{
        ld del = min(c,v);
        node* newc = new node(c-del,m+(del/2.0),p+(del/2.0));
        del = min(m,v);
        node* newm = new node(c+(del/2.0),m-del,p+(del/2.0));
        root->clink = newc;
        root->mlink = newm;
        createTree(newc);
        createTree(newm);
    }
}
void dfs(node* curr,ld level,ld product){
    if(curr == nullptr) return;
    level = level + 1.0;
    ld current = (level*(product*(curr->p)));
    ans += (current/scale);
   // cout << curr->c << " " << curr->m << " " << curr->p << " " << level << "\n";
    dfs(curr->clink,level,product*(curr->c/scale));
    dfs(curr->mlink,level,product*(curr->m/scale)); 
}
void solve(){
    ld c,m,p;
    cin>>c>>m>>p>>v;
    c = round(c*scale);
    m = round(m*scale);
    p = round(p*scale);
    v = round(v*scale);
    node* root = new node(c,m,p);
    createTree(root);
    ans=0.0;
    dfs(root,0.0,1.0);
    cout << setprecision(12) << fixed << ans << "\n";
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