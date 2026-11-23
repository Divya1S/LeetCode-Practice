// Brute Force: TLE
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {

//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == target)
//                 return i;
//         }

//         return -1;
//     }
// };

// TC: O(n)
// SC: O(1)

// Why no acceptable? Because the problem explicitly requires: O(logn)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            //if the array contains duplicate 
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

// TC: O(logn)
// each iteration eliminates half of the remaining search space 
// Note: If you add the duplicate handling fix worst case time can degrade to O(n) {when all elements are identical}

// SC: O(1)
