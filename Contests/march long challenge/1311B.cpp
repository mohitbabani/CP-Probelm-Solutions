    #include<bits/stdc++.h>
    using namespace std;
    void solve(){
        int n,m;cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++) 
            cin>>arr[i];
        set<int> s;
        for(int i=0;i<m;i++){
            int x;cin>>x; 
            s.insert(x);
        }
        vector<int> sorted(arr);
        sort(sorted.begin(),sorted.end());
        int cnt = 0;
        while(arr != sorted && cnt <= 10000){
            for(int i=0;i<n-1;i++){
                cnt++;
                if(arr[i] > arr[i+1] && s.find(i+1) != s.end()) 
                    swap(arr[i],arr[i+1]);
            }
        }
        if(arr != sorted) cout << "NO";
        else cout << "YES";
        cout << "\n";
    }
    int main(){
        int t;cin>>t;
        while(t--) solve();
        return 0;
    }