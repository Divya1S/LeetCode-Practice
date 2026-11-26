// //Brute Force
// class StockSpanner {
// private: 
//     vector<int> prices;
// public: 
//     StockSpanner() {

//     }

//     int next(int price) {
//         //Store todays price 
//         prices.push_back(price);

//         int span = 1;

//         //Start from yesterday and move backwards why are we starting from yesterday? the answer to this is that we have already counted today by initializing span = 1
//         for (int i = prices.size() - 2; i >= 0; i--) {
//             //If prev price is <= todays price it is part of the span 
//             if (prices[i] <= price) {
//                 span++;
//             } else {
//                 //Found a greater price, so stop 
//                 break;
//             }
//         }
//         return span;
//     }
// };

// TC: O(N^2)
// Time per next() : O(N)
// Total for n calls : O(N^2) 

// SC: O(N)

//Optimal Solution using Stack 
class StockSpanner {
private:
    //Stack will store pairs of {price, currentSpan}
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        //Constructor can stay empty, the stack is automatically initialized 
    }
    
    int next(int price) {
        int currentSpan = 1; //currently span of price is 1 which is itself

        //While stack has elements AND the top price is <= today's price 
        while(!st.empty() && st.top().first <= price) {
            currentSpan += st.top().second;
            st.pop();
        }

        //Push todays price and its newly accumulated span 
        st.push({price, currentSpan});

        return currentSpan;
    }
};

// TC: O(N)
// next() function has while loop (but each value is pushed to stack exactly once and popped exactly once) So amortized time complexity is O(1) per next() call 
// SC: O(N) stack can contain upto N elements in worst case