#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//#define int long long
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;
#define all(arr) arr.begin(), arr.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1e16
#define ll long long
ll mystoi(string s){
    if(s.empty()) return 0LL;
    ll i = s.length() - 1;
    ll fac = 1;
    ll ans = 0;
    while(i >= 0){
        ll val = (s[i] - 48)*fac;
        ans += val;
        fac *= 10;
        i--;
    }
    return ans;
}
auto solve(){
    ll n,l,r,ans=0;
    cin >> n >> l >> r;
    ll a[n];
    map<ll,ll> lb,ub;
    f(i,0,n) {
        cin >> a[i];
        lb[a[i]]=ub[a[i]]=-1;
    }

    sort(a,a+n); // sorted
    f(i,0,n){
        if(lb[a[i]] == -1) lb[a[i]] = i;
        ub[a[i]] = i;
    }
    
    string sl = to_string(l);
    ll len_sl = sl.length();

    string sr = to_string(r);
    ll len_sr = sr.length();

    f(i,0,n){
        string si = to_string(a[i]);
        ll len_si = si.length();
// cout << i << ' ' << "test" << '\n';

        // if(len_si >= len_sr) continue;
// cout << i << ' ' << "test" << '\n';

        string str = sl.substr(len_si,max(len_sl-len_si,0LL));
        

        f(j,0,len_si) {
            // return 0LL;
            if(si[j] > sl[j]){
                str = string(max(len_sl-len_si,0LL),'0');
                break;
            }
            if(si[j] < sl[j]){
                str = string(max(len_sl-len_si+1,0LL),'0');
                break;
            }
        }
        
        if(str.length()==0) continue;
        if(str[0] == '0') str[0] = '1';
        ll L = mystoi(str);
        
        str = sr.substr(len_si,max(len_sr-len_si,0LL));
        f(j,0,len_si){
            
            if(si[j] < sr[j]){
                str = string(max(len_sr-len_si,0LL),'9');
                break;
            }
            if(si[j] > sr[j]){
                str = string(max(len_sr-len_si-1,0LL),'9');
                break;
            }
            
        }
        if(str.empty()) continue;
// cout << i << ' ' << "test" << '\n';
       
        if(count(all(str),'0') == (int)str.length())
            str = string((int)str.length()-1,'9');
        
        if(str.empty()) continue; 
        ll R = mystoi(str);
// cout << i << ' ' << L << ' ' << R << ' ' << '\n';
        if(L > R) continue;
        auto it1 = lb.lower_bound(L);
        auto it2 = ub.upper_bound(R);it2--;
        ll i1 = (*it1).second;
        ll i2 = (*it2).second;
        
        ll temp = max(0LL,i2-i1+1LL);
        ans += temp;
    // cout << i+1 << ' ' << L << ' ' << R << ' ' << temp << '\n';
    return 0LL;
        // cout << i << ' ' <<  temp << '\n';
    }
    return  ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t t = 1;
    cin >> t;
    for(int32_t test=1;test<=t;test++){
        cout << solve() << '\n';
    }
    return 0;
}