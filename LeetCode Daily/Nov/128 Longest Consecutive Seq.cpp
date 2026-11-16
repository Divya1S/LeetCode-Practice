//Brute Force - TLE
//Linear scan for every sequential element
// class Solution {
// private:
//     //Helper function to perform a linear search 
//     bool linear_search(vector<int>& arr, int num) {
//         for (int i = 0; i < arr.size(); i++) {
//             if (arr[i] == num) {
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();

//         if (n == 0) return 0;

//         int longest = 1;

//         for (int i = 0; i < n; i++) {
//             int x = nums[i];
//             int count = 1;

//             //Increment x and search for the next consective number 
//             while (linear_search(nums, x+1) == true) {
//                 x = x + 1;
//                 count += 1;
//             }

//             //Update the max length found so far 
//             if (count > longest) {
//                 longest = count;
//             }
//         }

//         return longest;
//     }
// };

// TC: O(N^3)
// The outer loop runs N times 
// In worst case where the arr consists of single long consective seq the while loop runs up to N times 
// For every execution of the while loop the linear_search function iterates through the arr O(N) time
// Worst case time complexity is O(N^3) TLE

// SC: O(1)

//Better Solution using sorting
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;

//         //sort the array 
//         sort(nums.begin(), nums.end());

//         int longest = 1;
//         int countCurrent = 0;
//         int lastSmaller = INT_MIN;

//         //Iterate to find the longest sequence 
//         for (int i = 0; i < n; i++) {
//             if(nums[i] - 1 == lastSmaller) {
//                 //The current number is exactly one greater than the previous 
//                 countCurrent++;
//                 lastSmaller = nums[i];
//             }else if (nums[i] != lastSmaller) {
//                 //The current number is not a duplicate and breaks the sequence 
//                 countCurrent = 1;
//                 lastSmaller = nums[i];
//             }

//             //Update the longest sequence found so far 
//             longest = max(longest, countCurrent);
//         }

//         return longest;
//     }
// };

// TC: O(NlogN)
// Sorting the array takes O(NlogN) time 
// For the single for loop iterates the array once which takes O(N)
// overall time complexity is dominated by the sorting step O(NlogN)

// SC: O(logN)
// Modifying the arr in-place via sorted requires O(logN) stack space 

//Optimal Approach using Set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        int longest = 1;

        unordered_set<int> set;

        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
        }

        for (auto s : set) {
            if (set.find(s - 1) == set.end()) {
                int count = 1;
                int x = s;
                while(set.find(x+1) != set.end()) {
                    x = x + 1;
                    count++;
                }
                longest = max(longest, count); 
            }
        }

        return longest;
    }
};

// TC: O(N) avg case 
// build the set: for the first for loop iterates N times inserting each element into the unordered_set
// hash set insertion takes O(1) avg time making this setp O(N)
// Finding the sequences: the second loop iterates through the set although there is a while loop inside the for loop it only executes if the set.find == set.end() meaning it is the absolute starting number of sequence 
// bcoz of this check the while loop only moves forward through a sequence once across the entire execution of program the inner while will run atmost N times 
// in extreme rare event of severe hash collisions operations can degrade to O(N)
// SC: O(N) for unordered set 