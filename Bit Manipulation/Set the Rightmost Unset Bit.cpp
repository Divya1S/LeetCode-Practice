// Set the Rightmost Unset Bit

Description:
Given a number n, write a program to change its rightmost 0 bit to a 1.
For example, if n = 11 (Binary: 1011), the rightmost 0 is at index 2. 
Setting it to 1 should result in 1111 (which is 15).

Approach: Using n | (n + 1)
Just like subtraction flips bits for n & (n - 1), 
addition gives us a perfectly mirrored trick. 
When you add 1 to any binary number, it flips all the trailing 1s to 0s, and flips the first 0 it encounters into a 1.
Step-by-step logic for 
n = 11 (Binary: 1011):
Find n + 1: Adding 1 gives 12 (Binary: 1100). 
Notice how the trailing 1s flipped to 0, and the lowest 0 flipped to a 1.
Apply bitwise OR (|):
n: 1011
n + 1: 1100
n | (n + 1): 1111 (The lowest 0 is now filled in)

int setRightmostUnsetBit(int n) {
    // If all bits are 1 (e.g., 15 is 1111), n + 1 will carry over. 
    // Depending on the problem requirements, you might just return n, 
    // or let it naturally add the next power of 2.
    // For standard bit manipulation, n | (n + 1) works universally.
    return n | (n + 1);
}

int main() {
    int n = 11; // Binary: 1011
    
    cout << "Original number: " << n << " (Binary: 1011)\n";
    int result = setRightmostUnsetBit(n);
    cout << "After setting rightmost unset bit: " << result << " (Binary: 1111)\n";
    // Expected Output: 15
    
    // Another test case: 10 (Binary: 1010)
    // Lowest 0 is at index 0. Setting it should make it 1011 (11).
    cout << "Original number: 10 (Binary: 1010) -> Result: " 
              << setRightmostUnsetBit(10) << " (Binary: 1011)\n";
              
    return 0;
}

TC: O(1)
SC: O(1)

