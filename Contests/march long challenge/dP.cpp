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
vector<ll> null = {-1};
map<ll,vector<ll>> memo;
vector<ll> howSum(ll n,vector<ll> v){
    if(memo.find(n) != memo.end()) return memo[n];
    if(n == 0) return {};
    if(n < 0) return null;
    for(auto i : v){
        ll val = n - i;
        vector<ll> vec = howSum(val,v);
        if(vec != null){
            vec.push_back(i);
            memo[n] = vec;
            return vec;
        }
    }
    memo[n] = null;
    return null;
}
int main(){
    vector<ll> ans = howSum(7,{5,3,4,7});
    if(ans == null){
        cout << "null";
        return 0;
    }
    _out(ans);
}