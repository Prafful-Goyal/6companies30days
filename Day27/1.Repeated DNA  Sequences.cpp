//PROBLEM STATEMENT
/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.
Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
*/
//CODE
/*
T.C = O(N)
S.C = O(N)
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>ans;
        if(s.size()<10)
        {
            return ans;
        }
        for(int i=0;i<s.size()-9;i++)
        {
            string str = s.substr(i,10);
            mp[str]++;
        }
        for(auto it:mp)
        {
            if(it.second>1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
