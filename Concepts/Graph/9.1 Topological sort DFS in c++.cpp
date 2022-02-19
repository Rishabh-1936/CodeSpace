#include <bits/stdc++.h>
using namespace std;

class Solution{

    void findTopoSort(int node, vector<int>& adj, vector<int> &vis, stack<int>& st)
    {
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                findTopoSort(it, adj, vis, st);
            }
        }
        
        // when all the dependent node(i.e adjacent nodes are visited then push the parent node into the stack)
        st.push(node);
    }

 	public:

    vector<int> topoSort(int n, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(n, 0);
        vector<int> topoSortedList(n);

        for(int i = 0; i < n; ++i)
        {
            if(!vis[i])
            {
                findTopoSort(i, adj, vis, st);
            }
        }

        while(!st.empty())
        {
            topoSortedList.push_back(st.top());
            st.pop();
        }

        return topoSortedList;
    }

};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  