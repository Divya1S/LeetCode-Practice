Find XOR of numbers from L to R

Problem Statement: Given two integers L and R. 
Find the XOR of the elements in the range [L , R].

Example 1:
Input :
 L = 3 , R = 5
Output :
 2
Explanation : 
answer = (3 ^ 4 ^ 5) = 2.

Example 2:
Input :
 L = 1, R = 3
Output :
 0
Explanation : 
answer = (1 ^ 2 ^ 3) = 0.

Brute Force:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to find the XOR 
    of numbers from L to R*/
    int findRangeXOR(int l, int r){			
        
        // To store the XOR of numbers
		int ans = 0;
		
		// XOR all the numbers
		for(int i=l; i <= r; i++) {
		    ans ^= i;
		}
		
		// Return the result
		return ans;
	}
};

int main() {
    int l = 3, r = 5;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the
    XOR of numbers from L to R*/
    int ans = sol.findRangeXOR(l, r);
    
    cout << "The XOR of numbers from " << l << " to " << r << " is: " << ans;
    
    return 0;
}

Complexity Analysis
Time Complexity: O(N) Traversing through all the numbers take O(N) time.

Space Complexity: O(1) Using only a couple of variables, i.e., constant space.

Optimal Approach:

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /* Function to find the XOR 
    of numbers from 1 to n*/
    int XORtillN(int n) {
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n+1;
        if(n % 4 == 3) return 0;
        return n;
    }
    
public:
    /* Function to find the XOR 
    of numbers from L to R*/
    int findRangeXOR(int l, int r){			
		return XORtillN(l-1) ^ XORtillN(r);
	}
};

int main() {
    int l = 3, r = 5;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the
    XOR of numbers from L to R*/
    int ans = sol.findRangeXOR(l, r);
    
    cout << "The XOR of numbers from " << l << " to " << r << " is: " << ans;
    
    return 0;
}

Time Complexity: O(1) Using constant time operations.

Space Complexity: O(1) Using a couple of variables i.e., constant space.
