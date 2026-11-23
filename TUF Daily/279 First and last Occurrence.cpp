//Brute Force 
// class Solution{
// public:
//     vector<int> searchRange(vector<int> &nums, int target) {
//         int n = nums.size();
//         int first = -1;
//         int last = -1;

//         for (int i = 0; i < n; i++) {
//             if(nums[i] == target) {
//                 if (first == -1) {
//                     first = i;
//                 }

//                 last = i;
//             }
//         }

//         return {first, last};
//     }
// };

// TC: O(n) 
// for loop iterates through every element in nums from 0 to n - 1 exactly once 
// SC: O(1)

//Optimal Solution (using lower bound and upper bound)
// class Solution{
// public:
//     int lowerBound(vector<int>& arr, int n, int x) {
//         int low = 0, high = n - 1;
//         int ans = n;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             //maybe an answer 
//             if (arr[mid] >= x) {
//                 ans = mid;
//                 //look for more small index on left 
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1; //look for right 
//             }
//         }

//         return ans;
//     }

//     int upperBound(vector<int>& arr, int n, int x) {
//         int low = 0, high = n - 1;
//         int ans = n;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             //maybe an answer 
//             if (arr[mid] > x) {
//                 ans = mid;
//                 //look for more small index on left 
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1; //look for right 
//             }
//         }

//         return ans;
//     }
//     vector<int> searchRange(vector<int> &nums, int target) {
//         int n = nums.size();
//         int lb = lowerBound(nums, n, target);
//         if (lb == n || nums[lb] != target) {
//             return {-1, -1};
//         }

//         return {lb, upperBound(nums, n, target) - 1};
//     }
// };

// TC: O(logn)
//lower bound: O(logn)
//upper bound: O(logn)
// two binary searches take 2 * O(logn) = O(logn) time 
// SC: O(1)

//Optimal Solution (using pure binary search)
class Solution{
public:
    int firstOccurrence(vector<int>& arr, int n, int k) {
        int low = 0, high = n - 1;
        int first = - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == k) {
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return first;
    }
    int lastOccurrence(vector<int>& arr, int n, int k) {
        int low = 0, high = n - 1;
        int last = - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == k) {
                last = mid;
                low = mid + 1;
            }
            else if (arr[mid] < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        int first = firstOccurrence(nums, n, target);
        if (first == -1) {
            return {-1, -1};
        }
        int last = lastOccurrence(nums, n, target);
        return {first, last};
    }
};

// TC: O(logn)
// both firstOccurrence and lastOccurrence halve the search space on every iteration O(logn)

// SC: O(1)