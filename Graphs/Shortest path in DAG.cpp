class Solution {
private:
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto& it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                dfs(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        //Build the adjacency list: adj[u] = {v, weight}
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        //Find topological sort order using DFS
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        //Relax edges in topological order
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            // Only relax if u is reachable from source 0
            if (dist[u] != INT_MAX) {
                for (auto& it : adj[u]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        //Replace unreachable vertices with -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

// TC: O(N + M)
// Building the adjacency list takes O(M)
// DFS visites vertex and edges once O(N + M)
// Relaxing all edges while popping from the stack takes O(N + M)

// SC: O(N + M)
// The adjacency list stores N lists and M esges: O(N + M)
// The vis array dist array and topological stack and DFS recursion stack 
// each take O(N) space 
