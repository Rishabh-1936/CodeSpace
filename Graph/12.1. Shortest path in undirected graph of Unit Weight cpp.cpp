
void BFS(int n, vector<int> adj[], int src)
{
    vector<int> dist(n, INT_MAX);
    // or
    // int dist[N];
	// for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
    queue<int> q;

    // making the distance of source node 0 as the distance of source node from itself is always 0 until mentioned something
    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it : adj[node])
        {   
            // if the new distance is less than the previous distance then update the distance and push that node into the queue. 
            if(dist[node] + 1 < dist[it])
            {
                q.push(it);
                dist[it] = dist[node] + 1;
            }
        }
    }

	for(int i = 0; i < n; i++) cout << dist[i] << " \n"; 
}
