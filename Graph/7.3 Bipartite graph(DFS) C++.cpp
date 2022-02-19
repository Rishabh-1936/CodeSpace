// Concept is if I am able to color every vertex as per the rule of bipartite graph then it is a bipartite graph.
// the solution is same as DFS, just instead of visited array we use color array who also represent not visited if -1

#include<bits/stdc++.h>

bool isBipartite(int s, int colorCode, vector<int> adj[], vector<int> &color)
{
    color[s] = colorCode;

    for(auto it : adj[s])
    {
        if(color[it] == -1)
        {
            // found a node which is not color, so coloring this node with the opposite color of the adjacent node

            if(!isBipartite(it, 1 - colorCode, adj, color))
            {
                // this component is found to be non-bipartite (in case of multiple component)
                return false;
            }
        }
        else if(color[it] == colorCode){
                // found a node which is already colored and has the same color as the adjacent node, so as this component is
                // not bipartite, so the whole graph is also not bipartite.
            return false;
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
            if(!isBipartite(i, 0, adj, color))
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
	
	if(checkBipartite(adj, n)) {
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


/*
Another version:

bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {
                return false; 
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}

*/