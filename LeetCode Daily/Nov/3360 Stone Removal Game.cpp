class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToRemove = 10;
        int turnsTaken = 0;

        while(n >= stonesToRemove) {
            n -= stonesToRemove;
            stonesToRemove--;
            turnsTaken++;
        }

        //odd number of turns means Alice made the last valid move 
        return turnsTaken % 2 == 1;
    }
};

// TC: O(1)
// stonesToRemove starts at 10 and decreases by 1 on every iteration.
// Given the constraint n <= 50 the loop runs atmost 7 times (10 + 9 + 8 + 7 + 6 + 5 + 4 = 49)

// SC: O(1)