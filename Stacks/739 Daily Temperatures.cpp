//Brute Force: TLE
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int> answer(n, 0); //Initialize with 0 as required 

//         for (int i = 0; i < n; i++) {
//             //Look ahead to future days 
//             for (int j = i + 1; j < n; j++) {
//                 if (temperatures[j] > temperatures[i]) {
//                     answer[i] = j - i; //Calculate the distance in days 
//                     break; //Stop looking once we find a warmer day 
//                 }
//             }
//         }

//         return answer;
//     }
// };

// TC: O(N^2)
// worst case occurs when the temps are strictly decreasing or are all equal 
// eg: [100, 99, 98, ....] 
// break statement is never triggered 
// so far every elememt i the inner loop scans all remaining elements N - i - 1
// best case: occurs when the temperatures are strictly increasing 
// eg: [70, 71, 72, 73....] 

// SC: o(1) aux/ O(n) total 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; //This stack will store Indices not temperature 

        for (int i = 0; i < n; i++) {
            int currentTemp = temperatures[i];

            //While stack is not empty AND current day is warmer than the day at the top of the stack
            while (!st.empty() && currentTemp > temperatures[st.top()]) {
                int previousDayIndex = st.top();
                st.pop();

                //Calculate how many days we had to wait 
                answer[previousDayIndex] = i - previousDayIndex;
            }

            //Push the current days index into the stack
            st.push(i);
        }

        return answer;
    }
};

// TC: O(N)
// even though there is a while loop nested inside a for loop the algo runs in linear time 
// each idx from 0 to n-1 is pushed onto the stack exactly once and popped from the stack atmost once 
// across the entire execution there are at most N pushes and N pops (2N total stack operations)

// SC: O(N)
// worst case when temps are strictly decreasing or are equal the every index gets pushed onto st. 
// Best case: O(1) temp are strictly increasing 
// Total space: for O(N) answer vector