//PROBLEM STATEMENT
/*
You are given two strings s and t of the same length and an integer maxCost.
You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.
*/
//CODE
/*
T.C = O(N)
S.C = O(1)
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = str.size();

        int left = 0;

        int curr_cost = 0;

        int maxi = 0;

        // apply sliding window

        for(int right = 0; right < n; right++)
        {
            // add the cost into curr_cost

            curr_cost += abs(str[right] - tar[right]);

            // shrink the window from left to decrement the curr_cost, to make it within range

            while(left <= right && curr_cost > maxCost)
            {
                curr_cost -= abs(str[left] - tar[left]);

                left++;
            }

            // update maxi

            maxi = max({maxi, right - left + 1});
        }

        return maxi;
    }
};
