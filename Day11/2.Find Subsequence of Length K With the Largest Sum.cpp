//PROBLEM STATEMENT
/*
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
Return any such subsequence as an integer array of length k.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
*/
//APPROACH => USING MINIMUM PRIORITY QUEUE
//CODE
/*
T.C = O(NLOGN)
S.C = O(K)
*/
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
            if(pq.size()>k)
            {
               pq.pop();
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
        while(!pq.empty())
        {
            pq1.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        vector<int>ans;
        while(!pq1.empty())
        {
            ans.push_back(pq1.top().second);
            pq1.pop();
        }
        return ans;
    }
};
