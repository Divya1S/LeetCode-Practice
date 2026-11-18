//Brute Force Solution TLE
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
        
//         int n = nums.size();
//         set<vector<int>> set;

//         for(int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     if (nums[i] + nums[j] + nums[k] == 0) {
//                         vector<int> temp = {nums[i], nums[j], nums[k]};
//                         sort(temp.begin(), temp.end());
//                         set.insert(temp);
//                     }
//                 }
//             }
//         }

//         vector<vector<int>> ans(set.begin(), set.end());
//         return ans;
//     }
// };

// TC: O(n^3logk)
// we have 3 nested loops which takes O(n^3)
// inside the innermost loop sorting a 3 element array takes O(1) time but inserting into a set takes O(logk) time where k is the number of unique triplets currently in the set 

// SC: O(k)
// k is the number of unique valid triplets
// set requires extra memory to store these unique triplets before they are copied into the final answer vector 

//Better Solution TLE
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
        
//         int n = nums.size();
//         set<vector<int>> st;

//         for(int i = 0; i < n; i++) {
//             set<int> hashset;
//             for (int j = i + 1; j < n; j++) {
//                 int third = -(nums[i] + nums[j]);

//                 if(hashset.find(third) != hashset.end()) {
//                     vector<int> temp = {nums[i], nums[j], third};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 } 
//                 hashset.insert(nums[j]);
//             }
//         }

//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };

// TC: O(N^2logN)
// outer loop N times inner loop N times O(N^2)
// set bcoz hashset is a set and not a hashmap hashset.find() and hashset.insert() both take O(logN) time 
// when triplet is found inserting it in anothe rsert takes O(logK) time 

// SC: O(N + K)
// hashset storage: O(N)
// Unique Triplets Storage: O(K)

//Optimal Solution 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};

// TC: O(N^2)
// The sort takes O(NlogN) time 
// Two Pointers: The outer loop runs N times 
// inside the outer loop the while(j < k) loop traverses the remaining elements of the arr exactly once which takes O(N) time 

// SC: O(1) or O(K)
// ans vector takes O(K) space K is number of valid unique triplets 
