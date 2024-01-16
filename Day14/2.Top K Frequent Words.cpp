//PROBLEM STATEMENT
/*
Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
*/
//CODE
/*
T.C = O(NLOGN)
S.C = O(N)
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        vector<string>ans;
        for(int  i=0 ; i<words.size()  ; i++){
            mp[words[i]]++;
        }
        vector<pair<string,int>>vt;
        for(auto a: mp){
            vt.push_back(a);
        }
        auto cmp = [&](auto &a , auto &b){
            if(a.second==b.second){
                return a.first < b.first;
            }
            return a.second> b.second;
        };
        sort(vt.begin() ,  vt.end() , cmp);

        for(auto a: vt){
            ans.push_back(a.first);
            k--;
            if(k==0){
                break;
            }
        }
        return ans;
    }
};
