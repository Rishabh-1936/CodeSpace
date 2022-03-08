#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(checkForCycle(it, node, vis, adj)){
                return true;
            }
        }
        else if(parent != it){
            //cycle detected as parent of current node is not equal to the adjacent of the current node
            // or we say that node 'it' is visited and t iss not equal to the parent of the cureent node.
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> &vis, vector<int> adj[]){
    for(int i = 0; i < V; ++i){
        if(!vis[i]){
            if(checkForCycle(i, -1, vis, adj)){
                return true;
            }
        }
    }
    return false;
}

bool checkForCycle_BFS(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    vector<int> parent(V, -1);

    for(int i = 0; i < V; ++i){
        if(!vis[i]){
            queue<int> q;
            vis[i] = 1;
            parent[i] = -1;
            q.push(i);

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        parent[it]=node;
                        q.push(it);
                    }
                    else if(it != parent[node]){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool checkForCycle_BFS_2(int V, vector<int> adj[]){
    vector<int> vis(V, 0);

    for(int i = 0; i < V; ++i){
        if(!vis[i]){
            queue<pair<int, int>> q;
            vis[i] = 1;
            q.push({i,-1});

            while(!q.empty()){
                int node = q.front().first;
                int par = q.front().second;
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push({it, node});
                    }
                    else if(it != par){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void DFS(int node, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            DFS(it, vis, adj);
        }
    }
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

    vector<int> vis(n, 0);
    cout << "Is Cycle DFS:"<<endl;
    cout << isCycle(n, vis, adj);
    cout << endl;
    
    cout << "\nIs Cycle BFS-1:"<<endl;
    cout << checkForCycle_BFS(n, adj);
    cout << endl;

    cout << "\nIs Cycle BFS-2:"<<endl;
    cout << checkForCycle_BFS_2(n, adj);
    cout << endl;


    return 0;
}