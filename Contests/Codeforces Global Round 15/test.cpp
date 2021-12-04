#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define inf LLONG_MAX
#define all(vec) vec.begin(),vec.end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,b,a) for(ll i=b;i>=0;i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const long long mod = 1e9 + 7; // 998244353;
ll _power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll _power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;a *= a; a %= mod;} return p % mod;}
ll _gcd(ll a,ll b) { return b?_gcd(b,a%b):a;}
ll _max(ll a,ll b){ if(a>b){return a;}else{ return b;}}
ll _modI(ll a, ll m){ return _power(a, m - 2, m);}
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(vector<pair<ll,ll>> v) {for(auto i:v) cout<<i.first<<' '<<i.second<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
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
bool gt(vector<int> v1,vector<int> v2){
    int one = 0;
    // sort(all(v1));
    // sort(all(v2));
    f(i,0,5){
        if(v1[i] > v2[i]) one++;
    }
    if(one >= 3) return true;
    return false;
}
// bool lt(vector<int> v1,vector<int> v2){
//     int one=0;
//     f(i,0,5){
//         f(j,0,5){
//             if(v1[i] < v2[j] && v2[j] != -1) {
//                 one++;
//                 v2[j] = -1;
//             }
//         }
//     }
//     if(one >= 3) return true;
//     return false;
// }
void heapify(vector<vector<int>> &arr, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && gt(arr[l],arr[largest]) )
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && gt(arr[r],arr[largest]))
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(vector<vector<int>> &arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
bool cmp(vector<ll> &v1,vector<ll> &v2){

}
void solve(){
    int n;cin>>n;
    vector<vector<int>> r(n,vector<int>(6,0));
    f(i,0,n){
        f(j,0,5) cin >> r[i][j];
        r[i][5] = i;
    }
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    sort(all(r),cmp);
    heapSort(r, n);
    // sort(r[0].begin(),r[0].end()+5);
    // sort(r[1].begin(),r[1].end()+5);
    // int one=0;
    // f(i,0,5){
    //     if(r[0][i] < r[1][i]) one++;
    // }
    // if(one >= 3)
    // f(i,0,n){
    //     f(j,0,6){
    //         cout << r[i][j] << " ";
    //     }cout << '\n';
    // }
    if(gt(r[0],r[1])){
        cout << -1 << "\n";
    }else{
        cout << r[0][5] << '\n';
    }
}
int main(){
    IOS
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}