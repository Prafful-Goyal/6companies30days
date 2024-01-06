//PROBLEM STATEMENT
/*
Given an integer array nums and two integers k and p, return the number of distinct subarrays, which have at most k elements that are divisible by p.

Two arrays nums1 and nums2 are said to be distinct if:

They are of different lengths, or
There exists at least one index i where nums1[i] != nums2[i].
A subarray is defined as a non-empty contiguous sequence of elements in an array.
*/
//CODE
/*
    T.C = O(N^2)
    S.C = O(N^2)
*/
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        map<vector<int>,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            vector<int>temp;
            int count = 0;
            for(int j=i;j<nums.size();j++)
            {
                temp.push_back(nums[j]);
                if(nums[j]%p==0)
                {
                    count++;
                }
                if(count>k)
                {
                    break;
                }
                mp[temp]++;
            }
        }
        return mp.size();
    }
};
