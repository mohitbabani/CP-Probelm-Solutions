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

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
    Node(int val, Node* l, Node* r){
        data = val;
        left = l;
        right = r;
    }
};

class Solution{
    bool ans = true;
    int d = -1;
    void height(Node* node,int depth){
        if(node == NULL) return;
        if((node->left == NULL) && (node->right == NULL)){
            if(d == -1) d = depth;
            else{
                if(d != depth) ans = false;
            }
            return;
        }
        height(node->left,depth+1);
        height(node->right,depth+1);
    }
  public:
    /*You are required to complete this method*/
    bool check(Node *root){
        height(root,0);
        return ans;
    }
};

void solve(){
    Node* t = new Node(2);
    Node* f = new Node(4);
    Node* th = new Node(3,f,NULL);
    Node* o = new Node(1,t,th);
    Solution obj ;
    cout << (obj.check(o)) << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t t = 1;
    cin >> t;
    for(int32_t test=1;test<=t;test++){
        solve();
    }
    return 0;
}