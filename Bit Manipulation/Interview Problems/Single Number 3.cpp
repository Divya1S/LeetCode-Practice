Find the two numbers appearing odd number of times

Problem Statement: Given an array nums of length n, every integer in the array appears twice except for two integers. Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.

For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].

Example 1:
Input:
 nums = [1, 2, 1, 3, 5, 2]
Output:
 [3, 5]
Explanation:

The integers 3 and 5 have appeared only once.

Example 2:
Input:
 nums = [-1, 0]
Output:
 [-1, 0]
Explanation:

The integers -1 and 0 have appeared only once.

Brute Force

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to get the single 
    number in the given array */
    vector<int> singleNumber(vector<int>& nums){
        
        // Array to store the answer
        vector<int> ans;
        
        /* Map to store the elements 
        and their frequencies */
        unordered_map <int, int> mpp;
        
        // Iterate on the array
        for(int i=0; i < nums.size(); i++) {
            mpp[nums[i]]++; // Update the map
        }
        
        // Iterate on the map
        for(auto it : mpp) {
            // If frequency is 1
            if(it.second == 1) {
                /* Add the element to
                the result array */
                ans.push_back(it.first);
            }
        }   
        
        // Return the result after sorting
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the single 
    number in the given array */
    vector<int> ans = sol.singleNumber(nums);
    
    cout << "The single numbers in given array are: " << ans[0] << " and " << ans[1];
    
    return 0;
}

Time Complexity: O(N), where N is the size of the array.
Traversing the array to update the Hash Map: O(N).
Traversing the map: O(N) (in the worst case).
Sorting the answer array: O(2*log(2)) ~ O(1).
Hence, the overall time complexity is O(N) + O(N) + O(1) ~ O(N).

Space Complexity: O(N), since we are using a hashmap data structure, 
and in the worst case (when all elements in the array are unique), it will store N key-value pairs.

Optimal Approach
Traverse the entire array, performing an XOR operation on all numbers. This will effectively cancel out all the numbers that appear twice, leaving us with the XOR of the two unique numbers.
Determine the rightmost set bit (bit that is 1) in the result from the first step. This set bit can be used to differentiate the two unique numbers since they must differ at this bit position.
Traverse the array again, but this time divide the numbers into two groups:
One group where the numbers have the rightmost set bit.
Another group where the numbers do not have this bit set.
Perform XOR operations while adding numbers in each group. This will cancel out the duplicate numbers, leaving only the unique numbers in each group.
Sort the two unique numbers in ascending order and return them.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to get the single 
    numbers in the given array */
    vector<int> singleNumber(vector<int>& nums){
        // Variable to store size of array
        int n = nums.size();
        
        // Variable to store XOR of all elements
        long XOR = 0;
        
        // Traverse the array
        for(int i=0; i < n; i++) {
            
            // Update the XOR
            XOR = XOR ^ nums[i];
        }
        
        /* Variable to get the rightmost 
        set bit in overall XOR */
        int rightmost = (XOR & (XOR - 1)) ^ XOR;
        
        /* Variables to stores XOR of
        elements in bucket 1 and 2 */
        int XOR1 = 0, XOR2 = 0;
        
        // Traverse the array
        for(int i=0; i < n; i++) {
            
            /* Divide the numbers among bucket 1
             and 2 based on rightmost set bit */
            if(nums[i] & rightmost) {
                XOR1 = XOR1 ^ nums[i];
            }
            else {
                XOR2 = XOR2 ^ nums[i];
            }
        }
        
        // Return the result in sorted order
        if(XOR1 < XOR2) return {XOR1, XOR2};
        return {XOR2, XOR1};
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the single 
    numbers in the given array */
    vector<int> ans = sol.singleNumber(nums);
    
    cout << "The single numbers in given array are: " << ans[0] << " and " << ans[1];
    
    return 0;
}

Time Complexity: O(N), traversing the array twice results in O(2*N) time complexity.

Space Complexity: O(1), using a couple of variables, i.e., constant space.