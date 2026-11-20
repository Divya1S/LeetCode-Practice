//Recursion with memoization
// class Solution {
// public:
//     int n;
//     vector<vector<int>> memo;

//     int findMethod(vector<int>& nums, int start, int target) {
//         int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);

//         if(j < n && nums[j] == target) {
//             return j;
//         }

//         return -1;
//     }

//     int solve(int i, int inc, vector<int>& nums) {

//         if (memo[i][inc] != -1) {
//             return memo[i][inc];
//         }

//         int currVal = nums[i] + inc;
//         int len = 1;

//         //find currVal + 1
//         int j = findMethod(nums, i+1, currVal + 1);
//         if (j != - 1) {
//             len = max(len, 1 + solve(j, 0, nums));
//         }

//         //find currVal and then increment by 1
//         j = findMethod(nums, i+1, currVal);
//         if (j != - 1) {
//             len = max(len, 1 + solve(j, 1, nums));
//         }

//         return memo[i][inc] = len;
//     }

//     int maxSelectedElements(vector<int>& nums) {
//         n = nums.size();

//         sort(nums.begin(), nums.end());

//         memo.assign(n+1, vector<int>(2, -1));

//         int result = 1;
//         for(int i = 0; i < n; i++) {
//             result = max({result, solve(i, 0, nums), solve(i, 1, nums)});
//         }

//         return result;
//     }
// };

// TC: O(nlogn)
// Sorting: The code begins by sorting the array which takes O(nlogn) time 
// Memoized DFS:
// The solve function has 2 parameters that changes i (ranging from 0 to n) and inc (which is either 0 or 1). This means there are 2n unique states, so solve will compute its logic at most O(n) times.
// Inside each unmemoized solve call you call findMethod twice 
// findMethod uses lower_bound (binary search) to find the target element which takes O(logn) time.
// Since there are O(n) states and each perform O(logn) work, the total time spent computing the DP states is O(nlogn)

// SC: O(n)
// Memoization Table: The memo matrix is initialized with dimensions (n+1)*2 which takes O(n) space 
// solve function recursion stack takes O(n) space 
// sorting takes O(logn)
// Aux space is dominated by memo table and recursion stack

//Bottom Up Approach 
class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);

        if(j < n && nums[j] == target) {
            return j;
        }

        return -1;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin(), nums.end());

        dp.assign(n+1, vector<int>(2, 0));

        int result = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int inc = 0; inc <= 1; inc++) {
                int currVal = nums[i] + inc;
                int len = 1;

                //find currVal + 1
                int j = findMethod(nums, i + 1, currVal + 1);
                if (j != -1) {
                    len = max(len, 1 + dp[j][0]);
                }

                //find currVal and then inc by 1
                j = findMethod(nums, i + 1, currVal);
                if (j != -1) {
                    len = max(len, 1 + dp[j][1]);
                }

                dp[i][inc] = len;
                result = max(result, len);
            }
        }

        return result;
    }
};

// TC: O(nlogn)
// sorting: O(nlogn)
// Iterative DP:
// we have an outer loop running n times 
// inner loop runs exactly 2 times 
// inside the loop we call findMethod twice 
// findMethod uses lower_bound to find elements in the array which takes O(logn) time 
// computing the dp table takes n * 2 * logn time ~ O(nlogn)

// SC: O(n)
// DP table O(n)
// sorting stack: O(logn)