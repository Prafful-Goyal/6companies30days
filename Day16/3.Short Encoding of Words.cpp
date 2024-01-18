//PROBLEM STATEMENT
/*
A valid encoding of an array of words is any reference string s and array of indices indices such that:

words.length == indices.length
The reference string s ends with the '#' character.
For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.
*/
//CODE
/*
T.C = O(2N+N*S)
S.C = O(N)
*/
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(), words.end()); //store word in set so that they can remove easily
        
        //for each word find its suffixes and remove from set s if it present
        for(auto &word: words)
        {
            for(int i=1; i<word.size(); i++) //erase suffixes of a word
                s.erase(word.substr(i));
        }
        
        int ans=0;
        //all the remaining words in s are valid encoding string
        for(auto word:s)
            ans += word.size()+1;
        
        return ans;
    }
};
