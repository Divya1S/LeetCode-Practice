// Detect cycle in the Directed Graph using 
// DFS
// Old way

class Solution {
public:
    bool isCycleDFS(vector<int> adj[], int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u]) {
            //if not visited then we check for cycle in DFS 
            if (visited[v] == false && isCycleDFS(adj, v, visited, inRecursion)) {
                return true;
            } else if (inRecursion[v] == true) {
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);

        for (int i = 0; i< V; i++) {
            if (!visited[i] && isCycleDFS(adj, i, visited, inRecursion)) {
                return true;
            }
        }

        return false;
    }
};

//New Way
//DFS
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to detect a cycle using DFS in a directed graph
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        // Mark the current node as visited and add it to the active recursion stack
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u]) {
            // If the adjacent node is not visited, recursively check for a cycle
            if (!visited[v] && isCycleDFS(adj, v, visited, inRecursion)) {
                return true;
            } 
            // If the adjacent node is already in the recursion stack, we found a cycle
            else if (inRecursion[v]) {
                return true;
            }
        }

        // Remove the node from the recursion stack before returning
        inRecursion[u] = false;
        return false;
    }
    
    // Main function: Input IS the adjacency list
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);

        // Run DFS for every node to handle disconnected graph components
        for (int i = 0; i < V; i++) {
            if (!visited[i] && isCycleDFS(adj, i, visited, inRecursion)) {
                return true;
            }
        }

        return false;
    }
};

TC: O(V + E) 
V is the num of vertices 
E is the num of edges 
Each vertex is marked visited exactly once meaning we only process the outgoing edges of each vertex one time 

SC: O(V)
The visited and inRecursion vectors both take O(V) time 

//NEW BFS
//Here is how one can use BFS (Kahn's Algo) to detect a cycle in a directed graph 

// Kahn's Algo is traditionally used for Topological Sorting 
// It works on the principle of indegrees(the number of incoming edges to a node)
// In a Directed Acyclic Graph (DAG) there must be atleast one node with an indegree of 0
// If you repeatedly remove nodes with a 0 in-degree and update their neighbors you should eventually 
// process every node 
// If there is a cycle you will get stuck because the nodes in the cycle will never reach 
// an in-degree of 0
// We can detect this by counting how many nodes we successfully process 

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Main function: Input IS the adjacency list
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> indegree(V, 0);

        // 1. Calculate in-degrees of all vertices
        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> que;

        // 2. Push all vertices with an in-degree of 0 into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        int count = 0; // Tracks how many nodes we successfully process

        // 3. Process the queue
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            count++;

            // Decrease the in-degree of all adjacent vertices
            for (int &v : adj[u]) {
                indegree[v]--;
                
                // If the in-degree drops to 0, push it to the queue
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        // 4. If we processed all V nodes, there is NO cycle (returns false)
        // If count < V, we got stuck, meaning there IS a cycle (returns true)
        return count != V;
    }
};

// TC: O(V + E)
// SC: O(V)
