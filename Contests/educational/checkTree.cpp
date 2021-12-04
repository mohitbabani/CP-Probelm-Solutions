/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define long long long
#define v vector

long MOD = 1e9+7;

void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }

}

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        v<int> sorted;
        for(int i=0; i<N; i++){
            int num; cin>>num; sorted.push_back(num);
            arr.push_back(num);
        }
        sort(sorted.begin(), sorted.end());
        v<long> prefix(N);
        prefix[0] = 0;
        for(int i=1; i<N; i++){
            prefix[i] = prefix[i-1] + sorted[i];
        }
        long ans  = sorted.back();
        for(int i=N-1; i>0; i--){
            ans-=(long)sorted[i]* i - prefix[i-1];
        }
        cout<<ans<<endl;

    }
    return 0;
}

