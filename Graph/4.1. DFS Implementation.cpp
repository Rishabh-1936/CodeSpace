Basic idea is that we need to traverse each node(until it is not mentioned that there is only 1 component) and maintain a visited Array.
The DFS is a depth-order-traversing and uses Stack for its implementation.
1. First loop through all the nodes
2. If not-visited then push into the Stack
3. Then pop the top element and loop through it till its depth/end and mark their visited true and add them into the stack.


CPP implementation:
-------------------
1. Iterative

vector<int> dfsTraversal(int v, vector<int> adj[])
{
    vector<int> vis(v+1, 0);
    vector<int> dfs(v);
    
    for(int i = 0; i < v; ++i)
    {
        if(!vis[i])
        {
            stack<int> s;
            s.push(i);
            vis[i] = 1;
            
            while(!s.empty())
            {
                int node = s.top();
                s.pop();
                dfs.push_back(bode);

                // for(auto it:adj[node])
                // the adjacency list of the current node is reversed because we need node exploration left to right 
                // if the list is not reversed then the top node will be the last node of the list and node exploration 
                // will be right to left
                vector<int> reverse_adj_list(adj[node].rbegin(),adj[node].rend());
                for(auto it : reverse_adj_list)
                {
                    if(!vis[it])
                    {
                        vis[it] = 1;
                        s.push(it);
                    }
                }
            }
        }
    }
    return dfs;
}
// According to this implementation, when the control comes out to that first if-statement it means that it has traversed 1 component 
// completely. So in this manner we can keep a counter over the number of connected components.


//---------------------------------------------------------------------------------------------------------------------------------------

========================================

2. Recursive

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfsTraversal)
{
    storeDfsTraversal.push_back(node);
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it, vis, adj, storeDfsTraversal);
        }
    }
}

vector<int> dfsTraversal(int v, vector<int> adj[])
{
    vector<int> vis(v+1, 0);
    vector<int> storeDfsTraversal(v);
    
    for(int i = 0; i < v; ++i)
    {
        if(!vis[i])
        {
            dfs(i, vis, adj, storeDfsTraversal);
        }
    }
    return storeDfsTraversal;
}