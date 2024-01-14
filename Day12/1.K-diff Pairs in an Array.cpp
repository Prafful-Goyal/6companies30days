//PROBLEM STATEMENT
/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.
*/
//APPROACH => USING UNORDERED_MAP
//CODE
/*
T.C = O(N)
S.C = O(N)
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int cnt = 0;
        for(auto it:mp)
        {
            if(mp.find(it.first-k)!=mp.end())
            {
                if(it.first-k==it.first)
                {
                    if(it.second>=2)
                    {
                        cnt++;
                        mp[it.first] -= 2;
                    }
                }
                else
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
