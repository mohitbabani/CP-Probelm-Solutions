#include "bits/stdc++.h"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,avx2")
using namespace std;
using ll = long long int;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, pw = 0; cin >> n;
        while ((1<<pw) <= n) ++pw;
        vector<string> v;
        v.push_back(string(pw, '0'));
        v.push_back(string(pw, '0'));
        v.back()[0] = '1';
        for (int i = 1; i < pw; ++i) {
            auto w = v; reverse(begin(w), end(w));
            for (auto &s : w)
                s[i] = '1';
            v.insert(end(v), begin(w), end(w));
        }
        reverse(begin(v), end(v));
        for(auto sr: v) cout << sr << '\n';
        for (int i = 0; i < pw; ++i)
            if (v[0][i] == '1')
                cout << i+1 << ' ';
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < pw; ++j) {
                if (v[i][j] != v[i-1][j]) cout << j+1 << ' ';
            }
        }
        cout << '\n';
    }

}