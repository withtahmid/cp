void bfs(const auto& adj, auto& dist, int src){
    dist.resize(adj.size());
    fill(dist.begin(), dist.end(), -1);
    dist[src] = 0;
    queue<int>q;
    q.push(src);
    while(not q.empty()){
        auto u = q.front();
        q.pop();
        for(auto i : adj[u]){
            if(dist[i] == -1){
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }
}

/**
 * bfs(adjList, distArr, src)
 * 
 * */ 