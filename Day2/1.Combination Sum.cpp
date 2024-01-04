//PROBLEM STATEMENT
/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/
//APPROACH(RECURSION)
/*
  T.C = O(2^K)
  S.C = O(2^K)
*/
class Solution {
public:
    void solve(int i,int k,int n,int sumtillnow,vector<int>&subset,vector<vector<int>>&ans)
    {
        if(sumtillnow>n)
        {
            return;
        }
        if(k==0)
        {
            if(sumtillnow==n)
            {
                ans.push_back(subset);
            }
            return;
        }
        if(i==10)
        {
            return;
        }
        sumtillnow += i;
        subset.push_back(i);
        solve(i+1,k-1,n,sumtillnow,subset,ans);
        sumtillnow -= i;
        subset.pop_back();
        solve(i+1,k,n,sumtillnow,subset,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>subset;
        vector<vector<int>>ans;
        solve(1,k,n,0,subset,ans);
        return ans;
    }
};
