// Problem Statement: Remove the Rightmost Set Bit

// Description:
// Given a number n, write a program to clear its rightmost set bit. 
// For example, if the binary representation is 10110, the rightmost set bit is at index 1. 
// Removing it should result in 10100.

// Using n & (n - 1):
// This is one of the famous and widely used bit manipulation tricks. You can remove the rigtmost set bit 
// in a single operation using the expression n & (n - 1)

// When you subtract 1 from any binary number, an interesting pattern occurs: all bits up to and including the rightmost 1 are flipped.

// Let's look at n = 12 (Binary: 1100):
// Find n - 1: Subtracting 1 gives 11 (Binary: 1011).
// Notice how the rightmost 1 (at index 2) flipped to 0,
// and all the 0s to its right flipped to 1s
// The bits to the left remained completely unchanged.
// Apply bitwise AND: n: 1100
// n - 1: 1011
// n & (n - 1): 1000 (The rightmost set bit is now removed!)

int removeRightmostSetBit(int n) {
    //If n is 0, there are no set bits to remove
    if (n == 0) {
        return 0;
    }

    //Clear the lowest set bit 
    return n & (n - 1);
}

int main() {
    int n = 20; // Binary: 10100
    
    std::cout << "Original number: " << n << " (Binary: 10100)\n";
    int result = removeRightmostSetBit(n);
    std::cout << "After removing rightmost set bit: " << result << " (Binary: 10000)\n";
    // Expected Output: 16
    
    return 0;
}

TC: O(1)
SC: O(1)

