//PROBLEM STATEMENT
/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.
*/
//CODE
//APPROACH => BINARY SEARCH AND SORTING
/*
T.C = O(NLOGN)
S.C = O(N)
*/
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) 
    {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> v;
        for(auto e : envelopes) 
        {
            if(!v.size() || v.back() < e[1])
            {
              v.push_back(e[1]);
            }
            else 
            {
                int pos = lower_bound(v.begin(), v.end(), e[1]) - v.begin();
                v[pos] = e[1];
            }
        }
        return v.size();
    }
};
