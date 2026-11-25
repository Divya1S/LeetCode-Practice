//Brute Force:
class Solution {
public:
    double myPow(double x, int n) {
        long longN = n;
        if (longN < 0) {
            x = 1 / x;
            longN = -longN;
        }
        
        double ans = 1.0;
        for (long i = 0; i < longN; i++) {
            ans *= x;
        }

        return ans;
    }
};

// Since our n is very large (eg: 2^31 - 1) this will cause TLE.
// TC: O(n)
// SC: O(1)

// Using Recursion 
class Solution {
public:

    double solve(double x, long n) {
        if (n == 0)
            return 1;
        
        if (n < 0) {
            //line below raises an issue called floating point precision loss
            // return solve(1/x, -n);
            return 1.0 / solve(x, -n);
        }

        if (n%2 == 0)  //if n is even
            return solve(x*x, n/2);

        return x*solve(x*x, (n-1)/2); //if n is odd
    }
    double myPow(double x, int n) {
        return solve(x, (long)n);
    }
};

// TC = O(logn)
// We are halving the search space here.
// If n is even, we do solve(x*x, n/2) you cut n in half
// If n is odd, we subtract 1 (making it even) and then cut in half.

// SC = O(logn)

// Iterative Approach:
// Instead of calling a function recursively you can use a while loop. This brings the space complexity down to O(1) while maintaining the O(logn) time complexity.

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        bool isNegative = exp < 0;
        if (isNegative) {
            exp = -exp;
        }

        double ans = 1.0;

        while (exp > 0) {
            if (exp % 2 == 1) {
                ans *= x;
            }
            x *= x;
            exp /= 2;
        }

        return isNegative ? 1.0 / ans : ans;
    }
};

// TC: O(log n)
// SC: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};