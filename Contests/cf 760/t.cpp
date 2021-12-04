#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    int tc;
    cin>>tc;
    while(tc--)
    {
       
        ll n;
        cin>>n;
        
        // ll a[n];
        // for (ll i=0;i<n;i++)
        // {
        //     cin>>a[i];
        // }

        // for(ll i=0;i<n;i++){
        //   f[a[i]]++;
        // }          
        map<ll,ll> mp;
        ll arr[1];
        for(int i=0;i<n;i++){
            cin >> arr[0];
            mp[arr[0]]++;
        }
        ll ans=0;
        for(auto it : mp){
           
           ans+=((n-it.second)*it.second);
        }
        cout<<ans<<endl;
    }

    return 0;
}