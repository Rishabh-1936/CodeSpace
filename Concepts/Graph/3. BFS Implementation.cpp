Basic idea is that we need to traverse each node(until it is not mentioned that there is only 1 component) and maintain a visited Array.
The BFS is a level-order-traversing and uses Queue for its implementation.
1. First loop through all the nodes
2. If not-visited then push into the Queue
3. Then pop the top element and loop through all iths neighbour and mark their visited true and add them into the queue.

//Java Implementation -> Iterative

public ArrayList<Integer> bfsTraversal(int V,  ArrayList<ArrayList<Integer>> adj)
{
    ArrayList<Integer> bfs = new ArrayList<>();
    boolean vis[] = new boolean[V+1]; // as 0 indexing and V are 1 indexing

    for(int i = 0; i <= V; ++i)
    {
        if(vis[i] == false)
        {
            Queue<Integer> q = new LinkedList<Integer>();
            q.add(i);
            vis[i] = true;

            while(!q.empty())
            {
                Integer node = q.poll(); // to get the head element
                bfs.add(node);

                for(Integer it: adj.get(node))
                {
                    if(vis[it] == false)
                    {
                        vis[it] = true;
                        q.add(it);
                    }
                }
            }
        }
        // counter++  // for the number of connected components.
    }
    return bfs;
}

// According to this implementation, when the control comes out to that first if-statement it means that it has traversed 1 component 
// completely. So in this manner we can keep a counter over the number of connected components.


//---------------------------------------------------------------------------------------------------------------------------------------


CPP implementation:
-------------------

vector<int> bfsTraversal(int V, vector<int> adj[]){
    
    vector<int> vis(V+1, 0);
    vector<int> bfs(V);

    for(int i = 0; i <= V; ++i)
    {
        if(!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it : adj[node])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}