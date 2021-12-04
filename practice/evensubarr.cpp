#include<bits/stdc++.h>
#define N  "NO\n"
#define Y "YES\n"
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
void PrintStack(stack<char> s)
{
    // If stack is empty then return
    if (s.empty()) 
        return;
    
 
    char x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x ;
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}
int main(){
    w(t){
        string s;
        cin>>s;
        stack<char> stk;
        f(i,0,s.length()){
            if( stk.empty() )   stk.push(s[i]);
            else {
                if(s[i]==stk.top()) stk.pop();
                else stk.push(s[i]);
            }
        }
        if(stk.empty()) cout<<"KHALI";
        else PrintStack(stk);
        // else {
        //     vector<char> temp;
        //     while(! stk.empty()){
        //         temp.push_back(stk.top());
        //         stk.pop();
        //     }
        //     ll n = temp.size();
        //     for(ll i=n-1;i>=0;i--) cout<<temp[i];
        // }
        cout<<"\n";
    }
    return 0;
}