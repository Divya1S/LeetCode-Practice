//Brute Force - TLE
// class Solution {
// public:
//     vector<int> nextLargerElement(vector<int> arr) {
//         int n = arr.size();
//         vector<int> nge(n, -1);

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (arr[j] > arr[i]) {
//                     nge[i] = arr[j];
//                     break;
//                 }
//             }
//         }

//         return nge;
//     }
// };


//TC: O(n^2)
//SC: O(n)

// Optimal solution using stack 
class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&  arr[i] >= st.top()) {
                st.pop();
            }
            
            if(!st.empty()) {
                nge[i] = st.top();
            }

            st.push(arr[i]);
        }

        return nge;
    }
};

//TC: O(2N)
//SC: O(N) + O(N) one for stack and another for vector