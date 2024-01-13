//PROBLEM STATEMENT
/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
*/
//APPROACH => LONGEST INCREASING SUBSEQUENCE
//CODE
/*
T.C = O(N^2+N)
S.C = O(N)
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        sort(nums.begin(),nums.end());
        int maxi = -1;
        int lastindex = -1;
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
            for(int previndex=0;previndex<i;previndex++)
            {
               if(nums[i]%nums[previndex]==0&&1+dp[previndex]>dp[i])
               {
                   dp[i] = 1+dp[previndex];
                   hash[i] = previndex;
               }
            }
            if(dp[i]>maxi)
            {
                maxi = dp[i];
                lastindex = i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex)
        {
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;

    }
};
