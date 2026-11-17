//DFS old way
class Solution {
public:
    bool isCycleDFS(vector<int> adj[], int u, vector<bool>& visited, int parent) {
        visited[u] = true;

        for (int &v : adj[u]) {
            if (v == parent) continue;

            if(visited[v]) 
                return true;

            if(isCycleDFS(adj, v, visited, u)) {
                return true;
            }
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, -1)) {
                return true;
            }
        }

        return false;
    }
}

//My way of writing it in modern manner 
//DFS
class Solution {
public:
    // Helper function to detect a cycle using DFS in an undirected graph
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, int parent) {
        // Mark the current node as visited
        visited[u] = true;

        // Traverse all adjacent nodes
        for (int &v : adj[u]) {
            // Ignore the edge that goes right back to the parent we just came from
            if (v == parent) {
                continue;
            }

            // If we hit a visited node that IS NOT the parent, we found a cycle
            if (visited[v]) {
                return true;
            }

            // Recursively visit the neighbor, passing 'u' as the new parent
            if (isCycleDFS(adj, v, visited, u)) {
                return true;
            }
        }

        return false;
    }
    
    // Main function: Input IS the adjacency list
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);

        // Run DFS for every node to handle disconnected graph components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // Pass -1 as the initial parent for the starting node of a component
                if (isCycleDFS(adj, i, visited, -1)) {
                    return true;
                }
            }
        }

        return false;
    }
};

//BFS old way
class Solution {
public:
    bool isCycleBFS(vector<int> adj[], int u, vector<bool>& visited) {
        queue<pair<int, int>> que;

        que.push({u, -1});
        visited[u] = true;

        while(!q.empty()) {
            pair<int, int> P = que.front();
            que.pop();

            int source = P.first;
            int parent = P.second;

            for (int &v : adj[source]) {
                if (visited[v] == false) {
                    visited[v] = true;
                    que.push({v, source});
                } else if (v != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if(!visited[i] && isCycleBFS(adj, i, visited)) {
                return true;
            }
        }

        return false;
    }
}

//BFS my way
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Helper function to detect a cycle using BFS in an undirected graph
    bool isCycleBFS(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        // Queue stores pairs of {current_node, parent_node}
        queue<pair<int, int>> que;

        que.push({u, -1});
        visited[u] = true;

        while (!que.empty()) {
            pair<int, int> P = que.front();
            que.pop();

            int source = P.first;
            int parent = P.second;

            // Traverse all adjacent nodes
            for (int &v : adj[source]) {
                if (!visited[v]) {
                    visited[v] = true;
                    que.push({v, source});
                } 
                // If we hit a visited node that IS NOT the parent, we found a cycle
                else if (v != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    
    // Main function: Input IS the adjacency list
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);

        // Run BFS for every node to handle disconnected graph components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCycleBFS(adj, i, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

TC: O(V + E) 
V is the number of vertices and E is the number of edges 
In worst case every vertex is pushed and popped from the queue exactly once 
and we iterate through all edges once (evaluating both ends of an undirected graph)

SC: O(V)
visited arr takes O(V) space 
and the queue can hold atmost O(V) elements 

