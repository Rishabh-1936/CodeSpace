/*
In Out time is the base for the other algortihms. In this algorithm we need to maintain the entry point time of the node and
exit point of the node.

This concept can be used to detect whether one node lies in the subtree of other node.
For that if the 
        inTime[B] > inTime[A] and outTime[B] < outTime[A]
then B is in the subtree of A.
*/

#include<bits/stdc++.h>

using namespace std;

void DFS(int node, int &timer, vector<int> &vis, vector<int> adj[], vector<int> &inTime, vector<int> &outTime){
    vis[node] = 1;
    inTime[node] = ++timer;
    
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            DFS(it, timer, vis, adj, inTime, outTime);
        }
    }
    
    outTime[node] = ++timer;
}

bool check(int n, vector<int> adj[], int node1 , int node2)
{
    vector<int> inTime(n,0);
    vector<int> outTime(n,0);
    vector<int> vis(n,0);
    int timer = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            DFS(i, timer, vis, adj, inTime, outTime);
        }
    }
    
    if(inTime[node2] > inTime[node1] && outTime[node2] < outTime[node1])
    {
        return true;
    }
    
    return false;
}

int main(){

    int n, e, n1, n2, u, v;
    cin >> n >> e;
    
    vector<int> adj[n];

    while(e--){
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cin >> n1 >> n2;
    
    if(check(n, adj, n1, n2)){
        cout << "Found!!!";
    }
    else{
        cout << "Not Found!!!";
    }   
    
    return 0;
}