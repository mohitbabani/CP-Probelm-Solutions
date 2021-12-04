#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> swap(vector<ll> vector,ll x,ll y){
    ll temp;
    temp = vector[x];
    vector[x] = vector[y];
    vector[y] = temp;
    return vector;
}

// ll sum1(vector<ll> v1,ll m){
//     ll sum1=0;
//     for(auto itr=v1.begin();itr!=v1.begin()+m;itr++)
//     sum1 += *itr;
//     return sum1;
// }
// ll sum2(vector<ll> v1,ll m){
//     ll sum2=0;
//     for(auto itr=v1.begin()+m;itr!=v1.end();itr++)
//     sum2 += *itr;
//     return sum2;
// }

ll check(vector<ll> vector){
    ll n2=vector.size(),b=0,sum1=0,sum2=0;
    for(ll i=0;i<n2;i++)
    sum1+=vector[i];
    for(ll i=0;i<n2;i++){
        sum2+=vector[i];
        sum1-=vector[i];
        if(sum1==sum2){
        b=1;
        break;
        }
    }
    return b;
}
// ll check(vector<ll> vector,ll i,ll j){
//     ll n2=vector.size(),b=0;
//     for(ll k=0;k<n2;k++){
//         if( ( i<k && j<k && ( 2*k*(k+1) == n2*(n2+1) ) )  ||  ( i>=k && j>=k && ( 2*k*(k+1) == n2*(n2+1) ) ) )
//         {b=1;
//         break;}
//         else if(( i<k && j>=k && ( 2*k*(k+1) + vector[j] - vector[i] == n2*(n2+1) + vector[i] - vector[j] ) )  ||   ( i>=k && j<k && ( 2*k*(k+1) + vector[i] - vector[j] == n2*(n2+1) + vector[j] - vector[i] ) ) )
//         {b=1;
//         break;}

//     }
//     return b;
// }
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v;
        for(ll i=1;i<=n;i++)
        v.push_back(i);
       
        ll count=0;
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                if(i<j){
       
                vector<ll> v2=swap(v,i,j);
                
                if(check(v2)==1)
                count++;
            }
        }
    }
    cout<<count<<"\n";
    
}   
return 0;
}