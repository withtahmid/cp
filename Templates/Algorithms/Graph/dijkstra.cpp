void dijkstra(const auto& adj, auto& dist, int n, int u) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, u));
    dist[u] = 0;
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second;

        if (dist[u] != t.first)
            continue;

        for (auto x : adj[u]) {
            int v = x.second;
            int w = x.first;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

/**
 * @param n number of vertices (0-based)
 * @param u source vertex
 * @pair<weight, destination>
 * @dijkstra(adjList, distArr, numOfNodenode, src);
 */