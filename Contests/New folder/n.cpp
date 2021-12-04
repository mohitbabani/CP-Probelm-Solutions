#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//#define int long long
using pii = pair<bool,bool>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;
#define all(arr) arr.begin(), arr.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1e16

int answer(string s){
    int n = s.length();
    if(n <= 1) return 0;
    vector<int> arr;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1]){
            cnt++;
        }else{
            arr.push_back(cnt);
            cnt = 1;
        }
    }
    arr.push_back(cnt);
    n = arr.size();
    int res = 0;
    for(int i=0;i<n-1;i++){
        res += min(arr[i],arr[i+1]);
    }
    return res;
}

void solve(){
    string s;
    cin >> s;
    cout << answer(s) << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t t = 1;
    cin >> t;
    for(int32_t test=1;test<=t;test++){
        solve();
    }
    return 0;
}