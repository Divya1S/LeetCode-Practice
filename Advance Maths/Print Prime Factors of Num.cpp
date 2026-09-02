Given a positive integer N, find and print all of its prime factors. A prime factor is a prime number that divides N without leaving a remainder. If a prime factor appears multiple times (like how 2 divides 12 twice), it should be printed that many times.

Examples
Input: 12
Output: 2 2 3
(Explanation: 12 is completely divisible by 2 twice, leaving 3. So, 2 × 2 × 3 = 12)

Input: 315
Output: 3 3 5 7
(Explanation: 3 × 3 × 5 × 7 = 315)

Input: 11
Output: 11
(Explanation: 11 is a prime number itself)

Brute Force Approach:
The brute force method checks every number i from 2 up to N. 
For each i, it explicitly checks whether i is prime. 
If i is prime, it repeatedly divides N by i as long as i divides N cleanly.

#include <iostream>

// Helper function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void primeFactorsBruteForce(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) { // Primality check
            while (n % i == 0) {
                cout << i << " ";
                n /= i;
            }
        }
    }
}

int main() {
    int n = 315;
    cout << "Brute Force factors: ";
    primeFactorsBruteForce(n);
    return 0;
}

TC: O(N * sqrt(N)) in worst case 
where N is prime the loop runs N times and performs an O(sqrt(i)) primality test on each iteration 

SC: O(1)

2. Better Approach:
This approach eliminates the explicit isPrime() check. 
By iterating i from 2 up to N and immediately dividing out all occurrences of i, 
composite numbers are automatically skipped. 
For example, by the time i = 4, all factors of 2 have already been removed, so N will never be divisible by 4.

#include <iostream>

void primeFactorsBetter(int n) {
    for (int i = 2; i <= n; i++) {
        // No explicit prime test needed; factors of previous primes are already removed
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
}

int main() {
    int n = 315;
    cout << "Better approach factors: ";
    primeFactorsBetter(n);
    return 0;
}

TC: O(N) in worst case (when N is prime, the loop runs upto N)
SC: O(1) 

3. Optimal Approach:
A composite number N must have at least one prime factor less than or equal to sqrt{N}. 
By running the loop only up to sqrt{N} (using i * i <= n), runtime is significantly reduced. 
Furthermore, factoring out 2 first allows skipping all even numbers in the loop by incrementing i by 2.

#include <iostream>

void primeFactorsOptimal(int n) {
    // Process all factors of 2 first
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Process odd factors up to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // If n is still > 2, then the remaining n is itself prime
    if (n > 2) {
        cout << n << " ";
    }
}

int main() {
    int n = 315;
    std::cout << "Optimal factors: ";
    primeFactorsOptimal(n);
    return 0;
}

TC: O(sqrt(N)) worst case (when N is prime loop starts at sqrt(N))
SC: O(1)

