#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkCycle(int node, vector<int> adj[], vector<int> vis[], vector<int> dfsVis[]) 
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(checkCycle(it, adj, vis, dfsVis))
                {
                    return true;
                }
            }
            else if(dfsVis[it])
            {
                // the adjacent node is visited and in the current dfs visit stack also it is visited, it means whenever the 
                // dfsVis is showing the node is visited, it means it is visted in its current traversal and currently in stack and its 
                // adjacent nodes are traversing in the current iteration. 
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int N, vector<int> adj[])
    {
        vector<int> vis(N, 0);
        vector<int> dfsVis(N, 0);

        for(int i = 0; i < N; ++i)
        {
            if(!vis[i])
            {
                if(checkCycle(i, adj, vis, dfsVis))
                {
                    return true;
                }
            }
        }
        return false;
    }

};




int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}