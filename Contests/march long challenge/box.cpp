// // #include<bits/stdc++.h>
// // using namespace std;
// // #define ll long long
// // #define inf 1e17
// // #define all(vec) vec.begin(),vec.end()
// // #define ld long double
// // #define ull unsigned long long
// // #define f(i,a,b) for(ll i=a;i<b;i++)
// // #define newline cout<<endl;
// // #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// // void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
// // void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
// // vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
// // void solve();
// // int main(){
// //     IOS
// //     long long t = 1;
// //     cin >> t;
// // while(t--){
// //     solve();
// //     cout<<'\n';
// // }
// //     return 0;
// // }
// // // ANSWER IS FROM HERE //
// // void solve(){
// //     ll p,q;
// //     cin>>p>>q;
// //     ll x = max(p,q);
// //     ll y = min(p,q);
// //     ll ans = 0;
// //     while(1){
// //         if(x == 0 || y == 0) break;
// //         ans += x/y;
// //         ll rem = x%y;
// //         x = y;
// //         y = rem;
// //     }
// //     cout << ans ;
// // }
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define inf 1e17
// #define all(vec) vec.begin(),vec.end()
// #define ld long double
// #define ull unsigned long long
// #define f(i,a,b) for(ll i=a;i<b;i++)
// #define newline cout<<endl;
// #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
// void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
// vector<ll> _in(ll n){vector<ll> vec(n);f(i,0,n)cin>>vec[i];return vec;}
// void solve();
// int main(){
//     IOS
//     long long t = 1;
// while(t--){
//     solve();
// }
//     return 0;
// }
// // ANSWER IS FROM HERE //
// bool check(string s,ll r){
//     for(ll i=0;i<=s.length()-r;i++){
//         if(count(s.begin()+i,s.begin()+i+r,s[i]) == r) return 1;
//     }
//     return 0;
// }
// void solve(){
//     string s;
//     ll r;
//     cin >> s >> r;
//     while(1){
//         if(check(s,r) == 0) break;
//         for(ll i=0;i<=s.length()-r;i++){
//             if(count(s.begin()+i,s.begin()+i+r,s[i]) == r){
//                 s.erase(i,r);
//             }
//         }
//     }
//     cout << s;
// }
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
while(t--){
    solve();
}
    return 0;
}
// ANSWER IS FROM HERE //
void solve(){
    ll n,m;
    cin>>n>>m;
    stack<ll> s1,s2;
    ll t1=0,t2=0;
    f(i,0,n){
        ll x;cin>>x;
        t1 += x;
        s1.push(t1);
    }
    f(i,0,m){
        ll x;cin>>x;
        t2 += x;
        s2.push(t2);
    }
 
    // if(t1 == t2){
    //     ll f = s1.top();s1.pop();
    //     f += s1.top();
    //     ll l = s2.top();s2.pop();
    //     l += s2.top();
    //     s1.push(t1);s2.push(t2);
    //     if(f >= l) s1.pop();
    //     else s2.pop();
    // }
    ll ans = -1;
    while(!s1.empty() && !s2.empty()){
        if(s1.top() == s2.top()){
            ans = s1.top();
        }
        if(s1.top() > s2.top()){
            s1.pop();
        }
        else{
            s2.pop();
        }
    }
    if(ans == -1){
        cout << "Not possible";
        return;
    }
    cout << ans ;
}