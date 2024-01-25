//PROBLEM STATEMENT
/*
You are given two 0-indexed arrays of strings startWords and targetWords. Each string consists of lowercase English letters only.
For each string in targetWords, check if it is possible to choose a string from startWords and perform a conversion operation on it to be equal to that from targetWords.
The conversion operation is described in the following two steps:
Append any lowercase letter that is not present in the string to its end.
For example, if the string is "abc", the letters 'd', 'e', or 'y' can be added to it, but not 'a'. If 'd' is added, the resulting string will be "abcd".
Rearrange the letters of the new string in any arbitrary order.
For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and so on. Note that it can also be rearranged to "abcd" itself.
Return the number of strings in targetWords that can be obtained by performing the operations on any string of startWords.
Note that you will only be verifying if the string in targetWords can be obtained from a string in startWords by performing the operations. The strings in startWords do not actually change during this process.
*/
//CODE
class Solution {
public:
    int wordCount(vector<string>& s, vector<string>& t) {
        int n = t.size();
        map<string,int> m;
        for(int i=0;i<n;i++)
        {
            sort(t[i].begin(),t[i].end());
            m[t[i]]++;
        }
        int ans=0;
        
        for(int i=0;i<s.size();i++)
        {
            string tmp = s[i];
            for(int j=0;j<26;j++)
            {
                char ch = 97+j;
                if(find(tmp.begin(),tmp.end(),ch)==tmp.end())
                {
                    string tmp2 = s[i]+(ch);
                    sort(tmp2.begin(),tmp2.end());
                    if(m.find(tmp2)!=m.end())
                    {
                        ans+=m[tmp2];
                        m.erase(tmp2);
                    }
                }
            }
        }
        return ans;
    }
};
