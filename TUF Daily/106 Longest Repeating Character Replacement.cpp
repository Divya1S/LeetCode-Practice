//Brute Force 
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int maxLen = 0;
//         int n = s.length();
        
//         for (int i = 0; i < n; i++) {
//             int hash[26] = {0}; 
//             int maxF = 0;
            
//             for (int j = i; j < n; j++) {
//                 hash[s[j] - 'A']++;
//                 maxF = max(maxF, hash[s[j] - 'A']); 
                
//                 int changes = (j - i + 1) - maxF;
                
//                 if (changes <= k) {
//                     maxLen = max(maxLen, j - i + 1);
//                 } else {
//                     break;
//                 }
//             }
//         }
//         return maxLen;
//     }
// };

// TC: O(N^2)
// SC: O(N)

//Better Solution
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int lptr = 0, rptr = 0, maxLen = 0, maxF = 0;
//         int hash[26] = {0};

//         while(rptr < s.size()) {
//             //add the curr char to our frequency hash 
//             hash[s[rptr] - 'A']++;
//             maxF = max(maxF, hash[s[rptr] - 'A']);

//             //if the chracters we need to replace exceeds k, shirnk the window 
//             //window size is (rptr - lptr + 1)
//             while ((rptr - lptr + 1) - maxF > k) {
//                 hash[s[lptr] - 'A']--;

//                 //recalculate max freq in the current window 
//                 maxF = 0;
//                 for (int i = 0; i < 26; i++) {
//                     maxF = max(maxF, hash[i]);
//                 }
//                 lptr++;
//             }

//             //if the current window is valid 
//             if ((rptr - lptr + 1) - maxF <= k) {
//                 maxLen = max(maxLen, rptr - lptr + 1);
//             }

//             rptr++;
//         }

//         return maxLen;
//     }
// };

// TC: O(N)
// inner while loop takes O(N) and a for loop inside the inner while loop runs 26 times and rptr and lptr traverse the string s exactly once N (len of string)
// SC: O(26) ~ O(1)

//Optimal Solution 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int lptr = 0, rptr = 0, maxLen = 0, maxF = 0;
        int hash[26] = {0};

        while(rptr < s.size()) {
            //add curr char to freq hash
            hash[s[rptr] - 'A']++;

            //update the historical max freq 
            maxF = max(maxF, hash[s[rptr] - 'A']);

            //If the characters we need to replace exceeds k, slide the window 
            if ((rptr - lptr + 1) - maxF > k) {
                hash[s[lptr] - 'A']--;
                lptr++; //we do not need to recalculate maxF here 
            }

            //Update maxLen (the window is either valid or we just slid it) 
            maxLen = max(maxLen, rptr - lptr + 1);

            rptr++;
        }

        return maxLen;
    }
};

// TC: O(N)
// SC: O(1)