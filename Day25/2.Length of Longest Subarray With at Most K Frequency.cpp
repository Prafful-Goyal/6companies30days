//PROBLEM STATEMENT
/*
You are given an integer array nums and an integer k.
The frequency of an element x is the number of times it occurs in an array.
An array is called good if the frequency of each element in this array is less than or equal to k.
Return the length of the longest good subarray of nums.
A subarray is a contiguous non-empty sequence of elements within an array.
*/
//CODE
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i=0,j=0;
        unordered_map<int,int>freq;
        int maxlen = 0;
        while(j<n)
        {
                freq[nums[j]]++;
                while(freq[nums[j]]>k)
                {
                    int len = j-i;
                    maxlen = max(maxlen,len);
                    freq[nums[i]]--;
                    i++;
                }
                if(freq[nums[j]]<=k)
                {
                    int len = j-i+1;
                    maxlen = max(maxlen,len);
                }
            j++;
        }
        return maxlen;
    }
};
