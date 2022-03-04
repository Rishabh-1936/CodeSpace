#include <bits/stdc++.h>
using namespace std;

void DFS(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[])
{
	vis[node] = 1;
	tin[node] = low[node] = timer++;

	for(auto it : adj[node])
	{	
		// edge leading back to the parent in DFS tree
		if(it == parent)	continue;

		// adjacent node is not visited
		if(!vis[it])
		{
			DFS(it, node, vis, tin, low, timer, adj);
			
			// updating the lowest time in-case of there was any back-edge found at any of the ancestors/decendents
			low[node] = min(low[node], low[it]);
			
			// checking for the bridge
            if(low[it] > tin[node]) {
                cout << node << " " << it << endl;
            }
		}
		else
		{
			// Back-edge found so just updating the lowest possible time to reach the node.
            low[node] = min(low[node], tin[it]); 
        }

	}
}

int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        DFS(i, -1, vis, tin, low, timer, adj); 
	    }
	}
	
	return 0;
}