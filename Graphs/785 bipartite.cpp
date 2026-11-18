//DFS
class Solution {
public:
    bool checkBipartiteDFS(vector<int> adj[], int curr, vector<int>& color, int currColor) {
        color[curr] = currColor; //we have colored the currNode 

        //now lets go to adjacent nodes 
        for (int &v : adj[curr]) {
            if(color[v] == color[curr]) {
                return false;
            }

            if (color[v] == -1) {
                int colorOfV = 1 - currColor;

                if(checkBipartiteDFS(adj, v, color, colorOfV) == false) {
                    return false;
                }
            }
        }

        return true;

    }
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1); //no node colored in the start 

        //red = 1
        //green = 0

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (checkBipartiteDFS(adj, i, color, 1) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};

// TC: O(V + E)
// V is vertices the for loop in isBipartite ensures that every vertex is checked 
// the checkBipartiteDFS func is called once for each vertex bcoz it immediately gets marked with a color 

// E is edges inside the DFS the inner loop iterates over the adj list 
// across all recursive calls every edge is visited exactly twice in an undirected graph 

// SC: O(V)
// color array takes O(V) space 
// recursion stack O(V)

//BFS leetcode
class Solution {
public:
    bool checkBipartiteBFS(vector<vector<int>>& adj, int curr, vector<int>& color, int currColor) {
        queue<int> que;
        que.push(curr);
        color[curr] = currColor;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for (int &v : adj[u]) {
                if (color[v] == color[u]) {
                    return false;
                }
                else if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<int> color(V, -1); //no one colored as of now 

        //red = 1
        //green = 0

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (checkBipartiteBFS(adj, i, color, 1) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};

// TC: O(V + E)
// SC: O(V)