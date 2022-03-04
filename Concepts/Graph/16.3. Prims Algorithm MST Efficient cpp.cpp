/*
This implementation is memory and time efficient.
T.c = O(N*log(N)) => {T.C = N*log(N+E)}
S.C = O(N) => 5*N

This implementation uses the priority_queue for finding the minimal, which uses heap for it's implementation 
In priority_queue, for fetching the minimum takes O(log(N)) time.

*/

#include<bits/stdc++.h>
using namespace std;

void findMSTbyPrims(int N, vector<pair<int, int>> adj[], int src)
{
   vector<int> parent(N, -1);
   vector<bool> mst(N, false);
   vector<int> key(N, INT_MAX);
   int finalWeight = 0;
   
   // in priority_queue, the storage pattern is {key value, node}
   priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
   
   // mst[idx] = false means that this node is not the part of the current MST.
   key[src] = 0;
   parent[src] = -1;
   // Run the loop till all the nodes have been visited
   // because in the brute code we checked for mst[node] == false while computing the minimum
   // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
   // hence its better to keep running till all the nodes have been taken. 
   pq.push({key[src], src});
   
   // We know that for MST there are N-1 edges.
   for(int count = 0; count < N-1; ++count )
   {
      // node with minimum weight
      int u = pq.top().second;
      int mini = pq.top().first;
      pq.pop();

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
            parent[v] = u;
            key[v] = weight;
            pq.push({key[v], v});
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


// try the following case: 
// 6 7 
// 0 1 5 
// 0 2 10 
// 0 3 100 
// 1 3 50 
// 1 4 200
// 3 4 250
// 4 5 50

/*
   while(!pq.empty())
   { 
      int u = pq.top().second; 
      pq.pop(); 

      mstSet[u] = true; 

      for (auto it : adj[u]) {
         int v = it.first;
         int weight = it.second;
         if (mstSet[v] == false && weight < key[v]) {
            parent[v] = u;
   		   key[v] = weight; 
            pq.push({key[v], v});    
         }
      }
   } 

*/