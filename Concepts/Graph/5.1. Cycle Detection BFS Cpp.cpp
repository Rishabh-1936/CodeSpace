/*
The idea is for BFS is that we need to keep track of the parent of each node and if we found any adjacent node which is already traversed
it is not equal to it's parent then it means that someone else travesed that node which came from different path.

        1->2->3->5-\
           |        8->9
           4->6->7-/

If we make a bfs traversal over the above graph then after 1 and 2 queue is-> 3,4
after 3 the queue is -> 4,5
after 4 the queue is -> 5,6
after 5 the queue is -> 6,8
after 6 the queue is -> 8,7
after 8 the queue is -> 9

So when 8 is travesed it will found that 7 is traversed but the parent of 8 is 5 while parent of 7 is 6 and 7 is in adjacent of 8
so it means someone else traversed 7 from different path so it concludes that there is a cycle.

*/


bool checkForCycle(int s, int v, vector<int> adj[], vector<int>& vis )
{
    vector<int> parent(v,-1);

    // pair<current_node, parent>
    queue<pair<int,int>> q;
    
    q.push({s, -1});
    vis[s] = 1;

    while(!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push({it, node});
                parent[it] = node;
            }
            else if(par != it)
            // or else if(parent[node] != it)
            {
                return true;
            }
        }
        return false;
    } 

}

bool isCycle(int v, vector<int> adj[])
{
    vector<int> vis(v+1, 0);
    for(int i = 0; i <= v; ++i)
    {
        if(!vis[i])
        {
            if(checkForCycle(i, v, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}