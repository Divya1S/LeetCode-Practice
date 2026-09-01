Problem Statement: Count Set Bits

Description:
Given an integer n, 
write a program to count the total number of set bits (1s) in its binary representation by examining each bit one by one, from right to left.

Approach: Right Shift and Check (n & 1 and n >> 1)

Check the rightmost bit: The expression n & 1 performs a bitwise AND with 1. 
This isolates the last bit. If the number is odd, the last bit is 1, and n & 1 evaluates to 1. 
If the number is even, it evaluates to 0. We simply add this result to our total count.

Shift right: We use the right shift operator (n = n >> 1) to push all the bits one position to the right.
The bit we just checked falls off, and the next bit moves into the rightmost position.

Repeat: We loop this process until n becomes 0 (meaning no more 1s are left in the number).

Note: It is a best practice to use an unsigned int for this approach. 
If you right-shift a negative signed integer, C++ performs an arithmetic shift which 
pads the left side with 1s instead of 0s leading to an infinite loop)

int countSetBitShift(unsigned int n) {
    int count = 0;

    //Continue until all bits are shifted out 
    while (n > 0) {
        //Add the rightmost bit to the count (1 if odd, 0 if even)
        count += (n & 1);

        //Shift all bits to the right by 1 position 
        n = n >> 1; //n = n/2
    }

    return count;
}

int main() {
    unsigned int testCases[] = {0, 7, 14, 32, 127};
    
    for (unsigned int n : testCases) {
        cout << "Number: " << n << "\t -> Set bits: " << countSetBitsShift(n) << "\n";
    }
    // Output:
    // Number: 0   -> Set bits: 0
    // Number: 7   -> Set bits: 3 (Binary: 0111)
    // Number: 14  -> Set bits: 3 (Binary: 1110)
    // Number: 32  -> Set bits: 1 (Binary: 100000)
    // Number: 127 -> Set bits: 7 (Binary: 1111111)
    
    return 0;
}

TC: O(logn) or exactly O(b)
where b is the position of the most significant set bit 
The loop rins exactly once for every bit up to the highest 1 (eg: 4 times for 14 which is 1110)
SC: O(1)

Approach: Brian Kernighan's Algorithm (n & (n - 1))
We already know that the expression n & (n - 1) clears the rightmost set bit of $n$. 
Brian Kernighan's Algorithm uses this exact property in a loop to efficiently count the bits.
Instead of shifting the number and checking every single bit one by one (which would always take 32 iterations for a 32-bit integer), we can simply repeatedly apply n & (n - 1) until the number becomes 0. 
The number of times we are able to execute this operation is exactly equal to the number of set bits in the original integer.

Step-by-step logic for n = 14 (Binary: 1110):
Initial state: n = 1110, count = 0
Iteration 1: n = 1110 & 1101 = 1100, count = 1
Iteration 2: n = 1100 & 1011 = 1000, count = 2
Iteration 3: n = 1000 & 0111 = 0000, count = 3
End: n is 0. The loop terminates, and we return count = 3.

int countSetBits(int n) {
    int count = 0;

    //Continue until all bits are cleared 
    while (n > 0) {
        n = n & (n - 1); //Clear the lowest set bit 
        count++;
    }

    return count;
}

int main() {
    int testCases[] = {0, 7, 14, 32, 127};
    
    for (int n : testCases) {
        std::cout << "Number: " << n << "\t -> Set bits: " << countSetBits(n) << "\n";
    }
    // Output:
    // Number: 0   -> Set bits: 0
    // Number: 7   -> Set bits: 3 (Binary: 0111)
    // Number: 14  -> Set bits: 3 (Binary: 1110)
    // Number: 32  -> Set bits: 1 (Binary: 100000)
    // Number: 127 -> Set bits: 7 (Binary: 1111111)
    
    return 0;
}

TC: O(k)
where k is the number of set bits in n.
In worst case (eg: all 1s) its O(logn) 
But on average it is significantly faster than checking every single bit.

SC: O(1)

