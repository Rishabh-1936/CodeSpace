// Concept is if I am able to color every vertex as per the rule of bipartite graph then it is a bipartite graph.
// the solution is same as BFS, just instead of visited array we use color array who also represent not visited if -1


bool isBipartite(int s, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(s);
    color[s] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it : adj[node])
        {
            if(color[it] == -1)
            {
                // found a node which is not color, so coloring this node with the opposite color of the adjacent node
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node])
            {
                // found a node which is already colored and has the same color as the adjacent node, so as this component is
                // not bipartite, so the whole graph is also not bipartite.
                return false;
            }
        }
    }

    // successfully able to color all the nodes of this component whose source node is 's' with 2 different colors
    return true;
}


bool checkBipartite(int v, vector<int> adj[])
{
    vector<int> color(v , -1);
    // or 
    // int color[v]; 
    // memset(color, -1, sizeof color);

    // check for each component whether it is a bipartite or not, and any one component is found to be non-bipartite then return false
    for(int i = 0; i <= v; ++i)
    {
        // to check if the current vertex is colored or not (or I mean visited or not) 
        if(color[i] == -1)
        {
            if(!isBipartite(i, adj, color))
            {
                // this component is found to be non-bipartite (in case of multiple component)
                return false;
            }
        }
    }
    // all components are trarvesed/colored and are bipartite also.
    return true;
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
	
	if(checkBipartite(n, adj)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/
