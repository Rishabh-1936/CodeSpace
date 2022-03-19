/*
    SPOJ Problem: https://www.spoj.com/problems/PT07Z/
    
    Approach:
    Diameter of a Tree (2 DFS approach is used)
*/
#include<bits/stdc++.h>
#define lli int
#define mod 1000000007

using namespace std;

int diameter, maxNode;

void DFS(lli node, vector<lli> &vis, vector<lli> adj[], lli depth)
{
    vis[node] = 1;
    if(diameter < depth){
        diameter = depth;
        maxNode = node;
    }

    for(auto it: adj[node])
    {
        if(!vis[it]){
            DFS(it, vis, adj, depth+1);
        }
    }
}

int main(){

    int n, e, n1, n2, u, v;
    cin >> n;
    e=n-1;
    n++;
    
    vector<int> adj[n];
    vector<lli> vis(n,0);
    lli depth = 0;

    while(e--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    diameter = -1;
    maxNode = -1;

    for(lli i = 1; i < n; ++i)
    {
        if(!vis[i])
        {
            depth = 0;
            DFS(i, vis, adj, depth);
        }
    }

    vis.assign(n, 0);
    DFS(maxNode, vis, adj, 0);
    
    cout << diameter << endl;

    return 0;
}