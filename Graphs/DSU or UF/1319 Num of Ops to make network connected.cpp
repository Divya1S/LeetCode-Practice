//Using DSU
// class Solution {
// public:
//     vector<int> parent;
//     vector<int> rank;
//     //Path Compression 
//     int find(int i) {
//         if(i == parent[i]) {
//             return i;
//         }

//         return parent[i] = find(parent[i]); //path compression
//     }

//     //Union by Rank 
//     void unionSets(int x, int y) {
//         int x_parent = find(x);
//         int y_parent = find(y);

//         if(x_parent == y_parent) {
//             return;
//         }

//         if (rank[x_parent] > rank[y_parent]) {
//             parent[y_parent] = x_parent;
//         }
//         else if (rank[x_parent] < rank[y_parent]) {
//             parent[x_parent] = y_parent;
//         }
//         else {
//             parent[x_parent] = y_parent;
//             rank[y_parent]++;
//         }
//     }

//     int makeConnected(int n, vector<vector<int>>& connections) {
//         if (connections.size() < n - 1) {
//             return -1;
//         }

//         parent.resize(n);
//         rank.resize(n, 0);

//         for (int i = 0; i < n; i++) {
//             parent[i] = i;
//         }

//         int components = n;

//         for (auto &vec : connections) {
//             if (find(vec[0]) != find(vec[1])) {
//                 unionSets(vec[0], vec[1]);

//                 components--;
//             }
//         }

//         return components - 1;
//     }
// };

// TC: O(V + E * alpha(V))
// initializing parent and rank takes O(V)
// iterating through all E edges performs find and uninSets operations
// with path compression and union by rank each operation takes O(alpha(V)) amortized time 
// alpha is Ackermann function effectively constant 

// SC: O(V)
// Storing the parent and rank arrays require O(V) space 
// the recursion st in find is negligible and bounded well within O(V)

// //dfs
// class Solution {
// public:
//     void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
//         visited[node] = true;
//         for (int neighbor : adj[node]) {
//             if(!visited[neighbor]) {
//                 dfs(neighbor, adj, visited);
//             }
//         }
//     }
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         if (connections.size() < n - 1) {
//             return -1;
//         }

//         vector<vector<int>> adj(n);
//         for (const auto& edge : connections) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }

//         vector<bool> visited(n, false);
//         int components = 0;

//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 components++;
//                 dfs(i, adj, visited);
//             }
//         }

//         return components - 1;
//     }
// };

// TC: O(V + E)
// building the adj list takes O(V + E)
// DFS visits every node once and traverse ever undirected edge twice O(V + E)

// SC: O(V + E)
// adj list takes O(V + E)
// visited arr takes O(V)

//bfs
class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

        }

        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                bfs(i, adj, visited);
            }
        }

        return components - 1;
    }
};

// TC: O(V + E)
// Building the adj list takes O(V + E)
// Each node is enqueued and dequeued once and each edge is inspected twice taking O(V + E)

// SC: O(V + E)
// the adj list takes O(V + E) space 
// visited array takes O(V) queue holds atmost O(V) nodes in worst case 

