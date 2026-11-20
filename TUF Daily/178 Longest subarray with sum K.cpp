//Super Brute Force for positive and negative 
// class Solution{
// public:
//     int longestSubarray(vector<int> &nums, int k){
//         int n = nums.size();
//         int len = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 long long sum = 0;

//                 for (int p = i; p <= j; p++) {
//                     sum += nums[p];
//                 }

//                 if (sum == k) {
//                     len = max(len, j - i + 1);
//                 }
//             }
//         }

//         return len;
//     }
// };

// TC: O(N^3)
// SC: O(1)

//Brute Force 
// class Solution{
// public:
//     int longestSubarray(vector<int> &nums, int k){
//         int n = nums.size();
//         int len = 0;

//         for (int i = 0; i < n; i++) {
//             long long sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];

//                 if (sum == k) {
//                     len = max(len, j - i + 1);
//                 }
//             }
//         }

//         return len;
//     }
// };

// TC: O(N^2)
// SC; O(N)

//Better / Optimal approach for positive as well as negative
// class Solution{
// public:
//     int longestSubarray(vector<int> &nums, int k){
//         int n = nums.size();

//         map<long long, int> preSumMap;

//         long long sum = 0;

//         int maxLen = 0;

//         for (int i = 0; i < n; i++) {
//             sum += nums[i];
//             if (sum == k) {
//                 maxLen = max(maxLen, i+1);
//             }

//             int rem = sum - k;

//             if(preSumMap.find(rem) != preSumMap.end()) {
//                 int len = i - preSumMap[rem];
//                 maxLen = max(maxLen, len);
//             }

//             if(preSumMap.find(sum) == preSumMap.end()) {
//                 preSumMap[sum] = i;
//             }
//         }

//         return maxLen;
//     }
// };

// TC: O(NlogN)
// the loop runs N times 
// map operations find and insertion take O(logN) time 

// SC: O(N)

// Unordered_Map:
// TC: O(N) on average 
// The hash map lookups take O(1) on avg 
// but in the absolute worst-case scenario due to hash collisions it can degrade to O(N^2) but this is extremly rare 

// SC: O(N)

// Now we will see how to solve this in O(1) space if the array only had positive numbers:

//Optimal Approach: Only for positive 

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        long long sum = 0;
        int maxLen = 0;

        while (right < n) {
            // Expand the window by adding the rightmost element
            sum += nums[right];

            // If the sum exceeds k, shrink the window from the left
            while (left <= right && sum > k) {
                sum -= nums[left];
                left++;
            }

            // If the exact sum is found, update the maximum length
            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }

            // Move the right pointer forward
            right++;
        }

        return maxLen;
    }
};