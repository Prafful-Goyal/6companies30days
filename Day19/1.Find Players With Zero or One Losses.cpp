//PROBLEM STATEMENT
/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.
*/
//CODE
/*
T.C = O(N) WHERE N is the length of the matches
S.C = O(M) WHERE M is the number of players
*/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost_map;
        for(int i=0;i<matches.size();i++)
        {
            int lose=matches[i][1];
        lost_map[lose]++;
        }
        vector<int>notLost;
        vector<int>onceLost;
        for(int i=0;i<matches.size();i++)
        {
           int winner=matches[i][0];
           int looser=matches[i][1];
           if(lost_map.find(winner)==lost_map.end()) 
           {
               notLost.push_back(winner);
               lost_map[winner]=2;

           }
           if(lost_map[looser]==1)
           onceLost.push_back(looser);

        }
        sort(notLost.begin(),notLost.end());    
        sort(onceLost.begin(),onceLost.end());

        return {notLost,onceLost};
    }
};
