//Detect Cycle using DSU

//Problem Statement 
Given an undirected graph defined by V vertices and an adjacent list adj, determine 
whether the graph contains at least one cycle. 

//Approach 
The algo uses DSU data structure to connect vertices edge by edge 
If it attempts to connect 2 vertices that already shared the same parent root, this means 
cycle exists.

class Solution {
public: 
    vector<int> parent;
    vector<int> rank;

    //Path Compression
    int find(int i, vector<int>& parent) {

        if (i == parent[i]) {
            return i;
        }

        return parent[i] = find(parent[i], parent); //path compression
    }

    //Union by Rank
    void unionSets(int x, int y, vector<int>& parent, vector<int>& rank) {

        int x_parent = find(x, parent);

        int y_parent = find(y, parent);

        if (x_parent == y_parent) {
            return;
        }

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else { //rank[x_parent] == rank[y_parent]
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }

    bool detectCycle(int V, vector<int> adj[]) {
        parent.resize(V);
        rank.resize(V);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {

                //only process one direction of the undirected graph
                if(u <= v) { //using equal to only if self loops are possible in input
                    //pass the parent array to find()
                    int parent_u = find(u, parent);
                    int parent_v = find(v, parent);

                    if(parent_u == parent_v) {
                        return true; //cycle detected
                    }

                    unionSets(u, v, parent, rank);
                }
            }
        }

        return false;
    }
};


// TC: O(V + E * alpha(V))
// Initializing arrays takes O(V) time 
// We iterate through the adj list but the if (u < v) check ensures we only process each of the E unique edges exactly once.
// The find and unionSets operations take amortized O(alpha(V)) time 
// alpha = inverse Ackermann function 

// Space Complexity: O(V)
// The parent and rank arrays both require O(V) aux space.
// The recursion stack for the find function takes O(logV) and approaches O(1) due to path compression 
