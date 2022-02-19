#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

// DFS implementation of the topological sort
void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<pair<int,int>> adj[])
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(!vis[it.first])
        {
            findTopoSort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}

void shortestPath(int src, int n, vector<pair<int,int>> adj[])
{
    vector<int> vis(n, 0);
    // int vis[N] = {0};
    vector<int> dist(INF, 0);
    // vector<int> dis(1e9, 0);
    stack<int> st;

    for(int i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            findTopoSort(i, vis, st, adj);
        }
    }

    // setting the distance of the source node to 0
    dist[src] = 0;

    // stack store the order of the nodes in the topological order that's the order of the dependency of the nodes
    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(dist[node] != INF)
        {
            for(auto it : adj[node])
            {
                if(dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        (dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";
        cout << "\n"; 
    }
}


int main() 
{ 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	shortestPath(0, n, adj); 

	return 0; 
} 