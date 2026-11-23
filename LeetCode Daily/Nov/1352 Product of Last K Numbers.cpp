/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

//Brute Force
// class ProductOfNumbers {
// public:
//     vector<int> nums;
//     int n;

//     ProductOfNumbers() {
//         nums.clear();
//         n = 0;
//     }
    
//     void add(int num) {
//         nums.push_back(num);
//     }
    
//     int getProduct(int k) {
//         int prod = 1;
//         int n = nums.size();

//         for (int i = n-k; i < n; i++) {
//             prod *= nums[i];
//         }

//         return prod;
//     }
// };

// TC:
// ProductOfNumbers(): O(1)
// add(int num): O(1) amortized push_back takes const time on avg worst case O(N) when vector is resized 
// getProduct(int k): O(k) iterates through last k elements once 

// SC: 
// ProductOfNumbers(): O(1)
// add(int num): O(1)
// getProduct(int k): O(1) aux space 

//Optimal Approach:
class ProductOfNumbers {
public:
    //stores the running (prefix) product of non-zero numbers since the last 0
    vector<int> nums; //now we are using nums to store cumulative product
    //tracks the count of consecutive non-zero numbers currently in nums
    int n;

    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            //Any future product that includes this 0 will be 0
            //so reset the prefix array and start fresh
            nums = {};
            n = 0;
        }else {
            if (nums.empty()) {
                //first non-zero element since start or last 0
                nums.push_back(num);
            }else {
                //multiply the previous cumulative product by the new number 
                nums.push_back(nums[n-1] * num);
            }
            n++; 
        }
    }
    
    int getProduct(int k) {
        //if k exceeds the num of elements since the last 0
        //the last k elements must include at least one 0
        if (k > n) {
            return 0;
        } 
        //if k equals n the product is simply the entire cumulative product 
        else if (k == n) {
            return nums[n-1];
        }

        //divide the total product by the product of elements before the last k 
        return nums[n-1] / nums[n-k-1];
    }
};

// TC: 
// ProductOfNumbers(): O(1)
// add(int num): O(1) amortized 
// getProduct(int k): O(1) performs a const time comparison and at mmost one division

// SC: 
// ProductOfNumbers(): O(1)
// add(int num): O(1)
// getProduct(int k): O(1) aux space 