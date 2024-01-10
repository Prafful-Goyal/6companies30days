//PROBLEM STATEMENT
/*
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.
*/
//CODE
/*
T.C = O(N)
S.C = O(N)
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>secretfreq;
        unordered_map<char,int>guessfreq;
        int bulls = 0,cows = 0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
               bulls++;
            }
            else
            {
                secretfreq[secret[i]]++;
                guessfreq[guess[i]]++;
            }
        }
        for(auto it:guessfreq)
        {
            cows += min(it.second,secretfreq[it.first]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
