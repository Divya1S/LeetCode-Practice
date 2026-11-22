//DFS
// class Solution {
// public:
//     bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
//         visited[u] = true;
//         inRecursion[u] = true;

//         for (int &v : adj[u]) {
//             //if not visited then we check for cycle in DFS 
//             if (visited[v] == false && isCycleDFS(adj, v, visited, inRecursion)) {
//                 return true;
//             }
//             else if (inRecursion[v] == true) {
//                 return true;
//             }
//         }

//         inRecursion[u] = false;
//         return false;
//     }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int V = graph.size();
//         vector<bool> visited(V, false);
//         vector<bool> inRecursion(V, false);

//         for (int i = 0; i < V; i++) {
//             if (!visited[i]) {
//                 isCycleDFS(graph, i, visited, inRecursion);
//             }
//         }

//         vector<int> safeNodes;

//         for (int i = 0; i < V; i++) {
//             if (inRecursion[i] == false) {
//                 safeNodes.push_back(i);
//             }
//         }

//         return safeNodes;
//     }
// };

// TC: O(V + E)
// V is the num of vertices and E is the number of edges 
// The algo uses DFS 
// the visited array ensures that every vertex is visited exactly once 
// during the dfs the for (int &v : adj[u]) it processes each outgoing edge exactly once across the entire execution 
// thus the time spent traversing is directly proportional to the number of vertices and edges 

// SC: O(V)
// aux arrs: visited and inReursion each of size V takes O(V) space 
// recursion stack: in worst case scenario (a linear graph where each node points to the next like a linked list) the DFS recursion goes V levels deep before running 
// This consumes O(V) space on the call stack 

//Using BFS
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        queue<int> que;
        vector<int> indegree(V, 0);

        vector<vector<int>> adj(V);
        for (int u = 0; u < V; u++) {
            for (int &v : graph[u]) {
                adj[v].push_back(u);
                indegree[u]++;
            }
        }

        //fill que indegree with 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        //simple BFS 
        vector<bool> isSafe(V, false);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            isSafe[u] = true;

            for (int &v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (isSafe[i] == true) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

TC: O(V + E)
V is the num of nodes and E is the total number of edges 
Graph Reversal: iterating through the original graph to build the reversed adj list and calculate indegrees processes every node and every edge exactly once taking O(V + E) time 
Queue Initialization: Scanning the indegree array to find the terminal nodes (indegree of 0) takes O(V) time 
BFS/Kahn's algo: during BFS each node is pushed and popped from the queue at most once.
For each popped node its outgoing edges in the reversed graph are processed 
This means every edge is evaluated at most once this takes O(V + E) time 
Result Collection: Checking the isSafe array takes O(V) time 

SC: O(V + E)
Reversed Graph(adj): the algo creates a completely new adj list to reverse the direction of all edges. This requires O(V + E) space to store the V lists and E total connections.
Aux Arrays: indegree and isSafe arrs take O(V)space 
Queue: in worst case senario graph with no edges all nodes are pushed in the queue at once taking O(V) space 
Result Array: The safeNodes vector takes up to O(V) space 
because of the explicit creation of the reversed graph, the dominating space requirement is O(V + E) 