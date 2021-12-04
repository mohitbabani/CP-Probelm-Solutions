#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
/*
void ruko_main(){
    w(t){
        ll n,k; cin>>n>>k;
        string s; cin>>s;

        string ss = s+s;

        vector<ll> cnt(2*n);
        ll x = 0;
        f(i,0,2*n){
            if(ss[i] != '0') x++;
            else { cnt[i-x] = x; x=0; }
        }
        ll max = *max_element(cnt.begin(),cnt.end());
        ll m_i; f(i,0,2*n) if(cnt[i] == max) { m_i = i; break; }
        
        string B = ss.substr(m_i,n);  10101 -> 11010
        ll B_cnt = 0;
        f(i,0,n)    if(ss.substr(i,n) == B) B_cnt++;
        
        ll rem = k % B_cnt;
        ll ans;
        if(rem != 0) {
            ans = (k/B_cnt) * n;
            if(ss.substr(0,n) == B) rem--;
            f(i,1,n){
                if(rem > 0){
                    if(ss.substr(i,n) == B) rem--;
                    ans++;
                }
            }
        }
        else {
            ans = ( (k/B_cnt)-1 )*n;
            rem = B_cnt;
            if(ss.substr(0,n) == B) rem--;
            f(i,1,n){
                if(rem > 0){
                    if(ss.substr(i,n) == B) rem--;
                    ans++;
                }
            }
        } 
        
        
        cout<<ans<<"\n";
        
    }
    
}
*/
// int main (){
//     w(t){
//         ll n,k;cin>>n>>k;
//         string s;cin>>s;
        
//         string ss = s+s;
        
//         vector<ll> dec(n); ll max = 0;
//         f(i,0,n){
//             dec[i] = stoi(ss.substr(i,n),0,2); // string to decimal 
//             if(dec[i] > max) max = dec[i]; //  101011101
//         }
        
//         ll max_cnt = 0; f(i,0,n) if(dec[i] == max) max_cnt++;

//         ll rem = k % max_cnt;
//         ll ans;
//         if(rem != 0){
//             ans = (k / max_cnt) * n;
//             if(dec[0] == max) rem--;
//             for(ll i=1;i<n && rem>0;i++) {
//                 if(dec[i] == max) rem--;
//                 ans++;
//             }
//         }
//         else{
//             rem = max_cnt;
//             ans = ( (k / max_cnt) - 1 ) * n;
//             if(dec[0] == max) rem--;
//             for(ll i=1;i<n && rem>0;i++) {
//                 if(dec[i] == max) rem--;
//                 ans++;
//             }
//         }
//         cout<<ans<<endl;

//     }
//     return 0;
// }

int main(){
    w(t){
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        string temp0,temp1;
        temp0.resize(s.length(),'0');
        temp1.resize(s.length(),'1');
        if(s == temp0 || s == temp1) cout<<k;
        else{
            if(n % 2 != 0);
        }
    }
}