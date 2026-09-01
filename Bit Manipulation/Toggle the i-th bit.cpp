// Problem Statement: Toggle the i-th Bit

// Description:
// Given a number n and an integer i, write a program to toggle the i-th bit from the right (0-indexed) of n.
//  "Toggling" a bit means changing it to 1 if it is currently 0, and changing it to 0 if it is currently 1.

// Approach: Using Left Shift and XOR (<< and ^)

int toggleBit(int n, int i) {
    //Create mask (1 << i) and apply XOR 
    return n ^ (1 << i);
}

int main() {
    int n = 10; // Binary: 1010
    
    // Test 1: Toggle a bit that is currently 1 (index 1)
    int i1 = 1; 
    cout << "Original number: " << n << " (Binary: 1010)\n";
    int result1 = toggleBit(n, i1);
    cout << "After toggling " << i1 << "-th bit: " << result1 << " (Binary: 1000)\n\n";
    // Expected Output: 8
    
    // Test 2: Toggle a bit that is currently 0 (index 2)
    int i2 = 2;
    int result2 = toggleBit(n, i2);
    cout << "After toggling " << i2 << "-th bit: " << result2 << " (Binary: 1110)\n";
    // Expected Output: 14
    
    return 0;
}

// TC: O(1)
// SC: O(1)