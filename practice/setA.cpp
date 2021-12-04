#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
// #define max(a,b,c) max(max(a,b),c) 
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll hcf(ll a,ll b){
    ll ans;
    f(i,1,min(a,b)+1){
        if( a%i == 0 && b%i == 0 ) ans = i;
    }
    return ans;
}
bool checkRightTriangle(vector<ll> v){
    ll a = (v[2]-v[0])*(v[2]-v[0]) +  (v[3]-v[1])*(v[3]-v[1]);
    ll b = (v[4]-v[0])*(v[4]-v[0]) +  (v[5]-v[1])*(v[5]-v[1]);
    ll c = (v[4]-v[2])*(v[4]-v[2]) +  (v[5]-v[3])*(v[5]-v[3]);
    ll mx = max(max(a,b),c);
    if(a+b+c-mx == mx && a!=0 && b!=0 && c!=0) return 1;
    return 0;
}

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;
    while(k--){
        st.push(q.front());
        q.pop();
    }
    queue<int> ans;
    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        ans.push(q.front());
        q.pop();
    }
    return ans;
}
string int_to_binary_string(ll t){
    string s;
    if(t == 0) return "0";
    while(t){
        s.push_back( t%2 == 1 ? '1' : '0' );
        t /= 2;
    }
    ll n = s.length();
    ll temp = 20 - n;
    while(temp--){
        s.push_back('0');
    }
    n = s.length();
    f(i,0,n/2) swap(s[i],s[n-i-1]);
    return s;
}
ll nC2(ll n){
    return n*(n-1)/2;
}
int BS(int a[],int left,int right,int x){
    if(right >= left){
        int mid = left + (right - left)/2;

        if(a[mid] == x) 
            return mid;

        if(a[mid] > x)
            return BS(a,left,mid-1,x);
    
        return BS(a,mid+1,right,x);
    }
    return -1;
}
int main(){
    int arr[] = {1,2,6,4,7,8,3,4,5,7};
    ll n = sizeof(arr)/sizeof(arr[0]);
    cout << BS(arr,0,n-1,4);
}
// int main(){
//     cout << int_to_binary_string(1048575) << endl;
// }