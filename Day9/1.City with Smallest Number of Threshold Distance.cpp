//PROBLEM STATEMENT
/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
*/
//APPROACH => FLOYD WARSHALL ALGORITHM
//CODE
/*
T.C = O(N^3)
S.C = O(N^2)
*/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++)
        {
            dist[i][i] = 0;
        }
        //FLOYD WARSHALL ALGORITHM
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]==INT_MAX||dist[k][j]==INT_MAX)
                    {
                        continue;
                    }
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int count = n;
        int cityNo = -1;
        for(int city = 0;city<n;city++)
        {
            int cnt = 0;
            for(int adjcity = 0;adjcity<n;adjcity++)
            {
                if(dist[city][adjcity]<=distanceThreshold)
                {
                    cnt++;
                }
            }
            if(cnt<=count)
            {
                count = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};
