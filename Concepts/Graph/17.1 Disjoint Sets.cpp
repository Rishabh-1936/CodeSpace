#include<bits/stdc++.h>
using namespace std;

void makeSet(vector<int> &parent,vector<int> &rank)
{
    for(int i = 1; i <= n; ++i)
    {
        parent[i] = ii;
        rank[i] = 0;
    }
}

// let sequence be 6->4->3
int findPar(int node, vector<int> &parent)
{
    // the parent of the node is the same node itself
    if(parent[node] == node){
        return node;
    }
    // will return the parent of the current node (like for 3 it will call the findPar() at 4 and then at 6)
    return findPar(parent[node]);
}

// path compression
int findPar_PathCompression(int node, vector<int> &parent)
{
    // the parent of the node is the same node itself
    if(parent[node] == node){
        return node;
    }
    // will set and return the ultimate parent of each node (like for 3 it will call the findPar() at 4 and then at 6)
    // and will set the root parent of node 3 is 6 and return 6.
    return parent[node] = findPar_PathCompression(parent[node]);
}

void union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    // to get the ultimate parent of each node to identify from which set they belong to.
    u = findPar(u);
    v = findPar(v);
    if(u == v){
        cout<<"Belong to same set"<<endl;
        return;
    }
    // if the parent of both the nodes is not same, it means they belong to different disjoint sets. 
    // So the set having lower rank will get merged into the set with higher rank.
    // This is done to make the terminal node to root parent travesal easy as shorter tree is merged with
    // the tree of larger height.

    // Rank doesn't specify the actual height in the tree concept but treated as a criteria to distinguish
    // which set/tree is having more nodes in the term of level.
    // whenever two sets/tree with same ranks are merged only at that point the rank of the one in which
    // the other is merged is increased by one because at this point new level is introduced
    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rank[u]++;
    }
}

int main()
{
    int n = 10, m;
    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank);
    cin >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        union(u, v, parent, rank);
    }

    if(findPar(2) != findPar(3)){
        cout << "Different Components";
    }
    else{
        cout<<"Same Components";
    }

    return 0;
}

/*
Let there be 4 elements 0, 1, 2, 3

Initially, all elements are single element subsets.
0 1 2 3 

Do Union(0, 1)
   1   2   3  
  /
 0

Do Union(1, 2)
     2   3   
    /
   1
 /
0

Do Union(2, 3)
         3    
        /
      2
     /
   1
 /
0

The above operations can be optimized to O(Log n) in worst case.
The idea is to always attach smaller depth tree under the root of the deeper tree.
This technique is called union by rank. The term rank is preferred instead of height because if path compression technique 
(we have discussed it below) is used, then rank is not always equal to height. 
Also, size (in place of height) of trees can also be used as rank. Using size as rank also yields 
worst case time complexity as O(Logn).

Let us see the above example with union by rank
Initially, all elements are single element subsets.
0 1 2 3 

Do Union(0, 1)
   1   2   3  
  /
 0

Do Union(1, 2)
   1    3
 /  \
0    2

Do Union(2, 3)
    1    
 /  |  \
0   2   3

The second optimization to naive method is Path Compression. The idea is to flatten the tree when find() is called. 
When find() is called for an element x, root of the tree is returned. 
The find() operation traverses up from x to find root. The idea of path compression is to make the found root as 
parent of x so that we don’t have to traverse all intermediate nodes again. 
If x is root of a subtree, then path (to root) from all nodes under x also compresses.

Let the subset {0, 1, .. 9} be represented as below and find() is called
for element 3.
             9
         /   |   \  
        4    5    6
       /         /  \
      0         7    8
     /        
    3
   / \         
  1   2
When find() is called for 3, we traverse up and find 9 as representative
of this subset. With path compression, we also make 3 and 0 as the child of 9 so 
that when find() is called next time for 0, 1, 2 or 3, the path to root is reduced.

        --------9-------
      /   /    /  \      \
     0   4    5    6       3 
                  /  \    /  \
                 7    8   1   2
The two techniques complement each other. The time complexity of each operation becomes even smaller than O(Logn). 
In fact, amortized time complexity effectively becomes small constant. 


*/