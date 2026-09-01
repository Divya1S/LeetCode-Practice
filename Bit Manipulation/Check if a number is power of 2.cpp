Problem Statement: Check if a Number is a Power of 2

Description:
Given an integer n, write a program to determine if it is a power of 2. 
A number is considered a power of 2 if it can be represented as 2^k where k is an integer (e.g., 1, 2, 4, 8, 16...).

Approach: 
Using n & (n - 1)
If you look at the binary representation of any power of 2, 
you will notice a distinct pattern: it has exactly one bit set to 1, 
and all other bits are 0.
2^0 = 1 (Binary: 0001)
2^1 = 2 (Binary: 0010)
2^2 = 4 (Binary: 0100)
2^3 = 8 (Binary: 1000)
In the previous step, we learned that the expression n & (n - 1) removes the rightmost set bit.
If a number is a power of 2, it only has one set bit. 
Therefore, removing that single bit will leave us with exactly 0.
Wait, what about zero or negative numbers?
Zero is not a power of 2, but 0 & (0 - 1) evaluates to 0, which would give us a false positive. 
Negative numbers are also not powers of 2. 
To handle this, we just need to add a simple check to ensure n > 0.

bool isPowerOfTwo(int n) {
    //The number must be strictly positive
    //If n & (n - 1) equals 0 it means there was only one set bit 
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int testCases[] = {0, 1, 4, 14, 32, -8};
    
    for (int n : testCases) {
        if (isPowerOfTwo(n)) {
            std::cout << n << " is a power of 2.\n";
        } else {
            std::cout << n << " is NOT a power of 2.\n";
        }
    }
    
    return 0;
}

TC: O(1)
SC: O(1)
