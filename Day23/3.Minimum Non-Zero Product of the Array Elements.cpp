//PROBLEM STATEMENT
/*
You are given a positive integer p. Consider an array nums (1-indexed) that consists of the integers in the inclusive range [1, 2p - 1] in their binary representations. You are allowed to do the following operation any number of times:
Choose two elements x and y from nums.
Choose a bit in x and swap it with its corresponding bit in y. Corresponding bit refers to the bit that is in the same position in the other integer.
For example, if x = 1101 and y = 0011, after swapping the 2nd bit from the right, we have x = 1111 and y = 0001.
Find the minimum non-zero product of nums after performing the above operation any number of times. Return this product modulo 109 + 7.
Note: The answer should be the minimum product before the modulo operation is done.
*/
//CODE
class Solution {

    long long mod = 1000000007;

    long long exp(long long n, long long k){

        long long res = 1, mul = n;

        while(k){

            if(k&1){
                res = (mul*res)%mod;
            } 

            k >>= 1;
            mul = (mul%mod)*(mul%mod)%mod;
        }

        return res;
    }


public:
    int minNonZeroProduct(int p) {
        
        long long max = (1ll<<p)-1;
        long long half = exp(max-1,max/2);

        return half*(max%mod)%mod; 
    }
};
