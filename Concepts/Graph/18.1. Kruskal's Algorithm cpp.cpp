#include<bits/stdc++.h>

using namespace std;

struct Node{
    int u;
    int v;
    int wt;
    Node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(Node a, Node b){
    // as need to sort in ascending order that's whenever weight of first node is less than the weight of second node we 
    // want to preserve that order by keeping the first node ahead of second node, so return true.
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) 
        return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(u == v){
        return;
    }
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main()
{
	int N,m;
	cin >> N >> m;
	vector<node> edges; 

	for(int i = 0; i < m; i++) 
    {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.push_back(node(u, v, wt)); 
	}
	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(N);
	vector<int> rank(N, 0); 

	for(int i = 0; i < N; i++) 
	    parent[i] = i; 
        
	int cost = 0;
	vector<pair<int,int>> mst; 

	for(auto it : edges) {
	    if(findPar(it.u, parent) != findPar(it.v, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}