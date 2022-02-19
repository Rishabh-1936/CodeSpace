// the idea for cycle detection is same as bfs as if the adjacent node is already visited and it's parent is not same as current node parent then there is a cycle.


bool checkForCycle(int node, int parent, vector<int> adj[], vector<int>& vis ){
    vis[node] = 1;
    
    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            if(checkForCycle(it, node, adj, vis)){
                return true;
            }
            else if(it != parent)
            {
                return true;
            }
        }
    }
    return false;
}


bool isCycle(int v, vector<int> adj[])
{
    vector<int> vis(v+1, 0);
    for(int i = 0; i <= v; ++i)
    {
        if(!vis[i])
        {
            if(checkForCycle(i, -1, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}