//PROBLEM STATEMENT
/*
Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.
*/
//CODE
/*
T.C = O(N)
S.C = O(N)
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int n = nums.size();
        pq.push({nums[0],0});
        int ans = nums[0];
        for(int i=1;i<n;i++)
        {
            while(i-pq.top().second>k)
            {
                pq.pop();
            }
            int sum = max(nums[i],pq.top().first+nums[i]);
            ans = max(ans,sum);
            pq.push({sum,i});
        }
        return ans;
    }
};
