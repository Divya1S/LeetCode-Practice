//BFS 
//Directed Graph -> Topological Sorting and using Kahn's Algo for BFS
class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree) {
        queue<int> que;

        vector<int> result;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                result.push_back(i);
                count++;
                que.push(i);
            }
        }

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for (int &v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    result.push_back(v);
                    count++;
                    que.push(v);
                }
            }
        }  
        if (count == n) {
            return result;
        }
        //means we had a cycle and we could not complete all courses (visit all nodes)
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        vector<int> indegree(numCourses, 0);

        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            //{a,b}
            //b --> a
            adj[b].push_back(a);

            //arrow -> a me ja raha hai
            indegree[a]++;
        }

        return topologicalSort(adj, numCourses, indegree);
    }
};

TC: O(V + E)
// Building the graph: O(V + E)
// Initializing the indegree arr of size V takes O(V) time 
// Looping through prerequisites list takes O(E) time 
// inside the loop pushing to the adjacency list and incrementing the indegree both takes O(1) time 

// Finding the 0-indegree Nodes: O(V)
// the first for loop inside the topologicalSort iterates exactly V times to find nodes with no dependencies 

// Process the queue (kahn's algo with BFS): O(V + E)
// Each vertex is pushed to and popped from the queue exactly once contributing to O(V) time 
// For each popped vertex the code iterates over all of its neighbors 
// over the entire exection of the while loop every edge is visited exactly once contributing to O(E) time 
// Total time: O(V + E) + O(V) + O(V + E) = O(V + E)

// Space Complexity: O(V + E)
// Adj List: O(V + E)
// the unordered map stores up to V keys courses and across all the vectors associated with those keys it stores a total of E elements (the edges)

// Indegree Array: O(V)
// The vector has a fixed size of numCourses 

// Queue: O(V)
// in worst case the graph with no edges all V courses have an indegree of 0 and are pushed into the queue at the same time 

// Result Array: O(V)
// output vector stores up to V elements