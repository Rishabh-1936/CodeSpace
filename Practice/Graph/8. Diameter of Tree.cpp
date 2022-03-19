/*
    To find the diameter of a tree(which is the longest path in the tree). The implemented solution won't work, in which
    we are just running one DFS to get the maximum distance. As the below implementation will only work when the starting 
    node is any terminal node. As we are not sure that the current node we choose is the terminal node.

    But when we run the DFS from any node, the DFS always find the terminal node. If the DFS is run on any in-middle node
    then one run won't give the maximum distance but it is for sure that it will give one-of-the terminal node of the graph.

    So there are 2 solutions:
    1.  Running DFS 'N' times for the 'n' nodes individually taking each node as a source node and finding the maximum distance.
        But it is having a T.C. = O(N*N).
    
    2.  Running 2 DFS approach. In it 1st DFS is run over any random node as a source node and finding the maximum distance 
        with the node having that distance. Then validating the maximum distance and node by running the DFS over that node 
        again, which will anyhow find the actual maximum distance.

*/

#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007

using namespace std;

void DFS(lli node, vector<lli> &vis, vector<lli> adj[], lli &diameter, int depth)
{
    vis[node] = 1;
    if(diameter < depth){
        diameter = depth;
    }
    for(auto it: adj[node])
    {
        if(!vis[it]){
            DFS(it, vis, adj, diameter, depth+1);
        }
    }
}

void check(lli n, vector<lli> adj[])
{
    vector<lli> vis(n,0);
    lli depth = 1, diameter = 1;

    for(int i = 1; i < n; ++i)
    {
        if(!vis[i])
        {
            depth = 1;
            DFS(i, vis, adj, diameter, depth);
        }
    }
}

int main(){

    int n, e, n1, n2, u, v;
    cin >> n >> e;
    
    vector<int> adj[n];

    while(e--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    check(n, adj);


    return 0;
}