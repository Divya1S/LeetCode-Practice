//Shortest path in undirected graph with unit weights 

//Problem Statement 
Given an undirected graph with N vertices (numbered from 0 to N-1) and M edges of unit weight (each edge has weight 1)
find the shortest path distance from the source vertex 0 to every other vertex in the graph.
If a vertex cannot be reached from vertex 0 return -1 for that vertex.

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M) {
        // Build the adjacency list
        vector<vector<int>> adj(N);
        for (const auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Initialize distances to infinity (1e9) and source (0) to 0
        vector<int> dist(N, 1e9);
        int src = 0;
        dist[src] = 0;

        // Standard BFS for unit-weight shortest paths
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[node] + 1 < dist[neighbor]) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        // Replace unreachable distances (1e9) with -1
        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i];
            }
        }

        return ans;
    }
};

TC: O(N + M)
building the adjacency list takes O(M) time 
BFS visits each vertex at most once and explores each undirected edge twice taking O(N + 2M) time 
Preparing the final answer vector takes O(N) time 

SC: O(N + M)
The adjacency list stores N vertices and 2M edge entries O(N + M)
The dist array, ans array, and BFS queue takes upto O(N) space 
