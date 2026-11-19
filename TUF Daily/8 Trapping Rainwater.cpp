//Brute force
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if (n < 3) return 0;

//         int left = 0;
//         int right = n - 1;

//         int leftMax = 0;
//         int rightMax = 0;

//         int totalWater = 0;

//         while(left < right) {
//             //The water level is determined by the smaller of the two max heights 
//             if (height[left] < height[right]) {
//                 //If current height is taller than leftMax, update leftMax
//                 if (height[left] >= leftMax) {
//                     leftMax = height[left];
//                 }else {
//                     //Otherwise it can trap water 
//                     totalWater += leftMax - height[left];
//                 }
//                 left++;
//             } else {
//                 //If the current height is taller than rightMax, update rightMax
//                 if (height[right] >= rightMax) {
//                     rightMax = height[right];
//                 }else {
//                     //Otherwise it can trap water 
//                     totalWater += rightMax - height[right];
//                 }
//                 right--;
//             }
//         }
//         return totalWater;

//     }
// };

// TC: O(n) we are using a single while loop that runs as long as left < right pointers start at opposite ends of the array and move towards each other until they meet 
// SC: O(1)

//Better approach: Uses prefix and sufix maximum boundaries for each bar 
// class Solution {
// public:
//     int trap(vector<int> &height){
//         int n = height.size();
//         if (n == 0) return 0;

//         vector<int> leftHeightMax(n);
//         vector<int> rightHeightMax(n);

//         //leftHeightMax array
//         leftHeightMax[0] = height[0];
//         for (int i = 1; i < n; i++) {
//             leftHeightMax[i] = max(leftHeightMax[i-1], height[i]);
//         }

//         //rightHeightMax array
//         rightHeightMax[n-1] = height[n-1];
//         for (int i = n-2; i >= 0; i--) {
//             rightHeightMax[i] = max(rightHeightMax[i + 1], height[i]);
//         }

//         //Calculate the total water stored
//         int totalWaterStored = 0;
//         for (int i = 0; i < n; i++) {
//             totalWaterStored += min(leftHeightMax[i], rightHeightMax[i]) - height[i];
//         }

//         return totalWaterStored;
//     }
// };

// TC: O(N)
// SC: O(N)

// Better Approach with only suffix maximum boundary
// Instead of precomputing the left maximums in a separate array, you can calculate the left maximum on the fly using a single variable as you make your final pass to calculate the trapped water.
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if (n == 0) return 0;

//         vector<int> rightHeightMax(n);

//         // 1. Fill rightHeightMax array
//         rightHeightMax[n - 1] = height[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             rightHeightMax[i] = max(rightHeightMax[i + 1], height[i]);
//         }

//         int totalWaterStored = 0;
//         int currentLeftMax = 0; // Tracks the max height from the left on the fly

//         // 2. Calculate total water while updating the left max
//         for (int i = 0; i < n; i++) {
//             currentLeftMax = max(currentLeftMax, height[i]);
//             totalWaterStored += min(currentLeftMax, rightHeightMax[i]) - height[i];
//         }

//         return totalWaterStored;
//     }
// };
// TC: O(N)
// SC: O(N)

//Optimal Approach: Uses two pointer and keeps only the required boundaries 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWaterStored = 0;

        int leftPtr = 0, rightPtr = n-1;

        int leftHeightMax = 0;
        int rightHeightMax = 0;

        //two pointer approach
        while(leftPtr < rightPtr) {
            leftHeightMax = max(leftHeightMax, height[leftPtr]);
            rightHeightMax = max(rightHeightMax, height[rightPtr]);

            if(leftHeightMax < rightHeightMax) {
                totalWaterStored += leftHeightMax - height[leftPtr];
                leftPtr++;
            }
            else {
                totalWaterStored += rightHeightMax - height[rightPtr];
                rightPtr--;
            }
        }

        return totalWaterStored;
    }
};
  

// TC: O(N)
// SC: O(1)