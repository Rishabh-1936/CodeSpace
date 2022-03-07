// SPOJ Problem: PT07Y : https://www.spoj.com/problems/PT07Y/

#include<bits/stdc++.h>
using namespace std;


void DFS(int node, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            DFS(it, vis, adj);
        }
    }
}

bool isATree(int V, int edge, vector<int> adj[]){
    vector<int> vis(V, 0);
    int components = 0;

    for(int i = 0; i < V; ++i){
        if(!vis[i]){
            DFS(i, vis, adj);
            ++components;
        }
    }

    if(components == 1 && edge == n-1){
        return true;
    }
    return false;
}



int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    int u, v;

    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Is a Tree:"<<endl;
    cout << isATree(n, m, adj);
    cout << endl;


    return 0;
}