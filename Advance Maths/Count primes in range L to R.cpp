You are given an 2D array queries of dimension n*2
The queries[i] represents a range from queries[i][0] to queries[i][1] (including the end points)

Return the count of prime numbers present in between each range in queries array.

Input: 
queries = [ [2,5], [4,7]]
output:
[3,2]
The range 2 to 5 contains 3 prime nums: 2, 3, 5
The range 4 to 7 contains 2 prime nums: 5, 7

Example 2:
Input:
 queries = [ [1, 7], [3, 7] ]  
Output:
 [4, 3]  
Explanation:
  
The range 1 to 7 contains four prime numbers: 2, 3, 5, 7.  
The range 3 to 7 contains three prime numbers: 3, 5, 7.

Brute Force:
Sieve of Eratosthenes:
Create a boolean array isPrime[0...n], initially set all values to true.
Set isPrime[0] = false and isPrime[1] = false (0 and 1 are not prime).
Start from p = 2, the first prime number.
For each p:
If isPrime[p] is true, mark all multiples of p (i.e., p*2, p*3, …) as false.
Continue this process until p * p > n (no need to go beyond √n).
At the end, isPrime[i] tells whether i is a prime number.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> primesInRange(std::vector<std::vector<int>>& queries) {
        if (queries.empty()) {
            return {};
        }

        // Find the maximum value in the queries 
        // to determine the sieve range
        int maxVal = 0;
        for (const auto& query : queries) {
            maxVal = std::max(maxVal, query[1]);
        }

        // Step 1: Use the Sieve of Eratosthenes 
        // to find all primes up to maxVal
        std::vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;  // 0 and 1 are not primes
        for (int p = 2; p * p <= maxVal; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= maxVal; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        // Step 2: Create a prefix sum array 
        // to count primes up to each number
        std::vector<int> primeCount(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; ++i) {
            primeCount[i] = primeCount[i - 1];
            if (isPrime[i]) {
                primeCount[i]++;
            }
        }

        // Step 3: Process each query to find the number of primes 
        // in the given range
        std::vector<int> result;
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            if (start == 0) {
                result.push_back(primeCount[end]);
            } else {
                result.push_back(primeCount[end] - primeCount[start - 1]);
            }
        }

        return result;
    }
};

int main() {
    // Example usage
    // Create an instance of the Solution class
    Solution solution;
    
    // Call the function and store the result
    auto result = solution.primesInRange(queries);
    
    // Output the result
    cout << "The number of primes in the given ranges are: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}

TC: O(N log(logN))
for the Sieve of Eratosthenes where n is the max value in the queries.
The prefix sum computation takes O(n) and each query is processed in O(1) time.
Thus the overall complexity us dominated by the sieve 

SC: O(N)
For storing the prime status array and the prefix sum array where N is the max value in queries.
