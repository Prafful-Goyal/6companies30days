//PROBLEM STATEMENT
/*
A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.
*/
//CODE
class Solution {
    int fun(int start,int end)
    {
                //there r only four possible sitting arrarngments 
        
                if(2>=start && 9<=(end))  // 2-four people from 2->9
                    return 2;
                else if(2>=start && 5<=(end))
                    return 1;            // 1-four from 2-5
                else if(6>=start && 9<=(end))
                    return 1;           // 1-four from 6-9
                else if(4>=start && 7<=(end))
                    return 1;           // 1-four from 4-7
        
                return 0;      //or else cant;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        int ans=0;
        
        sort(a.begin(),a.end());
        
        int present=a[0][0];
        int last=1;
        
        set<int> st;  // this set is for
        // assume n=3, means 3 rows, but only 3rd row is reserved, so row-1 will contribute 2 four-seat + row-2 will contribute 2 four-seat
        //i hav added the remaining at last
        st.insert(present);
        
        
        for(int i=0;i<a.size();i++)
        {
            if(present==a[i][0])
            {         
                ans+=fun(last,(a[i][1]-1));
                
                last=a[i][1]+1;

            }
            else 
            {               
                ans+= fun(last,10);
            
                ans+=fun(1,a[i][1]-1);
                
                
                st.insert(a[i][0]);
                
                present=a[i][0];
                last=a[i][1]+1;
            }
                        
            
        }
        
        ans+= fun(last,10);
     
        if(st.size()!=n) ans+=(2*(n-st.size())); 
        
        return ans;
    }
};
