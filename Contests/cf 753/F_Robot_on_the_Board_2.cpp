#include"bits/stdc++.h"
using namespace std;
void print(vector<vector<int>> vis){
    for(auto v: vis){
        for(int i: v) cout << i << ' ';
        cout << '\n';
    }
    cout << '\n';
}
void solve(){
    int n,m;
    cin >> n >> m;
    string g[n];
    for(int i=0;i<n;i++) cin >> g[i];
    
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            int i = y, j = x;
            if(vis[i][j] != 0) continue;
            int cnt = 0;
            // print(vis);
            while(i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0){
                // cout << i << ' ' << j << '\n';
                vis[i][j] = -1;
                cnt++;
                if(g[i][j] == 'U') i--;
                else if(g[i][j] == 'D') i++;
                else if(g[i][j] == 'L') j--;
                else if(g[i][j] == 'R') j++;
            }
            // if(x==0&&y==0) cout << i<<' '<<j<<'\n';
            // print(vis);
            if(i >= 0 && i < n && j >= 0 && j < m){
                if(vis[i][j] == -1){
                    int p1 = i, p2 = j;
                    int temp = 0;
                    while(p1 != i || p2 != j || temp == 0){
                        temp++;
                        if(g[i][j] == 'U') i--;
                        else if(g[i][j] == 'D') i++;
                        else if(g[i][j] == 'L') j--;
                        else if(g[i][j] == 'R') j++;
                    }
                    // cout << temp << '\n';
                    bool ok = 1;
                    while(p1 != i || p2 != j || ok){
                        ok = 0;
                        vis[i][j] = temp;
                        if(g[i][j] == 'U') i--;
                        else if(g[i][j] == 'D') i++;
                        else if(g[i][j] == 'L') j--;
                        else if(g[i][j] == 'R') j++;
                    }
                }
                int p1 = i, p2 = j;
                i = y, j = x;
                int temp = vis[p1][p2];
                while(p1 != i || p2 != j){
                    temp++;
                    if(g[i][j] == 'U') i--;
                    else if(g[i][j] == 'D') i++;
                    else if(g[i][j] == 'L') j--;
                    else if(g[i][j] == 'R') j++;
                }
                i = y, j = x;
                while(p1 != i || p2 != j){
                    vis[i][j] = temp;
                    temp--;
                    if(g[i][j] == 'U') i--;
                    else if(g[i][j] == 'D') i++;
                    else if(g[i][j] == 'L') j--;
                    else if(g[i][j] == 'R') j++;
                }
            }else{
                i = y, j = x;
                while(i >= 0 && i < n && j >= 0 && j < m){
                    vis[i][j] = cnt;
                    cnt--;
                    if(g[i][j] == 'U') i--;
                    else if(g[i][j] == 'D') i++;
                    else if(g[i][j] == 'L') j--;
                    else if(g[i][j] == 'R') j++;
                }
            }
        }
    }
    // print(vis);
    int r=-1,c=-1,d=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] > d){
                d = vis[i][j];
                r = i+1, c = j+1;
            }
        }
    }
    cout << r << ' ' << c << ' ' << d << '\n';
    // cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}