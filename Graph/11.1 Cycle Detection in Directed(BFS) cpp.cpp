#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isCyclic(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> topologicalSorted;
        int cnt =0;
        vector<int> indegree(n, 0);

        // updating the value of indegree-array by counting the total number of incoming edges to each node
        for(int i = 0; i < n; ++i)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        // pushing those nodes whose indegree is zero into the queue
        for(int i = 0; i < n; ++i)
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
            ++cnt;
            // topologicalSorted.push_back(node);

            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        // if there is no cycle then all the nodes will get pushed and poped out from the queue and this will leads
        // to the value of the counter equal to 'n'(the number of vertices)
        // So if there is no cycle, it means cnt = n then return false otherwise true.
        // or you can check the size of the topologicalSorted array, as if it is equal to 'n' then also return false.
        if(cnt == n)    return false;
        return true;
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