//Sliding window
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 2; // Any subarray of length 2 is always valid
        int left = 0;
        int prod = 1;

        for (int right = 0; right < n; ++right) {
            while (gcd(prod, nums[right]) != 1) {
                prod /= nums[left];
                left++;
            }
            prod *= nums[right];
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// TC: O(NlogM)
// N = len of nums M = max(nums)
// each element is added to and removed from the window at most once 
// SC: O(1)