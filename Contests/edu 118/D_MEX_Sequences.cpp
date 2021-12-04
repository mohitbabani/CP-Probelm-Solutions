#include<bits/stdc++.h>
using namespace std;
long long binaryToDecimal(string num){
    long long dec_value = 0;
    long long base = 1;
    int len = num.length();
    for(int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
template<typename T>
string decimalToBinary(T n,int bits = -1){
    string s(0,' ');
    while(n != 0){
        if(n%2) s.push_back('1');
        else s.push_back('0');
        n /= 2;
    }
    reverse(s.begin(),s.end());
    if(s.size() == 0) s.push_back('0');
    if(bits == -1) return s;
    s = string(bits-s.length(),'0') + s;
    return s;
}
int main(){
    string s = "11001";
    int n = 9;
    cout << decimalToBinary(n) << '\n';
    cout << binaryToDecimal(s) << '\n';
}