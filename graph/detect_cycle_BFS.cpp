// Function to detect cycle in an undirected graph.
bool detect(int src, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[src] = 1;
    
    queue<pair<int, int>> q;
    q.push({src, -1}); // {current node, parent}
    
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1;
                q.push({neigh, node}); // Push neighbor with current node as parent
            } else if (neigh != parent) {
                // If visited and not the parent, a cycle is detected
                return true;
            }
        }
    }
    
    return false; // No cycle found
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, 0); // Visited array
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) { // If node is not visited
            if (detect(i, adj, vis)) {
                return true;
            }
        }
    }
    
    return false; // No cycle in the graph
}
