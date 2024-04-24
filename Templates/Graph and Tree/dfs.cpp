// using stack
void dfs(const auto& adj, auto& visited, int src){
    fill(visited.begin(), visited.end(), false);
    visited[src] = true;
    stack<int>stk;
    stk.push(src);
    while(not stk.empty()){
        auto u = stk.top();
        stk.pop();
        for(auto i : adj[u]){
            if(not visited[i]){
                visited[i] = true;
                stk.push(i);
            }
        }
    }
}

// using recursion
void dfs(const auto& adj, auto& visited, int src){
    visited[src] = true;
    for(auto i : adj[src]){
        if(not visited[i]){
            dfs(adj, visited, i);
        }
    } 
}

/**
 * dfs(adjList, visitedArr, src)
 * 
 * */ 