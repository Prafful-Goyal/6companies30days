//PROBLEM STATEMENT
/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.
*/
//CODE
/*
T.C = O(NLOGN)
S.C = O(N)
*/
class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        priority_queue<pair<int,char>>maxH;
        string ans;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }

        for(auto it:m){
            maxH.push({it.second, it.first});
        }

        while(maxH.size()>0){
            int freq= maxH.top().first;
            char ch=maxH.top().second;
            while(freq --){
                ans.push_back(ch);
            }
            maxH.pop();
        }
        return ans;
    }
};
