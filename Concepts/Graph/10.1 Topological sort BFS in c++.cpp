#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> topo(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(n, 0);
        vector<int> topoSortedList(n);

        // update the indegree array with the indegree's of all the nodes
        for(int i = 0; i < n; ++i)
        {
            // For getting the total number of incoming edges, we need to traverse the adjacent of each node, 
            // because the adjacent nodes are having an incoming edge from the parent node whose adjacents we are exploring  
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        // take all the nodes whose indegree is 0 and put them into the queue.
        for(int i = 0; i < n ; ++i)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topoSortedList.push_back(node);

            // decerementing the indegree of adjacent nodes by 1 and if their indegree reduces to 0, then push them into the queue.
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topoSortedList;
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