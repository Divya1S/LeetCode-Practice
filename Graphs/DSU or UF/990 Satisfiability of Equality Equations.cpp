//using DSU
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    //Path Compression
    int find(int i) {

        if (i == parent[i]) {
            return i;
        }

        return parent[i] = find(parent[i]); //path compression
    }

    //Union by Rank
    void unionSets(int x, int y) {

        int x_parent = find(x);

        int y_parent = find(y);

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

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26); //lowercase english letters a-z count = 26
        rank.resize(26, 0);

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        //first doing union of equal characters
        for (string&s : equations) {
            if (s[1] == '=') { //"a" == "b"
                // unionSets(s[0] - '0', s[3] - '0'); //we are using lowercase english letters (a to z) and then we try subtracting character '0' instead of 'a' 
                //In ASCII 'a' is 97 and '0' is 48
                //Doing 'a' - '0' gives 49 which tries to access index 49 in our above defined parent and rank arrays but they are only sized to 26
                //Thus we need to change '0' with 'a'
                unionSets(s[0] - 'a', s[3] - 'a');
            }
        }

        //find != cases and check validity
        for (string&s : equations) {
            if (s[1] == '!') { //"a" != "b"
                char first = s[0]; //a
                char second = s[3]; //b

                // int parent_first = find(first - '0');
                // int parent_second = find(second - '0');
                int parent_first = find(first - 'a');
                int parent_second = find(second - 'a');

                if (parent_first == parent_second) {
                    return false;
                }
            }
        }

        return true;
    }
};

// TC: O(N)
// N is the num of strings in the equations arr 
// creating and populating parent and rank arrays takes O(1) time as their size is strictly bounded by 26
// we iterate through the eqn arr twice once for == and once for != which takes O(N) time 
// Union-Find Operations: O(alpha(V)) since the number of variables V is fixed at max of 26 these operations take const O(1) time 

// SC: O(1)
// rank and parent arr but 26 only