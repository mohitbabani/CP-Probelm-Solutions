#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
ll MIN = (-1)*(1e18);
ll MAX = (1e18);
inline void print(ll a,ll b,ll c,ll d){
    cout << 2 << " " << a << " " << b << " " << c << " " << d << "\n";
    cout << flush;
}
void solve(int q,int d){
    ll x = MIN, X = MAX;
    ll y = MIN, Y = MAX;
    print(x,y,X,Y);
    string s;
    cin >> s;
    if(s=="O") return;
    while(1){
        print(x,(Y+y)/2,X,Y);
        cin>>s;
        if(s=="O") return;
        if(s=="IN"){
            print((X+x)/2,(Y,y)/2,X,Y);
            cin>>s;
            if(s=="O") return;
            if(s=="IN") continue;
        }else{

        }
    }
    
}
int main(){
    int t,q,d;
    cin >> t >> q >> d;
    while(t--){
        solve(q,d);
    }
    cout << endl;
}
/*
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
2 -2000000000000000000 0 0 2000000000000000000
2 0 0 2000000000000000000 2000000000000000000
2 -2000000000000000000 -2000000000000000000 0 0
2 0 -2000000000000000000 2000000000000000000 0
*/