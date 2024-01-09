//PROBLEM STATEMENT
/*
An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).

Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.
*/
//CODE
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        //BRUTE FORCE APPROACH
        /*
        T.C = O(9*N*M)
        S.C = O(N*M)
        */
        /*
        int n = img.size(),m = img[0].size();
        vector<vector<int>>smoothing(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum = 0, count = 0;
                for(int x=i-1;x<=i+1;x++)
                {
                    for(int y=j-1;y<=j+1;y++)
                    {
                        if(x>=0&&x<n&&y>=0&&y<m)
                        {
                           sum += img[x][y];
                           count += 1;
                        }
                    }
                }
                smoothing[i][j] = sum/count;
            }
        }
        return smoothing;
        */
        //OPTIMIZED APPROACH(IN TERMS OF SPACE COMPLEXITY)
        /*
        T.C = O(2*N*M)
        S.C = O(1)
        */
        int n = img.size(),m = img[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum = 0, count = 0;
                for(int x=i-1;x<=i+1;x++)
                {
                    for(int y=j-1;y<=j+1;y++)
                    {
                        if(x>=0&&x<n&&y>=0&&y<m)
                        {
                           sum += img[x][y]&((1<<8)-1);//In this we just removing smoothing values
                           count += 1;
                        }
                    }
                }
                img[i][j] |= (sum/count)<<8;//In this we add smoothing values and original values
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                img[i][j] = img[i][j] >> 8;
            }
        }
        return img;
    }
};
