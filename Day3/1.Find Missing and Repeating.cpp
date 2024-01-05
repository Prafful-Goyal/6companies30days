//PROBLEM STATEMENT
/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
*/
class Solution{
public:
vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        //APPROACH 1(using map simply check which number occur twice and which number occur zero times)
        /*
        T.C = O(N)
        S.C = O(N)
        */
        /*
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int missing,repeating;
        for(int i=1;i<=n;i++)
        {
            if(mp[i]==2)
            {
                repeating = i;
            }
            if(mp[i]==0)
            {
                missing = i;
            }
        }
        return {repeating,missing};
        */

        //APPROACH 2(IN this we treat input array as visited array and simply check which element already visited and also check which element is never visited)
        /*
        T.C = O(N)
        S.C = O(1)
        */
        int missing,repeating;
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1]<0)
            {
                repeating = abs(arr[i]);
            }
            else
            {
                arr[abs(arr[i])-1] = -1*arr[abs(arr[i])-1];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                missing = i+1;
                break;
            }
        }
        return {repeating,missing};
}
};
