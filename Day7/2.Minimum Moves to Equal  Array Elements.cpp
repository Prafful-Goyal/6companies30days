//PROBLEM STATEMENT
/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.
*/
//CODE
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        /*
        T.C = O(NLOGN)
        S.C = O(LOGN)(FOR SORTING)
        */
        /*
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int median = n%2==0?(nums[n/2]+nums[n/2-1])/2:nums[n/2];
        int steps = 0;
        for(auto it:nums)
        {
            steps += abs(it-median);
        }
        return steps;
        */
        //ANOTHER APPROACH
        sort(nums.begin(),nums.end());
        int i=0,j=nums.length()-1;
        int steps = 0;
        while(i<j)
        {
           steps += (nums[j]-nums[i]);
           i++;
           j--;
        }
        return steps;
    }
};
