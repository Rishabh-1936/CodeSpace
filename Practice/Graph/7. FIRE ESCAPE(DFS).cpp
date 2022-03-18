/*
    Problem on Codechef : https://www.codechef.com/problems/FIRESC 
    TAGS: depth-first-search, simple, union-find

    Approach:
    1. As to maximize the number of exits we are counting the number of components as friends are sharing the same exits and to maximize
    the number of exits we are introducing one new exit for each friend group.
    2. To count the number of routes, so it is just a simple permutation formula, in which the total number of routes is equal to 
    multiplication of the size of each group.
*/

#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007

using namespace std;

void DFS(lli node, vector<lli> &vis, vector<lli> adj[], lli &friends)
{
    vis[node] = 1;
    for(auto it: adj[node])
    {
        if(!vis[it]){
            ++friends;
            DFS(it, vis, adj, friends);
        }
    }
}

void check(lli n, vector<lli> adj[])
{
    vector<lli> vis(n,0);
    lli comp = 0, routes = 1, friends = 1;

    for(int i = 1; i < n; ++i)
    {
        if(!vis[i])
        {
            ++comp;
            friends = 1;
            DFS(i, vis, adj, friends);
            routes = (routes * friends) % mod;
        }
    }
   cout << comp << " " << routes << endl;
}

int main(){

    lli t, f, r, u, v;
    cin >> t;
    
    while(t--)
    {
        cin >> f >> r;
        f++;
        vector<lli> adj[f];
        
        while(r--)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        check(f, adj);
    }
    return 0;
}