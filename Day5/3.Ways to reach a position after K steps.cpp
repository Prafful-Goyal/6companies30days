//PROBLEM STATEMENT
/*
You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. With one step, you can move either one position to the left, or one position to the right.

Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you perform exactly k steps. Since the answer may be very large, return it modulo 109 + 7.

Two ways are considered different if the order of the steps made is not exactly the same.

Note that the number line includes negative integers.
*/
//CODE
/*
T.C = O(3002*1001)
S.C = O(3002*1001)
*/
class Solution {
public:
    const int mod = 1000000007;
    long long solve(int s,int e,int k,vector<vector<long long>>&dp)
    {
        if(k==0)
        {
            if(s==e)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[s+1000][k]!=-1)
        {
            return dp[s+1000][k];
        }
        int rightmove = solve(s+1,e,k-1,dp)%mod;
        int leftmove = solve(s-1,e,k-1,dp)%mod;
        return dp[s+1000][k] = (rightmove+leftmove)%mod;

    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<long long>>dp(3002,vector<long long>(1001,-1));
        return solve(startPos,endPos,k,dp);
    }
};
