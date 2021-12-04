#include<bits/stdc++.h>
using namespace std;
vector<int> primes(int n){
    vector<int> s;
    for(int i=2;i*i<=n;i++){
        if(n % i == 0){
            s.push_back(i);
            while(n%i == 0) n /= i;
        }
    }
    if(n > 2) s.push_back(n);
    return s;
}
int main(){
    int n;
    cin >> n;
    for(auto i: primes(n)){
        cout << i << '\n';
    }
}