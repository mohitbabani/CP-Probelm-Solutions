/*  Jai Shree Ram 🚩🚩🚩 */
#include "bits/stdc++.h"
#define ll long long int
#define oo 1000000000000000000
#define forr(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
#define unique(v) sort(all(v)); v.resize(distance(v.begin(),unique(all(v))))
#define eb emplace_back
#define FF first
#define SS second
#define mem(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define popcount(x) __builtin_popcount(x)

using namespace std;

template<typename T>
ostream &operator<<(ostream &output,const vector<T> &v){ 
    if(v.empty()) return output;
    for(int i=0;i<v.size()-1;i++) output << v[i] <<" ";
    output << v.back();
    return output;
}
template<typename T>
istream &operator>>(istream &input,vector<T> &v){ 
    for(auto &i: v) cin >> i;
    return input;            
}

template <int MOD=1000000007>
struct Modular {
    int value;
    static const int MOD_value = MOD;
 
    Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}
 
    Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}
 
    friend Modular mexp(Modular a, long long e) {
        Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
        return res;
    }
 
    friend Modular inverse(Modular b, long long m = MOD) {
        long long u = 0, v = 1, a = b.value;
        while (a != 0) {
            long long t = m / a;
            m -= t * a; swap(a, m);
            u -= t * v; swap(u, v);
        }
        return Modular(u);
    }
 
    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};
using mint = Modular<998244353>;

template<typename T>
class Fenwick{
    private:
        vector<T> bit;
        int n;
        template<typename T1>
        T sum(T1 id){
            T ans = 0;
            while(id>0) ans+=bit[id] , id -= id & -id;
            return ans;
        }
    public:
        template<typename T1>
        Fenwick(T1 n){
            this->n = n;
            bit.assign(n+2,0);
        }
        template<typename T1,typename T2>
        void update(T1 id,T2 val){
            while(id<=n) bit[id]+= val , id += id & -id;
        }
        template<typename T1,typename T2>
        T query(T1 l,T2 r){
            return sum(r) - sum(l-1);
        }
};


bool check(vector<int> &v){
    int n = v.size();
    vector<int> cnt(100);
    int mex = 0;
    for(auto &i: v){
        cnt[i]++;
        while(cnt[mex]!=0) mex++;
        if(abs(mex - i) > 1) return 0;
    }
    return 1;
}

int brute(vector<int> &v){
    int n = v.size();
    int ans = 0;
    forr(i,1<<n){
        if(i == 0) continue;
        vector<int> temp;
        forr(j,n){
            if((1<<j) & i) temp.eb(v[j]-1);
        }
        if(check(temp)){
        //    cout << temp<<"\n";
            ans++;
        }

    }
    return ans;
}


void __sol(){
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    for(auto &i: v) i++;
    vector<mint> f_play(n+4);
    vector<mint> f_stop(n+4);
    f_play[0] = 1;
    mint ans = 0;
    for(int i=1;i<=n;i++){
        int x = v[i-1];

        mint curr = f_play[x] + f_play[x - 1];

        ans += curr;

        f_play[x] += curr;

        curr = f_stop[x];

        ans += curr;

        f_stop[x] += curr;

        if(x - 2 >= 0){
            ans += f_play[x - 2];
            f_stop[x] += f_play[x - 2];
        }
        curr = f_stop[x+2];
        ans += curr;
        f_stop[x + 2] += curr;
    }
    cout << ans<<"\n";
    return;
}


int main(){ 
    fastio;
    int tc=1; cin >> tc;
    while(tc--) __sol();
    return 0;
}