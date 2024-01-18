//PROBLEM STATEMENT
/*
You are given three integers x, y, and z.

You have x strings equal to "AA", y strings equal to "BB", and z strings equal to "AB". You want to choose some (possibly all or none) of these strings and concatenate them in some order to form a new string. This new string must not contain "AAA" or "BBB" as a substring.

Return the maximum possible length of the new string.

A substring is a contiguous non-empty sequence of characters within a string.
*/
//CODE
class Solution {
public:
    int longestString(int x, int y, int z) {
                char s,e;
        int ans = 0;
        if(x>y)
        {
            s = 'x';
            e = 'x';
            x = x-y-1;
            ans+=2*y+1;
            y = 0;
            
        }
        else if(y>x)
        {
            s = 'y';
            e = 'y';
            y = y-x-1;
            ans+=2*x+1;
            x = 0;
            
        }
        else
        {
            s = 'x';
            e = 'y';
            x = 0;
            ans=ans+2*y;
            y = 0;
        }

        if(x>0 && z>0)
        {
            if((s=='y' && e=='y') || (s=='x' && e=='y'))
            {
                z--;
                x--;
                ans+=2;
            }
        }
        if(y>0 && z>0)
        {
            if((s=='x' && e=='x') || (s=='x' && e=='y'))
            {
                z--;
                y--;
                ans+=2;
            }
        }

        if(z>0)
        ans+=z;


        return ans*2;
    }
};
