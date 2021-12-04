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
string decimalToBinary(ll n) 
{ 
    //finding the binary form of the number and  
    //coneverting it to string.  
    string s = bitset<64> (n).to_string(); 
      
    //Finding the first occurance of "1" 
    //to strip off the leading zeroes. 
    const auto loc1 = s.find('1'); 
      
    if(loc1 != string::npos) 
        return s.substr(loc1); 
      
    return "0"; 
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    ll base = 1;
 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
int main(){
    w(t){
        ll c;
        cin>>c;
        string s = decimalToBinary(c);
        string a,b;
        ll n = s.length();
        f(i,0,n){
            a.push_back('0');
            b.push_back('0');
        }
        f(i,0,n){
            if(s[i] == '0'){
                a[i] = b[i] = '1';
            }
        }
        
        f(i,0,n){
            if(binaryToDecimal(b) > binaryToDecimal(a)) a[i] = '1';
            else  b[i] = '1';
        }
        
        cout << binaryToDecimal(a) * binaryToDecimal(b) << "\n";
    }
}