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
int main(){
    IOS
    w(t){
        ll n,k;cin>>n>>k;
        vector<char> v(n,0);
        ll cntW=0,cntL=0;
        ll score=0;

        f(i,0,n){
        cin>>v[i];
        if(v[i]=='L')
        cntL++;
        if(v[i]=='W')
        cntW++;
        }
        {
        if(v[0] == 'W')
        score++;
        }
        
        f(i,1,n){
        if(v[i-1]=='L' && v[i]=='W')
        score++;
        if(v[i-1]=='W' && v[i]=='W')
        score+=2;
        }


        if(cntW == n || k >= cntL)
        score = 2*n -1;
        else{
            f(i,1,n-1){
                if(k > 0 && v[i]=='L' && v[i-1]=='W' && v[i+1]=='W'){
                    v[i] = 'W';
                    score += 3;
                    k--;
                }
            }
            f(i,1,n-1){
                if(k > 0 && v[i]=='L' && v[i-1]=='W' && v[i+1]=='L'){
                    v[i] = 'W';
                    score += 2;
                    k--;
                }
                if(k > 0 && v[i]=='L' && v[i-1]=='W' && v[i+1]=='W'){
                    v[i] = 'W';
                    score += 3;
                    k--;
                }
            }
            f(i,1,n-1){
                if(k > 0 && v[i]=='L' && v[i-1]=='L' && v[i+1]=='W'){
                    v[i] = 'W';
                    score += 2;
                    k--;
                }
                if(k > 0 && v[i]=='L' && v[i-1]=='W' && v[i+1]=='L'){
                    v[i] = 'W';
                    score += 2;
                    k--;
                }
                if(k > 0 && v[i]=='L' && v[i-1]=='W' && v[i+1]=='W'){
                    v[i] = 'W';
                    score += 3;
                    k--;
                }
            }
            f(i,1,n-1){
                if(k > 0 && v[i]=='L' && v[i-1]=='L' && v[i+1]=='L'){
                    v[i] = 'W';
                    score++;
                    k--;
                }
                if(k > 0 && v[i]=='L' && v[i-1]=='L' && v[i+1]=='W'){
                    v[i] = 'W';
                    score += 2;
                    k--;
                }
                if(k > 0 && v[i]=='L' && v[i-1]=='W' && v[i+1]=='L'){
                    v[i] = 'W';
                    score += 2;
                    k--;
                }
                if(k > 0 && v[i]=='L' && v[i-1]=='W' && v[i+1]=='W'){
                    v[i] = 'W';
                    score += 3;
                    k--;
                }
            }
            {
                if( k>0 && v[0] == 'L' && v[1] == 'W' ){
                    v[0] = 'W';
                    score += 2;
                }
                if( k>0 && v[n-2] == 'W' && v[n-1] == 'L' ){
                    v[n-1] = 'W';
                    score += 2; 
                }
                if( ( v[0] == 'L' && v[1] == 'L' ) || ( v[n-2] == 'L' && v[n-1] == 'L' ) )
                score ++;
            }
        }
        cout<<score<<"\n";
    }
    return 0;
}