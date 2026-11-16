// 1. When you MUST build the Adjacency List
// Use this when the problem provides the number of vertices (V) and a list of edges (e.g., [[0,1], [1,2]]). 
// You have to construct the adj array before you can traverse it. 
// This matches the commented-out portion of your reference code.

class Solution {
  public:
    // Helper function to perform the actual BFS traversal
    void bfs(vector<vector<int>> &adj, int u, vector<bool>& visited, vector<int>& result) {
        queue<int> que;
        
        que.push(u);
        visited[u] = true;
        result.push_back(u);
        
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            
            for (int &v : adj[curr]) {
                if(!visited[v]) {
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    
    // Main function: Input is vertices V and raw edges
    vector<int> bfsOfGraph(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);

        // We MUST build the adjacency list from the raw edges
        for (auto edge : edges) {
             int u = edge[0];
             int v = edge[1];

             adj[u].push_back(v);
             adj[v].push_back(u); // Assuming an undirected graph
        }
        
        vector<bool> visited(V, false);
        vector<int> result;
        
        bfs(adj, 0, visited, result);
        
        return result;
    }
};

// 2. When you DO NOT need to build the Adjacency List
// Use this when the platform already passes vector<vector<int>> &adj directly into your main function. 
// Since the connections are already built for you, you can skip the edge-loop entirely and jump straight into the traversal.

class Solution {
  public:
    // Helper function to perform the actual BFS traversal
    void bfs(vector<vector<int>> &adj, int u, vector<bool>& visited, vector<int>& result) {
        queue<int> que;
        
        que.push(u);
        visited[u] = true;
        result.push_back(u);
        
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            
            for (int &v : adj[curr]) {
                if(!visited[v]) {
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    
    // Main function: Input IS the adjacency list
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int V = adj.size(); 
        
        // We DO NOT build the list because 'adj' is already provided
        
        vector<bool> visited(V, false);
        vector<int> result;
        
        bfs(adj, 0, visited, result);
        
        return result;
    }
};
