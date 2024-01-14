//PROBLEM STATEMENT
/*
You are given a positive integer 0-indexed array nums.

A subset of the array nums is square-free if the product of its elements is a square-free integer.

A square-free integer is an integer that is divisible by no square number other than 1.

Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo 109 + 7.

A non-empty subset of nums is an array that can be obtained by deleting some (possibly none but not all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
*/
//APPROACH => DP TABULATION + BITMASK
//CODE
/*
T.C = O(n*2^10)
S.C = O(n*2^10)
*/
#define ll long long
class Solution {
public:
    int memo[1001][1024];
    vector<int>vec={2,3,5,7,11,13,17,19,23,29};
    ll mod=1e9+7;
    ll dp(vector<int>&nums,int i,int mask)
    {
        if(i==nums.size()) return 1;
        if(memo[i][mask]!=-1) return memo[i][mask];
        int temp=mask,flag=1;
        for(int j=0;j<10;j++)
        {
            int num=nums[i],count=0;
            while(num%vec[j]==0)  num/=vec[j], count++;
            if(count>=2 or ((count==1) and ((mask>>j)&1)))
            {
                flag=0;
                break;
            }
            if(count) temp=temp|(1<<j);
        }
        if(flag)
               return memo[i][mask]=(dp(nums,i+1,mask)+dp(nums,i+1,temp))%mod;
        else
              return memo[i][mask]=dp(nums,i+1,mask);
        
    }
    
    int squareFreeSubsets(vector<int>& nums) 
    {
        memset(memo,-1,sizeof(memo));
        return 1LL*(dp(nums,0,0)-1+mod)%mod;  
    }
};
