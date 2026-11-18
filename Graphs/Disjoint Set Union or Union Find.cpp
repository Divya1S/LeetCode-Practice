//Disjoint Set Union or Union Find 
DSU also called Union Find is a data structure used to manage multiple seperate groups (sets).

It mainly supports 2 operations:
1. Find: Determines which set an element belongs to by finding its representative (root)
2. Union: Combines 2 different sets into one set.

The imp idea is that every set has a representative element also called its parent / root.


//It combines two given sets 
//Tells if 2 members belong to same set or not 

//Also called Union Find 

//Brute Force
//Find the representaive (root) of a set 
int find(int i, vector<int>& parent) {

    if (i == parent[i]) {
        return i;
    }

    return find(parent[i], parent);
}

//Combine two sets
void unionSets(int x, int y, vector<int>& parent) {

    int x_parent = find(x, parent);

    int y_parent = find(y, parent);

    if (x_parent != y_parent) {
        parent[x_parent] = y_parent;
    }
}

Note:
Remember to initialize the parent array before using DSU:

int n = 5;
vector<int> parent(n);

for (int i = 0; i < n; i++) {
    parent[i] = i;
}

// TC: O(n) worst case 
// find() takes O(n) in worst case 
// unionSets() takes O(n) in worst case 

// SC: O(n)
// for parent array



//Disjoint Set Union by Rank and Path Compression 
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

// TC: 
// initialization : O(n)
// Find: O(alpha(n)) amortized 
// Union: O(alpha(n)) amortized

// SC: O(n)
// coz we maintain 2 arrays
// parent array: O(n)
// rank arr: O(n) 

What is alpha(n)?
It is called the Inverse Ackermann Function 
You don't need to understand its mathematical definition 
Just remember:
        alpha(n) ~= O(1)
for all practical input sizes 
The time complexity of a sequence of operations using path compression and union by rank 
is nearly constant per operation (amortized)

The recursive find() also uses a recursion stack with depth bounded by O(logn) under union by rank



//Important notes about Path Compression 

return parent[i] = find(parent[i], parent);

What happens here?
1. Recursively find the ultimate parent (root).
2. Update the current node's parent to point directly to that root.
3. Return the root 

Remember: Path compression makes the tree flatter by connecting visited nodes directly to the root.

Important notes about Union by Rank
Our implementation has 3 conditions:

Case 1: Rank of X is greater 

if (rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = x_parent;
}

//Attach Y's root to X's root 

Case 2: Rank of Y is greater 

else if (rank[y_parent] > rank[x_parent]) {
    parent[x_parent] = y_parent;
}

//Attach X's root to Y's root 

Case 3: Both ranks are equal 

else {
    parent[x_parent] = y_parent;
    rank[y_parent] += 1;
}

//Attach one root to the other and increase the rank of the new root by one. 

Imp Notes:
1. Always compare the ranks of the ultimate parents, not the original elements.

2. Increase rank only when the 2 roots have equal rank.

3. After path compression, rank does not necessarily represent the actual height of the tree. 
It is an upper-bound measure used to maintain balance.


