// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         // Find the maximum pile size to set our upper bound
//         int maxVal = *max_element(piles.begin(), piles.end());
        
//         // Check every speed from 1 to maxVal
//         for (int speed = 1; speed <= maxVal; speed++) {
//             long long totalHours = 0; 
            
//             // Calculate total hours required at the current speed
//             for (int pile : piles) {
//                 // Integer math equivalent to ceil(double(pile) / speed)
//                 totalHours += (pile + speed - 1) / speed; 
//             }
            
//             // The first speed that finishes within 'h' hours is our minimum
//             if (totalHours <= h) {
//                 return speed;
//             }
//         }
        
//         return maxVal;
//     }
// };
// The above solution gives TLE

//Binary Search
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        
        // Binary search on the possible speeds
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHours = 0;
            
            // Calculate total hours required at the 'mid' speed
            for (int pile : piles) {
                totalHours += (pile + mid - 1) / mid; //ceil(a / b) = (a + b - 1) / b;
                //very common trick in competitive programming for calculating ceiling division with positive integers
            }
            
            // If Koko can finish in time, record it and try a slower speed
            if (totalHours <= h) {
                ans = mid;
                high = mid - 1; 
            } 
            // If she can't finish in time, she must eat faster
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

// TC: O(nlogm)
// finding the upper bound: *max_element() scans the entire array once taking O(n) time 
// binary search loop: seach space is [1, m] so the while loop runs atmost [logm] times 
// inner for loop: takes O(n) time 

// SC: O(1)