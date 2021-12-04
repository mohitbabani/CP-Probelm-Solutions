#include<bits/stdc++.h>
using namespace std;
int main(){
    cout << "Enter the binary string :";
    string s;
    cin >> s;
    int n = s.length();
    string oo_1 = "  _   _";
    string oo_2 = " | | | ";
    string oo_3 = "_| |_| ";
    string zz_1 = "_   _  ";
    string zz_2 = " | | | ";
    string zz_3 = " |_| |_";
    string oz_1 = "  _ _  ";
    string oz_2 = " |   | ";
    string oz_3 = "_|   |_";
    string zo_1 = "_     _";
    string zo_2 = " |   | ";
    string zo_3 = " |_ _| ";
    for(int i=0;i<n-1;i+=2){
        if(s[i] == '1' && s[i+1] == '1') cout << oo_1 ;
        else if(s[i] == '1' && s[i+1] == '0') cout << oz_1;
        else if(s[i] == '0' && s[i+1] == '1') cout << zo_1;
        else cout << zz_1;
    }
    cout << "\n";
    for(int i=0;i<n-1;i+=2){
        if(s[i] == '1' && s[i+1] == '1') cout << oo_2 ;
        else if(s[i] == '1' && s[i+1] == '0') cout << oz_2;
        else if(s[i] == '0' && s[i+1] == '1') cout << zo_2;
        else cout << zz_2;
    }
    cout << "\n";
    for(int i=0;i<n-1;i+=2){
        if(s[i] == '1' && s[i+1] == '1') cout << oo_3 ;
        else if(s[i] == '1' && s[i+1] == '0') cout << oz_3;
        else if(s[i] == '0' && s[i+1] == '1') cout << zo_3;
        else cout << zz_3;
    }
}