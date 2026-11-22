//Brute Force
// class Solution {
// public:
//     bool checkString(string s) {
//         int n = s.length();
//         for (int i = 0; i < n; i++) {
//             for (int j = i+1; j < n; j++) {
//                 if (s[i] == 'b' && s[j] == 'a') {
//                     return false;
//                 } 
//             }
//         }

//         return true;
//     }
// };

// TC: O(n^2) 
// where n is the len of the string 
// We are using nested loops to compare every chracter with every subsequent char 

// SC: O(1)

//Optimal Approach
class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i-1] == 'b' && s[i] == 'a') {
                return false;
            }
        }

        return true;
    }
};

// TC: O(n)
// where n is the len og the string 
// We iterate through the string eactly once 

// SC: O(1)