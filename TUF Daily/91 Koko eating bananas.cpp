class Solution {
public:
   int minimumRateToEatBananas(vector<int> nums, int h) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = high;

        //Binary Search 
        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalHrs = 0;

            //calculating the total hrs 
            for (int i = 0; i < n; i++) {
                totalHrs += (nums[i] + mid - 1) / mid; //formula for finding ceil 
            }

            if (totalHrs <= h) {
                ans = mid;
                //but next we want to find better min 
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

// TC: O(nlogm)
// SC: O(1)