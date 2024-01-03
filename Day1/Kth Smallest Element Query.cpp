//PROBLEM STATEMENT
/*
You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.

You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

Trim each number in nums to its rightmost trimi digits.
Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
Reset each number in nums to its original length.
Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.

Note:

To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
Strings in nums may contain leading zeros.
*/

//APPROACH -> USE PRIORITY QUEUE
/*
    T.C = O(N*M) WHERE N IS THE SIZE OF QUERY AND M IS THE SIZE OF NUMS
    S.C = O(M)(FOR PRIORITY QUEUE)+O(N)(FOR ANSWER)
*/
 class Solution {
 public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it:queries)
        {
            int trimval = it[1];
            int kthsmallest = it[0];
            priority_queue<pair<string,int>>pq;
            for(int i=0;i<nums.size();i++)
            {
                 string x = nums[i];
                 int len = x.size();
                 string str = x.substr(len-trimval,trimval);
                 if(pq.size()<kthsmallest)
                 {
                     pq.push({str,i});
                 }
                 else
                 {
                     if(pq.top().first>str)
                     {
                         pq.pop();
                         pq.push({str,i});
                     }
                 }
            }
            int val = pq.top().second;
            ans.push_back(val);
        }
        return ans;
    }
};
