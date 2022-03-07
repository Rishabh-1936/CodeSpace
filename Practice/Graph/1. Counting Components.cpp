#include<bits/stdc++.h>

using namespace std;

int connectComponent_BFS(int V, vector<int> adj[]){
    int components = 0;
    vector<int> vis(V, 0);
    
    for(int i = 0; i < V; ++i)
    {
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            ++components;
            
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return components;
}

void connectComponent_DFS(int node, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            connectComponent_DFS(it, adj, vis);
        }
    }
}

int connectComponent_DFS_util(int V, vector<int> adj[]){
    vector<int> vis(V,0);
    int components = 0;
    for(int i = 0; i<V;++i){
        if(!vis[i]){
            ++components;
            connectComponent_DFS(i, adj, vis);
        }
    }
    return components;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    int u, v;

    while(m--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Connected Components : BFS"<<endl;
    cout << connectComponent_BFS(n, adj);
    cout << endl;
    cout << "Connected Components : DFS"<<endl;
    cout << connectComponent_DFS_util(n, adj);

    return 0;
}