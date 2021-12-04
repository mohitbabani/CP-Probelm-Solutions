// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define inf 1e17
// #define all(vec) vec.begin(),vec.end()
// #define ld long double
// #define ull unsigned long long
// // #define w(t) long long t=1 ; cin>>t ; while(t--)
// #define f(i,a,b) for(ll i=a;i<b;i++)
// #define newline cout<<endl
// #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
// void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
// void solve();
// int main(){
//     IOS
//     long long t = 1;
//     cin >> t;
//     while(t--) {solve();cout << "\n";}
//     return 0;
// }
// // ANSWER IS FROM HERE //
// ll digit_sum(ll a){
//     string s = to_string(a);
//     ll sum = 0;
//     for(auto i : s){
//         sum += int(i) - 48;
//     }
//     return sum;
// }
// ll gcdSum(ll x){
//     return __gcd(x,digit_sum(x));
// }
// vector<ll> d_b(ll n){
//     vector<ll> vec;
//     while(n > 0){
//         vec.push_back(n%2);
//         n /= 2;
//     }
//     return vec;
// }
// bool empty(vector<ll> vec){
//     for(auto i : vec){
//         if(i != 0) return 0;
//     }
//     return 1;
// }
// // void solve(){
// //     ll n,W;
// //     cin >> n >> W;
// //     vector<ll> w(n);
// //     f(i,0,n) cin >> w[i];
// //     vector<ll> b_W = d_b(W);
// //     ll sz = b_W.size();
// //     vector<ll> cnt(sz,0);
// //     f(i,0,n){
// //         ll idx = log2(w[i]);
// //         cnt[idx]++;
// //     }
// //     ll ans = 0;
// //     while(!empty(cnt)){
// //         ll m = 1;
// //         ll t = 0;
// //         for(ll i = sz-1; i>= 0; i--){
// //             if(b_W[i]) t += m;
// //             if(t >= cnt[i]){
// //                 t -= cnt[i];
// //                 cnt[i] = 0;
// //             }else{
// //                 t = 0;
// //                 cnt[i] -= t;
// //             }
// //             m *= 2;
// //         } 
// //         ans++;
// //     }
// //     cout << ans;
// // }
// void solve(){
//     ll n,w;
//     cin >> n >> w;
//     vector<ll> counts(20,0);
//     f(i,0,n){
//         ll x;cin >> x;
//         x = log2(x);
//         counts[x]++;
//     }
//     ll h = 1;
//     ll s_l = w;
//     f(i,0,n){
//         ll lar = -1;
//         for(ll j=19;j>=0;j--){
//             if(counts[j] && pow(2,j) <= s_l){
//                 lar = j;
//                 break;
//             }
//         }
//         if(lar == -1){
//             s_l = w;
//             h += 1;
//             for(ll j=19;j>=0;j--){
//                 if(counts[j] && pow(2,j) <= s_l){
//                     lar = j;
//                     break;
//                 }
//             }
//         }

//         counts[lar] -= 1;
//         s_l -= pow(2,lar);
//     }
//     cout << h ;
// }