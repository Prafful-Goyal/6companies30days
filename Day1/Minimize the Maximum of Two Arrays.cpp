//PROBLEM STATEMENT
/*
We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:

arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
No integer is present in both arr1 and arr2.
Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.
*/

//APPROACH -> BINARY SEARCH
/*
    T.C = O(LOG 10^10)
    S.C = O(1)
*/
class Solution {
public:
    long gcd(long a,long b)
    {
        if((a%b)==0)
        {
           return b;
        }
        else
        {
            return gcd(b,a%b);
        }
    }
    void bs(long l,long h,int divisor1,int divisor2,long lcm,long *ans,int c1,int c2 )
    {
        if(l<=h)
        {
            long m = (l+h)/2;
            
            long a = m - (m/divisor1);
            long b = m - (m/divisor2);
            long c = m - (m/divisor1) - (m/divisor2) + (m/lcm);

            if(a>=c1&&b>=c2&&a+b-c>=c1+c2)
            {
                (*ans) = m;
                bs(l,m-1,divisor1,divisor2,lcm,ans,c1,c2);
            }
            else
            {
                bs(m+1,h,divisor1,divisor2,lcm,ans,c1,c2);
            }
        }
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long g = gcd(max(divisor1,divisor2),min(divisor1,divisor2));
        long l = (long(divisor1)*long(divisor2))/g;
        long ans = 1000000000;
        bs(1,10000000000,divisor1,divisor2,l,(&ans),uniqueCnt1,uniqueCnt2);
        return ans;
    }
};
