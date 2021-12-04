// #include<bits/stdc++.h>
// #define N  "NO\n"
// #define Y "YES\n"
// #define ll long long
// // #define max(a,b,c) max(max(a,b),c) 
// #define ld long double
// #define w(t) long long t ; cin>>t ; while(t--)
// #define f(i,a,b) for(ll i=a;i<b;i++)
// #define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
// #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// using namespace std;
// bool seat[2000][2000] = {{0}};
// pair<ll,ll> alloted(pair<ll,ll> t,ll n,ll m){
//     ll i = t.first,j = t.second;
//     if(seat[i][j] == 0 && i >= 0 && i < n && j >= 0 && j < m){
//         seat[i][j] = 1;
//         return make_pair(i,j);
//     }
//     while(  )
// }
// int main(){
//     ll n,m,k;
//     cin>>n>>m>>k;
    
//     f(i,0,k){
//         ll a,b;
//         cin>>a>>b;
//         pair<ll,ll> ans = alloted( make_pair(a,b) , n , m );
//         cout << ans.first << " " << ans.second << "\n";
//     }
// }
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    vector<string> ans;
    int count = 0;
    string s;
    for(int i=0;i<str.size();i++){
       
       if(str[i] <= str[i+1] && i != str.size()){
           s.push_back(str[i]);
       }
       else{
           s.push_back(str[i]);
           count++;
           ans.push_back(s);
           s.clear();
       }
    }
    cout << count << " ";
    for(int i=0;i<count;i++){
        cout << ans[i] <<" ";
    }
}