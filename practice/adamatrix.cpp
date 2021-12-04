#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll graph[n][n];
        bool arr[n+1] ={0};

        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin>>graph[i][j];
                if( graph[i][j] != i*n+(j+1)){
                    arr[max(i,j)] =1;
                }
            }
        }
        ll flag = 0;
        ll count =0;
        for(ll i = n-1;i>0;i--){
            if(arr[i]==1&& flag ==0){
                count++;
                flag = 1;
            }
            if(arr[i] ==0 && flag==1){
                count++;
                flag =0;
            }
        }

        cout<<count<<"\n";


    }
    
}