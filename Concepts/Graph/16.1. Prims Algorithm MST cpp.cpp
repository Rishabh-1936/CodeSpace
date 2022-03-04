/*
This implementation is not memory and time efficient.
T.c = O(N*N) => {T.C > N*N}
S.C = O(N) => 5*N
*/

#include<bits/stdc++.h>
using namespace std;

void findMSTbyPrims(int N, vector<pair<int, int>> adj[], int src)
{
   vector<int> parent(N, -1);
   vector<bool> mst(N, false);
   vector<int> key(N, INT_MAX);

   key[src] = 0;
   // mst[idx] = false means that this node is not the part of the current MST.

   int finalWeight = 0;
   
   // We know that for MST there are N-1 edges.
   for(int count = 0; count <= N-1; ++count )
   {
      int mini = INT_MAX, u = -1;

      for(int v = 0; v < N; ++v)
      {
         // loop for finding the minimal
         if(mst[v] == false && key[v] < mini)
         {
            // The node 'v' is not the part of the current MST and it is having the minimum value
            mini = key[v], u = v;
         }
      }

      // to consider the node with minimum value is 'u', consider it in the current MST
      mst[u] = true;
      finalWeight += mini;

      // Traversing all the adjacent nodes of 'u' and updating the 'key' and 'parent' array
      for(auto it : adj[u])
      {
         int v = it.first;
         int weight = it.second;

         if(mst[v] == false && weight < key[v])
         {
            // If the node 'v' is not taken into the current MST, and the current weight is less than the weight of the node 'v'.
            parent[v] = u, key[v] = weight;
         }
      }

   }

   // printing the MST
   for (int i = 1; i < N; i++) 
   {
      cout << parent[i] << " - " << i <<" \n";
   } 

}

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	

   findMSTbyPrims(N, adj, 0);

	return 0;
}