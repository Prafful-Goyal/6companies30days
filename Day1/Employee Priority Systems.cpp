// PROBLEM STATEMENT
/*
You are given a 2D 0-indexed array of strings, access_times, with size n. For each i where 0 <= i <= n - 1, access_times[i][0] represents the name of an employee, and access_times[i][1] represents the access time of that employee. All entries in access_times are within the same day.

The access time is represented as four digits using a 24-hour time format, for example, "0800" or "2250".

An employee is said to be high-access if he has accessed the system three or more times within a one-hour period.

Times with exactly one hour of difference are not considered part of the same one-hour period. For example, "0815" and "0915" are not part of the same one-hour period.

Access times at the start and end of the day are not counted within the same one-hour period. For example, "0005" and "2350" are not part of the same one-hour period.

Return a list that contains the names of high-access employees with any order you want.
*/

//APPROACH

//WE USE MAP AND STORE EACH STRING CORRESPONDING MINUTES IN VECTOR AND THEN SORT THE VECTOR OF MINUTES OF EACH STRING AND THEN SIMPLE CHECK IF THEIR
//DIFFERENCE BETWEEN TIMES<=60 AND IF WE GET ACESS TIMES >= 3 TIMES WITHIN IN A ONE-HOUR PERIOD THEN WE SIMPLY PUT THIS STRING IN MY ANSWER VECTOR
/*
  T.C = O(N*(k+NLOGN)) WHERE K IS LENGTH OF MINUTES
  S.C = O(N)+O(N)~O(N)
*/
    
class Solution {
    public:
    
    bool isValid(vector<int>&times)
    {
        for(int i=0;i<times.size()-2;i++)
        {
            if(times[i+2]-times[i]<60)
            {
                return true;
            }
        }
        return false;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
       vector<string>ans;
        unordered_map<string,vector<int>>unmp;
        for(auto x:access_times)
        {
            string hour = x[1].substr(0,2);
            string min = x[1].substr(2,2);
            int minute = stoi(hour)*60+stoi(min);
            unmp[x[0]].push_back(minute);
        }
        for(auto it:unmp)
        {
            if(it.second.size()<3)
            {
                continue;
            }
            sort(it.second.begin(),it.second.end());
            if(isValid(it.second))
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
