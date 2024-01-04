//PROBLEM STATEMENT
/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/
//APPROACH(maintaining position indices within a 'm X n' matrix for flip operation and resetting positions in flip operation itself when matrix boundaries are reached.)
/*
T.C = O(1)
S.C = O(1)
*/
class Solution {
public:
    int n,m;
    int i=0,j=0;
    Solution(int m, int n) {
        this->n = n;
        this->m = m;
    }
    
    vector<int> flip() {
        int I = i,J=j;
        if(j+1<n)
        {
            j++;
        }
        else if(i+1<m)
        {
            i++;
            j=0;
        }
        else
        {
            i=0;
            j=0;
        }
        return {I,J};
    }
    
    void reset() {
        
    }
};
