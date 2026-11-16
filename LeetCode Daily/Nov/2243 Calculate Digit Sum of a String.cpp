//Brute Force Approach
// The most straightforward way to solve this is to follow the problem description exactly using string slicing (substr) 
// We slice the string into chuncks of size k iterate through each chuck to find the sum and concatenate the result 
// class Solution {
// public:
//     string digitSum(string s, int k) {
//         //Continue rounds until the string length is less than or equal to k 
//         while(s.length() > k) {
//             string next_s = "";

//             //Divide into groups of size k 
//             for (int i = 0; i < s.length(); i += k) {
//                 string group = s.substr(i, k);

//                 //Calculate the digit sum of the group
//                 int sum = 0;
//                 for (char c : group) {
//                     sum += c - '0';
//                 }

//                 //merge back together 
//                 next_s += to_string(sum);
//             }
//             s = next_s;
//         }

//         return s;
//     }
// };

// TC: O(N * R) ~ O(N)
// N is the length of the string 
// R is the number of rounds 
// in worst case k = 2 all 9s the string length shrinks drastically after a couple of rounds 
// The max num of rounds for N = 100 is extremely small (less than 10) 
// Overall time complexity is O(N)

// SC: O(N)
// because s.substr() creates a new string for every group and next_s stores the new string of up to length N 

//Optimal Approach
//We can optimize the memory allocation and avoid the overhead of creating intermediate substring copies 
//Instead of slicing we can keep a running sum and append it to our new string eactly when we hit the k-th character of a group or end of the string 
//we can also use move and reserve to prevent unnecessary memory allocations

class Solution {
public:
    string digitSum(string s, int k) {
        //Continue rounds until the string length is less than or equal to k 
        while(s.length() > k) {
            string next_s;
            //Reserve memory to avoid multiple reallocations during concatenation 
            next_s.reserve(s.length());

            int curr_sum = 0;
            for (int i = 0; i < s.length(); i++) {
                curr_sum += s[i] - '0';

                //if we reach the end of the group of size k OR the end of the string 
                if ((i + 1) % k == 0 || i == s.length() - 1) {
                    next_s += to_string(curr_sum);
                    curr_sum = 0; //reset for the next group
                }
            }

            //we use move to transfer ownership without copying the string characters 
            s = move(next_s);
        }

        return s;
    }
};

// TC: O(N)
// N is the length of string 
// We iterate through the string a few times and the len drops exponentially in most cases 
// Avoid substr makes the constant factors much smaller resulting in faster exection 

// SC: O(N)
// to store the next_s string during construction 
// However .reserve() and move() eliminates the hidden memory overhead caused by repeatedly dynamic allocations and copying 