//DSU
// class Solution {
// public:
//     vector<int> parent;
//     vector<int> rank;

//     int find(int i) {
//         if (i == parent[i]) {
//             return i;
//         }

//         return parent[i] = find(parent[i]);
//     }

//     void unionSets(int x, int y) {
//         int x_parent = find(x);
//         int y_parent = find(y);

//         if (x_parent == y_parent) {
//             return;
//         }

//         if (rank[x_parent] > rank[y_parent]) {
//             parent[y_parent] = x_parent;
//         }
//         else if(rank[y_parent] > rank[x_parent]) {
//             parent[x_parent] = y_parent;
//         }
//         else {
//             parent[x_parent] = y_parent;
//             rank[y_parent]++;
//         }
//     }

//     long long countPairs(int n, vector<vector<int>>& edges) {
//         parent.assign(n, 0);
//         rank.assign(n, 0);
        
//         //initially every node is its own isolated component
//         for (int i = 0; i < n; i++) {
//             parent[i] = i;
//         }
        
//         //group connected nodes into the same component using the given edges
//         for (auto &vec : edges) {
//             int u = vec[0];
//             int v = vec[1];

//             unionSets(u, v);
//         }

//         //count the size of each connected component 
//         //key = parent of the component and value = number of nodes in that component(size)
//         unordered_map<int, int> mp;
//         for (int i = 0; i < n; i++) {
//             int root = find(i);

//             mp[root]++;

//         }

//         //calculate total unreachable pairs without double - counting
//         long long result = 0;
//         long long remainingNodes = n;

//         for (auto &it : mp) {
//             long long size = it.second;

//             //every node in the current component can pair with all nodes in the remaining components
//             result += (size) * (remainingNodes - size);

//             //remove current components nodes so their pairs are not counted again 
//             remainingNodes -= size;
//         }

//         return result;
//     }
// };

// n = num of nodes E = num of edges alpha(n) is Inverse Ackermann function 
// TC: O(n + E * alpha(n)) effectively O(n + E)
// assigning parent and rank vectors takes O(n)
// union operations: O(E * alpha(n)) amortized time 
// counting components size find: takes O(n * alpha(n) avg time
// iterating over the map takes: O(n)
 
// SC: O(n)
// parent and rank vec: O(n)
// unordered_map: O(n) 
// recursion stack: O(1) due to path compression and union by rank 

//dfs
// class Solution {
// public: 
//     void dfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited, long long &Size) {
//         visited[u] = true;
//         Size++;

//         for (int &v : adj[u]) {
//             if (!visited[v]) {
//                 dfs(v, adj, visited, Size);
//             }
//         }
//     }
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>> adj;
//         for (auto &vec : edges) {
//             adj[vec[0]].push_back(vec[1]);
//             adj[vec[1]].push_back(vec[0]);
//         }

//         vector<bool> visited(n, false);
//         long long remainingNodes = n;
//         long long result = 0;

//         for(int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 long long Size = 0;
//                 dfs(i, adj, visited, Size);

//                 result += (Size) * (remainingNodes - Size);

//                 remainingNodes -= Size;
//             }
//         }

//         return result;
//     }
// };

// TC: O(n + E)
// building adjacency list through edges and inserting adj takes O(E) time 
// DFS traversal: Each of n nodes is visited once and each undirected edge is checked twice 
// O(n + E)

// SC: O(n + E)
// adj stores 2E edge entires across n keys taking O(n + E)
// visited arr takes O(n)
// recursion stack in worst case takes O(n)

//bfs
class Solution {
public: 
    void bfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited, long long &Size) {
        
        queue<int> q;
        q.push(u);

        visited[u] = true;
        Size++;

        while(!q.empty()) {
            int x = q.front();
            q.pop();

            for (int &v : adj[x]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    Size++;
                }
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto &vec : edges) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        vector<bool> visited(n, false);
        long long remainingNodes = n;
        long long result = 0;

        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long Size = 0;
                bfs(i, adj, visited, Size);

                result += (Size) * (remainingNodes - Size);

                remainingNodes -= Size;
            }
        }

        return result;
    }
};

// TC: O(n + E)
// SC: O(n + E)