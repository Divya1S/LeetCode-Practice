// class Solution {
// public:
//     int minChanges(string s) {
//         int n = s.length();
//         //find the total len of string and stores it in var n 

//         char ch = s[0];
//         //looks at very first character of string and saves it in var called ch 
//         //we will use this to keep track of current block of identical character 
//         int count = 0;
//         //sets up a counter to track how many times in a row we have seen the same character 

//         int changes = 0;
//         //sets up a counter for total number of character changes we are forced to make 

//         for (int i = 0; i < n; i++) {
//             //loop that will look at every single character in the string one by one 
//             if (s[i] == ch) {
//                 count++;
//                 continue;
//             }
//             //checks if the current character is same as our tracked character 
//             //if it is we increase our count by 1 as identical thing recognized and use continue to skip the rest of teh loop and move directly to the next character 

//             //current character is not equal to ch 
//             if (count % 2 == 0) {
//                 count = 1;
//             } 
//             //If we reach this line the curr character is different from the tracked character we check if count of prev identical char is an even number 
//             //if it is even that block is perfectly fine. 
//             // we just start our new block with the new character setting new count to 1
//             else { //odd num of characters 
//                 changes += 1;
//                 count = 0;
//             }
//             //if the prev block had odd num of characters we have a problem we are forced to change teh the curr character to match prev block 
//             // we add 1 to changes and reset count to 0 bcoz we have fixed the block and will start fresh on the next loop 

//             ch = s[i]; //updates our tracked chracter ch to current character so the next loop iteration can compare against it 
//         }

//         return changes;
//     }
// };

// TC: O(n)
// SC: O(1)

class Solution {
public: 
    int minChanges(string s) {
        int changes = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i+1]) changes++;
        }
        return changes;
    }
};

//Bcoz teh problem requires the string of even len of idential characgters 
// if pair like s[0] and s[1] has diff char you are forced to make exactly one change to make them match. 
// By jumping through the string 2 characters at a time (i += 2) and counting how many pairs don't match you get the min number of changes needed for the entire string 

// TC: O(n)

// SC: O(1)