// Topological Sort 
//DFS

class Solution {
public: 
    void DFS(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;

        //pehele mere ('u' ke node ke) bachho ko daalo
        for (int &v : adj[u]) {
            if (!visited[v]) {
                DFS(adj, v, visited, st);
            }
        }

        //abb mujhe dallo stack me
        st.push(u);
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(adj, i, visited, st);
            }
        }

        vector<int> result;

        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

//New way 
//DFS
#include <vector>
#include <stack>

using namespace std;

class Solution {
public: 
    // Helper function to perform DFS and populate the stack
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;

        // First, recursively visit all the children (dependents) of node 'u'
        for (int &v : adj[u]) {
            if (!visited[v]) {
                DFS(adj, v, visited, st);
            }
        }

        // Now that all children are processed, push the current node 'u' into the stack
        st.push(u);
    }

    // Main function: Input IS the adjacency list
    vector<int> topoSort(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        stack<int> st;

        // Run DFS for every node to handle disconnected graph components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(adj, i, visited, st);
            }
        }

        vector<int> result;

        // Pop elements from the stack to get the topologically sorted order
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

TC: O(V + E)
where V is the num of vertices and E is the number of edges 
SC: O(V)
the visited arr stack and result arr all require about O(V) space only