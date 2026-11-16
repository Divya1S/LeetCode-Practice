3875. Construct Uniform Parity Array I

// How parity in Math work:
// Even - Odd = Odd 
// Odd - Odd = Even 
// Even stays Even 
// Odd stays Odd 

// Brute Force:
// For this we can directly simulate the rules. 
// We will check if it is possible to make all elements even and then check if its possible to make all elements odd.
// To make everything even:
// If a num is already even we keep it 
// If it is odd we must subtract another odd number from it to make it even.
// So we scan the array to find another odd number.

// To make everything odd:
// If a number is already odd we keep it.
// If it is even we must subtract an odd number from it to make it odd.
// So we scan the array to find an Odd number 

// If either of these two checks succeeds we return true.

// class Solution {
// public:
//     bool uniformArray(vector<int>& nums1) {
//         int n = nums1.size();
//         bool canMakeAllEven = true;
//         bool canMakeAllOdd = true;

//         //Target 1: Try to make every element EVEN 
//         for (int i = 0; i < n; i++) {
//             if (nums1[i] % 2 != 0) { //If it is odd we need another odd to subtract
//                 bool foundOtherOdd = false;
//                 for (int j = 0; j < n; j++) {
//                     if (i != j && nums1[j] % 2 != 0) {
//                         foundOtherOdd = true;
//                         break;
//                     }
//                 }
//                 if(!foundOtherOdd) {
//                     canMakeAllEven = false;
//                     break;
//                 }
//             }
//         }
//         //Target 2: Try to make every element ODD
//         for (int i = 0; i < n; i++) {
//             if (nums1[i] % 2 == 0) { //If it is even we need another odd to subtract
//                 bool foundOdd = false;
//                 for (int j = 0; j < n; j++) {
//                     if (i != j && nums1[j] % 2 != 0) {
//                         foundOdd = true;
//                         break;
//                     }
//                 }
//                 if(!foundOdd) {
//                     canMakeAllOdd = false;
//                     break;
//                 }
//             }
//         }

//         //If we can achieve either configuration return true
//         return canMakeAllEven || canMakeAllOdd;
//     }
// };

// TC: O(N^2)
// Coz for every element we potentially loop through the array again to find a counterpart.

// SC: O(1)

// Optimal Solution:
// It is always mathematically possible.
// Let's look at the number of Odd integers in the array:

// Zero Odd Numbers: Every number is already even. We can just keep all of them. (Successfully made everything EVEN).

// Exactly One Odd Number: We can't make everything even, BUT we can easily make everything ODD! We keep the single odd number as is. For all the other even numbers, we subtract that one odd number (Even - Odd = Odd). (Successfully made everything ODD).

// Two or More Odd Numbers: We can easily make everything EVEN, because every single odd number has another odd number it can subtract to become even (Odd - Odd = Even). (Successfully made everything EVEN).

// Because one of these 3 conditions will always be met no matter what the input array looks like, the answer is unconditionally true.

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // It is mathematically always possible to form a uniform parity array
        return true;
    }
};

TC: O(1)
SC: O(1)