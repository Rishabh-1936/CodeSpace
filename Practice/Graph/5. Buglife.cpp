// SPOJ Problem: BUGLIFE : https://www.spoj.com/problems/BUGLIFE/

#include<bits/stdc++.h>
using namespace std;

bool checkExperiment(int node, int gen, vector<int> &gender, vector<int> adj[]){
    gender[node] = gen;
    for(auto it: adj[node]){
        if(gender[it] == -1){
            // returns when experiment is false
            if(!checkExperiment(it, 1 - gen, gender, adj)){
                return false;
            }
        }
        // bugs with same gender interacts and returns as experiment is false
        else if(gender[it] == gen){
            return false;
        }
    }
    return true;
}

string experimentUtil(int V, vector<int> adj[]){
    vector<int> gender(V, -1);
    for(int i = 1; i < V; ++i){
        if(gender[i] == -1){
            if(!checkExperiment(i, 0, gender, adj)){
                return "Suspicious bugs found!";
            }
        }
    }
    return "No suspicious bugs found!";
}

int main(){
    int b, u, v, n, m;
    vector<string> result;
    cin >> b;
    
    for(int i = 0; i < b; ++i)
    {
        cin >> n >> m;
        vector<int> adj[n+1];
        
        for(int j = 0; j < m; ++j)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        result.push_back(experimentUtil(n+1, adj));
    }
    
    for(int i = 0; i < b; ++i){
        cout<<"Scenario #"<<(i+1)<<":\n";
        cout<<result[i]<<endl;
    }
    return 0;
}