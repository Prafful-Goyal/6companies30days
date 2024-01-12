//PROBLEM STATEMENT
/*
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.
*/
//CODE
/*
T.C = O(NLOGN)
S.C = O(N)
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        sort(nums.begin(),nums.end());
        int i=1,j=n-1;
        while(i<n)
        {
            res[i] = nums[j];
            i += 2;
            j--;
        }
        i=0;
        while(i<n)
        {
            res[i] = nums[j];
            i += 2;
            j--;
        }
        for(int i=0;i<n;i++)
        {
            nums[i] = res[i];
        }
    }
};
