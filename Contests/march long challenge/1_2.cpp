#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e17
#define all(vec) vec.begin(),vec.end()
#define ld long double
#define ull unsigned long long
#define w(t) long long t=1 ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<endl
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void _out(vector<ll> v) {for(auto i:v) cout<<i<<' '; cout<<endl;}
void _out(set<ll> s) {for(auto i:s) cout<<i<<' '; cout<<endl;}
void solve();
int main(){
    IOS
    long long t = 1;
    cin >> t;
    while(t--) {solve();cout<<"\n";}
    return 0;
}
void computeLPSArray(char* pat, int M, int* lps);
int KMPSearch(char* pat, char* txt)
{
    int ans=0;
    int M = strlen(pat);
    int N = strlen(txt);
  
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
  
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
  
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            ans++;
            j = lps[j - 1];
        }
  
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return ans;
}
  
// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
  
    lps[0] = 0; // lps[0] is always 0
  
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
  
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void reverseStr(string& str)
{
    int n = str.length();
  
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
// ANSWER IS FROM HERE //
void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x=0;
    for(auto i : s){
        if(i == '1') x+=1;
    }
    if(x%2==0){
        if(x==2){
            ll arr[2];
            ll k=0;
            f(i,0,n){
                if(s[i]=='1'){
                    arr[k]=i;
                    k++;
                }
            }
            ll diff = arr[1]-arr[0]+1;
            ll piss = n-diff;
            if(piss>=2) {cout << "YES";return;}
            cout << "NO";
            return;
        }
        if(x==4) {
            ll arr[4];
            ll k=0;
            f(i,0,n){
                if(s[i]=='1'){
                    arr[k]=i;
                    k++;
                }
            }
            ll diff1 = arr[1]-arr[0]+1;
            ll diff2 = arr[3]-arr[2]+1;
            ll piss = n-diff1-diff2;
            if(piss>=1) {cout << "YES";return;}
            cout << "NO";
            return;
        }
        cout << "YES"; return;
    }
    if(x%3!=0){
        cout << "NO";
        return;
    }
    ll y = x/3;
    string rev = s;
    reverseStr(rev);
    string rep;
    f(i,0,n){
        if(y>0){
            rep.push_back(rev[i]);
            if(rev[i]=='1') y-=1;
        }
    }
    ll sz = rep.length();
    char txt[n+1];
    char pat[sz+1];
    strcpy(txt,rev.c_str());
    strcpy(pat,rep.c_str());
    int cnt = KMPSearch(pat,txt);
    if(cnt==3) {cout << "YES";return;}
    cout << "NO";
}