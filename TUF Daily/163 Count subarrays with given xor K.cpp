//Brute force solution TLE
// class Solution{
// public:
//     int subarraysWithXorK(vector<int> &nums, int k) {
//         int n = nums.size();
//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 int current_xor = 0;
//                 for (int p = i; p <= j; p++) {
//                     current_xor = current_xor ^ nums[p];
//                 }
//                 if(current_xor == k) {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };

// TC: O(N^3) because of 3 nested loops 
// SC: O(1)

//Better Approach
// class Solution{
// public:
//     int subarraysWithXorK(vector<int> &nums, int k) {
//         int n = nums.size();
//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             int current_xor = 0;
//             for (int j = i; j < n; j++) {
//                 current_xor = current_xor ^ nums[j];
                
//                 if(current_xor == k) {
//                 count++;
//                 }
//             }
//         }

//         return count;
//     }
// };
// TC: O(N^2)
// SC: O(1)

//Optimal Solution 
// class Solution{
// public:
//     int subarraysWithXorK(vector<int> &nums, int k) {
//         int xr = 0;
//         map<int, int> mpp;
//         mpp[xr]++; //{0, 1}

//         int count = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             xr = xr ^ nums[i];
//             //k
//             int x = xr ^ k;
//             count += mpp[x];
//             mpp[xr]++;
//         }

//         return count;
//     }
// };

//Optimal Way written in modern cpp format 
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int current_xor = 0;
        int count = 0;

        unordered_map<int, int> prefix_xor_counts;
        prefix_xor_counts[0] = 1; //base case: prefix XOR of 0 at the start 

        for (int i = 0; i < nums.size(); i++) {
            current_xor = current_xor ^ nums[i];

            //formula 
            int target_prefix = current_xor ^ k;

            //look up the target and check if it exists in map
            if (auto it = prefix_xor_counts.find(target_prefix); it != prefix_xor_counts.end()) {
                count += it->second;
            }

            prefix_xor_counts[current_xor]++;
        }

        return count;
    }
};

// TC: O(N) on avg 
// We iterate through the arr of size N exactly once 
// Hash table insertions and lookups in unordered_map take O(1) avg time 
// Note: In extreme worst case scenario with sever hash collision this could degrade to O(N^2)

// SC: O(N)
// in worst case every prefix XOR is completely unique meaning we will store N distinct entires inside the mao