//PROBLEM STATEMENT
/*
You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.
*/
//CODE
/*
T.C = O(N)
S.C = O(1)
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        int f0 = 0;
        for(int i=0;i<n;i++)
        {
           totalsum += nums[i];
           f0 += i*nums[i];
        }
        int maxfn=f0,previousfn = f0;
        for(int i=n-1;i>=0;i--)
        {
            int nextfn = previousfn+totalsum-n*(nums[i]);
            maxfn = max(maxfn,nextfn);
            previousfn = nextfn;
        }
        return maxfn;
    }
};
