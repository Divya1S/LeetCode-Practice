class Solution {
private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);

        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int u = 0; u < V; u++) {
            if (indegree[u] == 0) {
                q.push(u);
            }
        }

        vector<int> topo;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return topo;
    }
public:
	string findOrder(string dict[], int N, int K) {
		vector<int> adj[K];

        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int len = min(s1.size(), s2.size());

            //edge case if s1 is longer than s2 and s2 is a prefix of s1 the dictionary is invalid 
            if(s1.size() > s2.size() && s1.substr(0, len) == s2.substr(0, len)) {
                return "";
            }

            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        //call topoSort and convert the result into a string 
        vector<int> topo = topoSort(K, adj);

        //If the graph has a cycle (invalid dictionary) topo sort won't include all nodes 
        if (topo.size() != K) {
            return "";
        }

        string ans = "";
        for (auto ch : topo) {
            ans += char(ch + 'a');
        }

        return ans;

	}
};

TC: O(N * L + K)
building the graph: iterate through N - 1 pairs of adjacent words.
In the worst case you compare characters up to len of shorter word 
If L is the max len of a string in the dictionary this takes O(N * L) time 
Topological Sort: Kahn's algo visites every vertex(character) and every edge once 
The number of vertices is K Since we only add a max of one edge per pair of words the number of edges is atmost N - 1 Thus sorting takes O(K + N) time 

SC: O(K + N)
Adj List: create an arr of K vectors it stores atmost N - 1 directed edges takes O(K + N) space 
Indegree Array and Queue: takes O(K) space 