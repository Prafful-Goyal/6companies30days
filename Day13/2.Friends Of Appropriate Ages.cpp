//PROBLEM STATEMENT
/*
There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.

A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:

age[y] <= 0.5 * age[x] + 7
age[y] > age[x]
age[y] > 100 && age[x] < 100
Otherwise, x will send a friend request to y.

Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.

Return the total number of friend requests made.
*/
//CODE
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> v(121, 0);
        for(auto it: ages)
            v[it]++;
        int ans=0;
        for(int i=1; i<121; i++)
        {
            if(v[i]==0) continue;
            int tmp =0;
            for(int j=1; j<121; j++)
            {
                if(v[j]==0) continue;
                if(i==j)
                {
                    if(j>(i*0.5+7))
                        tmp+=(v[i]-1);
                }
                else
                {
                    bool flag= true;
                    if(j<=(i*0.5+7)) flag= false;
                    if(j>i) flag= false;
                    if(i<100 && j>100) flag= false;
                    if(flag)
                        tmp+=v[j];
                }
            }
            ans= ans + v[i]*tmp;
        }
        return ans;
    }
};
