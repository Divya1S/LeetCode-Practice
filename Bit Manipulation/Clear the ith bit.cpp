// Problem Statement: Clear the i-th Bit
// Description: Given a number n and an integer i, write a program to clear the i-th bit from the right (0-indexed) of n. 
// "Clearing" a bit means setting it to 0. If the i-th bit is already 0, the number should remain unchanged.

// Approach: Using Left Shift, NOT, and AND (<<, ~, &)

int clearBit(int n, int i) {
    //Create mask: (1 << i) 
    //Invert mask: ~(1 << i) 
    //Apply AND: n & ~(1 << i)
    return n & ~(1 << i);
}

int main() {
    int n = 15; // Binary: 1111 (All 4 lower bits are 1)
    int i = 2;  // We want to clear the bit at index 2
    
    std::cout << "Original number: " << n << "\n";
    int result = clearBit(n, i);
    std::cout << "After clearing " << i << "-th bit: " << result << "\n";
    // Expected Output: 11 (Binary: 1011)
    
    return 0;
}

TC: O(1)
SC: O(1)

