/*
    Calculating the size of subtree. 
    
    Approach: 
    1.  DFS is used to get the size of subtree for every node.
    2. 2 arrays are maintained, one is for visited and another is for subSize.

*/

#include<bits/stdc++.h>
#define lli int
#define mod 1000000007

using namespace std;

int DFS(lli node, vector<lli> &vis, vector<lli> adj[], vector<lli> &subSize)
{
    int curSize = 1;
    vis[node] = 1;

    for(auto it: adj[node])
    {
        if(!vis[it]){
            curSize += DFS(it, vis, adj, subSize);
        }
    }
    subSize[node] = curSize;
    return curSize;
}

int main(){

    int n, e, n1, n2, u, v;
    cin >> n >> e;
    
    vector<int> adj[n];
    vector<lli> vis(n,0);
    vector<lli> subSize(n,0);

    while(e--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(lli i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            DFS(i, vis, adj, subSize);
        }
    }

    cout << "Size of sub-tree of each node:" << endl;
    for(int i = 0; i < n; ++i){
        cout << i << ":" << subSize[i] << endl;
    }

    return 0;
}

/*
Input:
8 6
1 2
2 3
3 7
2 4
4 5
4 6

Output:
Size of sub-tree of each node:
0:1
1:7
2:6
3:2
4:3
5:1
6:1
7:1

*/