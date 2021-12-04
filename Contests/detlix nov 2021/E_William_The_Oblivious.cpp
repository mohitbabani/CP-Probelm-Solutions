#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define ld long double
#define pb push_back
#define set_bits __builtin_popcountll
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
template<typename T>
void _out(vector<T> v) {for(T i:v) cout<<i<<' '; cout<<nl;}
template<typename T>
void _out(vector<pair<T,T>> v) {for(pair<T,T> i:v) cout<<i.first<<' '<<i.second<<nl;}
template<typename T>
void _out(set<T> s) {for(T i:s) cout<<i<<' '; cout<<nl;}
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
class DSU{
    public:
        vector<ll> par,sz;
        DSU(ll n){
            par.resize(n+2);
            sz.resize(n+2);
            f(i,1,n+1) par[i] = i, sz[i] = 1;
        }
        void merge(ll a,ll b){
            ll Pa = find(a);
            ll Pb = find(b);
            if(sz[Pa] > sz[Pb]) swap(Pa,Pb);
            par[Pa] = Pb;
            sz[Pb]+=sz[Pa];
        }
        ll find(ll node){
            while(par[node] != node){
                node = par[node];
            }
            return node;
        }
        bool is_same(ll a,ll b){
            return find(a) == find(b);
        }
};
class ST{
public:
    int n;
    vector<int> arr,st;
    void init(int n,vector<int> arr){
        this->n = n;
        this->arr = arr;
        st.resize(4*n);
        constructST(0,0,n-1);
    }
    void constructST(int idx,int L,int R){
        if(L == R){
            st[idx] = arr[L];
            return;
        }
        int mid = (L+R) >> 1;
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        constructST(left,L,mid);
        constructST(right,mid+1,R);
        st[idx] = st[left] + st[right];
    }
    void myUpdate(int idx,int L,int R,int diff,int pos){
        if(pos < L || pos > R) return;
        st[idx] += diff;
        if(L == R) return;
        int mid = (L+R) >> 1;
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        myUpdate(left,L,mid,diff,pos);
        myUpdate(right,mid+1,R,diff,pos);
    }
    void update(int pos,int val){
        int old = arr[pos];
        arr[pos] = val;
        int diff = val - old;
        myUpdate(0,0,n-1,diff,pos);
    }
    int myGetSum(int idx,int L,int R,int start,int end){
        if(start > R || end < L) return 0;
        if(start <= L && end >= R) return st[idx];
        int mid = (L+R) >> 1;
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        int res = myGetSum(left,L,mid,start,end)+myGetSum(right,mid+1,R,start,end);
        return res;
    }
    int getSum(int start,int end){
        return myGetSum(0,0,n-1,start,end);
    }
};
void solve(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> idx[3];
    vector<vector<int>> cnt(3,vector<int>(n,0));
    
    for(int i=0;i<n;i++){
        idx[s[i]-97].insert(i);
        cnt[s[i]-97][i] = 1;
    }
    ST obj[3];
    for(int i=0;i<3;i++) obj[i].init(n,cnt[i]);
    
    for(int k=1;k<=q;k++){
        int i; char nch;
        cin >> i >> nch; 
        i--;
        char och = s[i];
        s[i] = nch;
        nch -= 97; 
        och -= 97;
        idx[och].erase(i);
        idx[nch].insert(i);
        obj[och].update(i,0);
        obj[nch].update(i,1);
        auto firstA = idx[0].begin();
        auto lastC = idx[2].rbegin();
        if(idx[0].empty() || idx[2].empty() || *firstA > *lastC){
            cout << 0 << '\n';
            continue;
        }
        int mn = 1e9;
        for(int i=0;i<3;i++) {
            int val = obj[i].getSum(*firstA,*lastC);
            mn = min(mn,val);
        }

        if(k == 96) cout << "96 " << s << ' ' << mn << '\n';
    }
}
int32_t main(){
    IOS
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}