#include<bits/stdc++.h>

using namespace std;

void SSSP(int V, int src, vector<int> adj[]){
    
    vector<int> vis(V, 0);
    vector<int> dis(V, 0);

    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dis[src] = 0;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                dis[it] = dis[node]+1;
                q.push(it);
            }
        }
    }
    
    // print the distance
    for(int i = 0; i < dis.size(); ++i){
        cout << i << ":" << dis[i] << endl;
    }
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

    cout << "SSSP"<<endl;
    cout << SSSP(n, adj, 0);
    cout << endl;


    return 0;
}