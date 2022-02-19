// Adjacency matrix -> space complexity= O(N*N)

#include<iostream>
using namepace std;

int main(){
    int n; // number of vertices
    cin >> n;
    int adj[n+1][n+1];

    int e; // number of edges
    cin >> e;     

    int u, v;
    // take edge input
    for(int i=0;i<e;++i){
        cin>>u>>v;
        adj[u][v] = 1;
        //if undirected then 
        adj[v][u] = 1;
    }

    return 0;
}

//-----------------------------------------------------------------------/

// Adjacency List -> space complexity= O(V+2E) Generally perefered if number of vertices > 10^5

#include<bits/stdc++.h>
using namepace std;

int main()
{
    int n; // number of vertices
    cin >> n;
    
    vector<int> adj[n];

    int e; // number of edges
    cin >> e;     

    int u, v;
    // take edge input
    for(int i = 0; i < e; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        //if undirected then 
        adj[v].push_back(u);
    }

    return 0;
}

//-----------------------------------------------------------------------/

// Adjacency List with weight -> space complexity= O(V+2E)+2E Generally perefered if number of vertices > 10^5

#include<bits/stdc++.h>
using namepace std;

int main(){
    int  n; // number of vertices
    cin>>n;
    
    // instead of int we will use the pair-> one is connecting vertex \
    // and another is weight associated with that edge
    vector<pair<int,int>> adj[n];

    int e; // number of edges
    cin>>e;     

    int u, v, w;
    // take edge input
    for(int i = 0 ; i < e ; ++i)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        //if undirected then 
        adj[v].push_back({u , w});
    }

    return 0;
}

