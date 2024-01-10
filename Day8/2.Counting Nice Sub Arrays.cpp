//PROBLEM STATEMENT
/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.
*/
//CODE
/*
T.C = O(N)
S.C = O(N)
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i]%2;
            if(mp.find(sum-k)!=mp.end())
            {
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};
