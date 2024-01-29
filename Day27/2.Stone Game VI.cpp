//PROBLEM STATEMENT
/*
Alice and Bob take turns playing a game, with Alice starting first.
There are n stones in a pile. On each player's turn, they can remove a stone from the pile and receive points based on the stone's value. Alice and Bob may value the stones differently.
You are given two integer arrays of length n, aliceValues and bobValues. Each aliceValues[i] and bobValues[i] represents how Alice and Bob, respectively, value the ith stone.
The winner is the person with the most points after all the stones are chosen. If both players have the same amount of points, the game results in a draw. Both players will play optimally. Both players know the other's values.
Determine the result of the game, and:
If Alice wins, return 1.
If Bob wins, return -1.
If the game results in a draw, return 0.
*/
//CODE
/*
T.C = O(N*LOGN)
S.C = O(N)
*/
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size(), bob=0, alice=0;
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++) nums.push_back({aliceValues[i]+bobValues[i],i});
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<n;i++){
            int index=nums[i].second;
            if(i%2) bob+=bobValues[index];
            else alice+=aliceValues[index];
        }   
        if(bob==alice) return 0;
        
    return alice>bob ? 1 : -1;
    }
};
