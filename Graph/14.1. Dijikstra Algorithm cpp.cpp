/*
    Note: By default, C++ creates a max-heap for priority queue.

    How to create a min-heap for the priority queue? 
        C++ provides the below syntax for the same.  

    Syntax:
        priority_queue <int, vector<int>, greater<int>> g = gq;  

*/
#include<bits/stdc++.h>
using namespace std;

void shortestPath(int source, int n, vector<pair<int,int> > adj[])
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq; // min-heap ; In pair => (dist,from)
    vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 

	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for(auto it : adj[prev])
        {
            int nextNode = it.first;
            int nextDist = it.second;
            if(distTo[prev] + nextDist < distTo[nextNode])
            {
                 distTo[nextNode] = distTo[prev] + nextDist;
                 pq.push(make_pair( distTo[nextNode], nextNode));
            }
        }
        
    // Without for-each loop:
    /*
        vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
    */
    }
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
}


int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	shortestPath(source, n+1, g);
	return 0;
}