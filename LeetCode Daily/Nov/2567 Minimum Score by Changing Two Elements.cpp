class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        //Option one is to make two smallest similar 
        int option1 = nums[n-1] - nums[2];

        //Option two is to make two largest similar 
        int option2 = nums[n-3] - nums[0];

        //Option three is one largest and one smallest 
        int option3 = nums[n-2] - nums[1];

        return min({option1, option2, option3});
    }
};

// TC: O(nlogn) as we are sorting the array

//SC: O(1)