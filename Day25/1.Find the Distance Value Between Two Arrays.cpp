//PROBLEM STATEMENT
/*
Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.
The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.
*/
//CODE
/*
T.C = O(NLOGN)
S.C = O(1)
*/
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        for(auto var:arr1)
        {
            int start = 0;
            int end = arr2.size()-1;
            int mid = (start + end)/2;
            res++;
            while(start <= end)
            {
                mid = (start + end)/2;
                if((arr2[mid] <= (d+var))  and (arr2[mid] >= (var-d)))
                {
                    res--;
                    break;
                }
                else if(arr2[mid] > (d+var))                    end = mid-1;
                else                                          start = mid+1;
            }
        }
        return res;
    }
};
