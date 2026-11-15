//When you must build the Adjacency List 
// Use this when the problem provides the number of vertices (V) and a list of edges
// You must construct the adj array before traversing it recursively 

class Solution {
public:
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result) {
        //mark the curr node as visited and add to result 
        visited[u] = true;
        result.push_back(u);

        //Recursively visit all unvisited neighbors 
        for (int &v : adj[u]) {
            if(!visited[v]) {
                dfs(adj, v, visited, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);

        //we must build the adjacency list from the raw edges 
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<bool> visited(V, false);
        vector<int> result;

        //start DFS from node 0
        dfs(adj, 0, visited, result);

        return result;
    }
};

//When you do not need to build the Adjacency List 
// Use this when the platform already passes vector<vector<int>> adj directly into your main function 
// You skip the edge loop and pass it straight into the recursive helper 

class Solution {
public:
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result) {
        //mark the curr node as visited and add to result 
        visited[u] = true;
        result.push_back(u);

        //Recursively visit all unvisited neighbors 
        for (int &v : adj[u]) {
            if(!visited[v]) {
                dfs(adj, v, visited, result);
            }
        }
    }

    vector<int> dfsOfGraph(vector<vector<int>> &adj) {
        int V = adj.size();

        //we do not build the list because adj is already provided

        vector<bool> visited(V, false);
        vector<int> result;

        //start DFS from node 0
        dfs(adj, 0, visited, result);

        return result;
    }
};