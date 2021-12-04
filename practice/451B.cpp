#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
// #define max(a,b,c) max(max(a,b),c) 
#define ld long double
#define ull unsigned long long
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
bool checkSorted(ll *a,ll n){
    f(i,0,n-1){
        if(a[i+1] < a[i]) return 0;
    }
    return 1;
}
void swap(ll *a,ll *b){
    ll temp = *a;
    *a = *b;
    *b = temp;
}
void reverseArray(ll *a,ll start,ll end){
    while(end > start){
        swap(&a[start],&a[end]);
        start++;
        end--;
    }
}
int find_index(string s,string a[],ll m){
    f(i,0,m) if(a[i] == s) return i;
    return -1;
}
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
bool solve(ll n){
    ld root_n = sqrt(n);
    if( ( root_n == floor(root_n) ) && isPrime(root_n) )
        return 1;

    return 0;
}
bool isEqual(vector<ll> a,vector<ll> b){
    f(i,0,26) if(a[i] != b[i]) return 0;
    return 1; 
}
bool isGreater(vector<ll> a,vector<ll> b){
    f(i,0,26) if(a[i] < b[i]) return 0;
    return 1;
}
bool find(ll arr[],ll n,ll x){
    f(i,0,n) if(arr[i] == x) return 1;
    return 0;
}
// int main(){
//     IOS
//     w(t){
//         ll n;
//         cin>>n;
//         vector<ll> x,y;
//         f(i,0,2*n){
//             ll a,b;
//             cin >> a >> b;
//             a = abs(a);
//             b = abs(b);
//             if(a == 0) y.push_back(b);
//             else x.push_back(a);
//         }
//         sort(x.begin(),x.end());
//         sort(y.begin(),y.end());
//         double ans = 0;
//         f(i,0,n){
//             ans += sqrt(x[i]*x[i] + y[i]*y[i]);
//         }
//         cout << fixed << setprecision(12) << ans << "\n";
//     }
//     return 0;
// }
int main(){
    cout << LONG_LONG_MIN ;
}