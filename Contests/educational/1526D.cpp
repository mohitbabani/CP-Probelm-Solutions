#include<bits/stdc++.h>
using namespace std;
int two_power(int num){
    int power=0;
    while(num != 1){
        if(num % 2 != 0) return -1;
        power++;
        num /= 2;
    }
    return power;
}
void solve(){
    int n;cin>>n;
    if(n % 2){
        cout << "Bob\n";
        return;
    }
    int pow = two_power(n);
    if(pow == -1){
        cout << "Alice\n";
        return;
    }
    if(pow%2) cout << "Bob\n";
    else cout << "Alice\n";
}
int main(){
    int tc;cin>>tc;
    while(tc--) solve();
    return 0;
}