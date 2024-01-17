//PROBLEM STATEMENT
/*
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.
Return the minimum number of extra characters left over if you break up s optimally.
*/
//CODE
class Solution {
public:
    unordered_map<string,int> mp;
    int dfs(int start ,string s,int end,vector<int>& dp ){
        if(end >= s.size()) return end-start;
        if(dp[start] != -1) return dp[start];
        string temp = s.substr(start,end-start+1);
        int ans = 1e9;
        //pick
        if(mp.find(temp) != mp.end()){
            ans = dfs(end+1,s,end+1,dp);
        }
        //not pick
        ans = min(ans,dfs(start,s,end+1,dp));
        //skip char
        ans = min(ans,end-start+1 +dfs(end+1,s,end+1,dp));
        return dp[start] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
    for(auto word:dictionary){
            mp[word]++;
        }
        int n = s.size();
         vector<int> dp(n+1,-1);
        return dfs(0,s,0,dp);
    }
};
