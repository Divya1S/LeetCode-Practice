//Binary Search on Answers 
//Sliding Window 
//Rolling Hash

class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7; //large prime modulo to prevent integer overflow in rolling hash

    //computes (a^base) in O(log(base)) time using binary exponentiation
    ll findPower(ll a, ll base) {
        if (base == 0) {
            return 1;
        }

        ll half = findPower(a, base/2);
        ll result = (half * half) % MOD;

        //If the exponent is odd, multiply once more by the base 'a'
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    } 

    //checks if there exists atleast one unique subarray of length size
    bool check (vector<int>& nums, int size, int base) {
        int n = nums.size();

        ll hash = 0;
        unordered_map<ll, int> mp; //tracks the freq of each subarray hash

        //highest positional weight: base^(size-1) 
        ll p = findPower(base, size-1);

        int lptr = 0; //left boundary of sliding window
        int rptr = 0; //right boundary of sliding window 

        while (rptr < n) {
            //Append the new right element into the rolling polynomial hash
            hash = (hash * base + nums[rptr]) % MOD;

            //expand window until it reachest the target size
            if (rptr - lptr + 1 < size) {
                rptr++;
            } else {
                //record the hash of the current window of length 'size' 
                mp[hash]++;

                //remove the leftmost element's contribution before sliding the window 
                //(+MOD ensures the result stays non-negative after subtraction)
                hash = (hash - (p * nums[lptr])%MOD + MOD) % MOD;

                //Slide the window forward by one position
                lptr++;
                rptr++;
            }
        }
        
        //If any subarray has appeared strictly once, a unique subarray exists
        for (auto& it : mp) {
            if (it.second == 1) {
                return true;
            }
        }

        return false;

    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        //choose a base strictly larger than the max element to min collisions
        int base = *max_element(nums.begin(), nums.end()) + 1;

        //Binary search on the answer: subarray len ranges from 1 to n
        int low = 1; 
        int high = n;

        int result = n; //the entire array of length n is guaranteed to be unique

        while(low <= high) {
            int mid = low + (high - low) / 2;

            //if a unique subarray of length 'mid' exists try searching for a smaller length 
            if (check(nums, mid, base)) {
                result = mid;
                high = mid - 1;
            }
            else {
                //otherwise we need a longer subarray to make it unique
                low = mid + 1;
            }
        }

        return result;
    }
};

// TC: O(NlogN) avg, O(N^2) worst case 
// N = num of elements in array
// *max_element: scans the arr once O(N)
// binary search: binary search over the range [1, N] executing check() atmost O(logN) times
// binary exponentiation (findPower): O(log(size)) <= O(logN) time 
// sliding window: while loop traverses the arr in O(N) steps 
// each hash insertion and update in unordered_map takes O(1) avg time and O(N) in worst case due to hash collisions 
// then iterating the map takes up to O(N) time as there are atmost (N - size + 1) subaarrays 
// Total check call: O(N + logN) = O(N) avg O(N^2) worst case 

// SC: O(N)
// map: O(N)
// findPower() recursion takes: O(logN)