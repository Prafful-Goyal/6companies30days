//PROBLEM STATEMENT
/*
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
*/
//CODE
/*
  T.C = O(N*M)
  S.C = O(N*M)
*/
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1)
                {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int row = it.first,col = it.second;
            int val = ans[row][col];
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int newrow = row+delRow[i];
                int newcol = col+delCol[i];
                if(newrow>=0&&newrow<n&&newcol>=0&&newcol<m)
                {
                    if(ans[newrow][newcol]==-1)
                    {
                        ans[newrow][newcol] = val+1;
                        q.push({newrow,newcol});
                    }
                }
            }
        }
        return ans;
    }
};
