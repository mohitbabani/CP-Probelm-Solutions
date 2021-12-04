// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+10;

// Adjacency List to store the graph
vector<int> adj[maxN];

// Stores the height of each node
int height[maxN];

// Stores the maximum distance of a
// node from its ancestors
int dist[maxN];

// Function to add edge between
// two vertices
void addEdge(int u, int v)
{
	// Insert edge from u to v
	adj[u].push_back(v);

	// Insert edge from v to u
	adj[v].push_back(u);
}

// Function to calculate height of
// each Node
void dfs1(int cur, int par)
{
	// Iterate in the adjacency
	// list of the current node
	for (auto u : adj[cur]) {

		if (u != par) {

			// Dfs for child node
			dfs1(u, cur);

			// Calculate height of nodes
			height[cur]
				= max(height[cur], height[u]);
		}
	}

	// Increase height
	height[cur] += 1;
}

// Function to calculate the maximum
// distance of a node from its ancestor
void dfs2(int cur, int par)
{
	int max1 = 0;
	int max2 = 0;

	// Iterate in the adjacency
	// list of the current node
	for (auto u : adj[cur]) {

		if (u != par) {

			// Find two children
			// with maximum heights
			if (height[u] >= max1) {
				max2 = max1;
				max1 = height[u];
			}
			else if (height[u] > max2) {
				max2 = height[u];
			}
		}
	}

	int sum = 0;

	for (auto u : adj[cur]) {
		if (u != par) {

			// Calculate the maximum distance
			// with ancestor for every node
			sum = ((max1 == height[u]) ? max2 : max1);

			if (max1 == height[u])
				dist[u]
					= 1 + max(1 + max2, dist[cur]);
			else
				dist[u]
					= 1 + max(1 + max1, dist[cur]);

			// Calculating for children
			dfs2(u, cur);
		}
	}
}

// Driver Code
int main()
{
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        addEdge(u,v);
    }
    dfs1(1, 0);
    dfs2(1,0);
    while(q--){
        int a,b,k;
        cin >> a >> b >> k;
        int ans = (max(dist[a], height[a]));
        cout << ans << '\n';
    }
	return 0;
}
