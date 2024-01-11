//PROBLEM STATEMENT
/*
Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.

Return the maximum possible product of the lengths of the two palindromic subsequences.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.
*/
//CODE
/*
T.C = O(N^2)
S.C = O(N^2)
*/
class Solution {
public:
    int lps(string &s)
    {
        int n=s.size();
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        int dp[s.size()+1][s.size()+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=(s1[i-1]==s2[j-1])?1+dp[i-1][j-1]:max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][n];
    }
    int maxProduct(string s) {
        int ans=0;
        int n=s.size();
        for(int i=1;i<(1<<n)-1;i++)
        {
            string s1="",s2="";
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    s1.push_back(s[j]);
                }
                else
                {
                    s2.push_back(s[j]);
                }
            }
            ans=max(ans,lps(s1)*lps(s2));
        }
        return ans;
    }
};
