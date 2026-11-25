//Recursive (Binary Exponentiation)

class Solution {
public: 
    using ll = long long;
    static constexpr ll MOD = 1e9 + 7;

    //Computes (a^exp) % MOD using recursive binary exponentiation
    ll findPower(ll a, ll exp) {
        //base case: any number raised to the power of 0 is 1
        if (exp == 0) {
            return 1;
        }

        //Reduce 'a' modulo MOD to prevent overflow during multiplication 
        a %= MOD;

        //Recursively compute a^(exp/2) 
        ll half = findPower(a, exp / 2);

        //Square the half result: (a^(exp / 2))^2 
        ll result = (half * half) % MOD;

        //If the exponent is odd, multiply once more by the base 'a'
        if (exp % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }
};

// TC: O(log(exp)) exp is halved at every recursive call 
// SC: O(log(exp)) using recursion call stack 

//Iterative Solution (Binary Exponentiation)
//The iterative approach builds the answer using the binary representation of exp 
//eliminating recursion stack overhead 

class Solution {
public:
    using ll = long long;
    static constexpr ll MOD = 1e9 + 7;

    //Computes (a^exp) using iterative binary exponentiation 
    ll findPower(ll a, ll exp) {
        ll result = 1;
        a %= MOD; //Reduce base modulo to prevent overflow 
    }

    while(exp > 0) {
        //If the current exponent is odd (lowest bit is 1) 
        //multiply the current base power into the result 
        if (exp % 2 == 1) {
            result = (result * a) % MOD;
        }

        //Square the base for the next bit position 
        a = (a * a) % MOD;

        //Halve the exponent (equivalent to right-shifting by 1 bit)
        exp /= 2;
    }

    return result;
};

TC: O(log(exp)) the loop runs once per bit of exp 

SC: O(1) 