//PROBLEM STATEMENT
/*
Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.
*/

//APPROACH(In this question for 'I' we put value in increasing order and for 'D' we put in decreasing order for making this we use stack data structure and perform this implementation)
//EX: IIDDD ->1 2 6 5 4 3
/*
T.C = O(N)
S.C = O(N)
*/
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here
        /*
        T.C = O(N)
        S.C = O(N)
        */
        string ans = "";
        stack<int>st;
        int num = 1;
        int n = S.size();
        for(int i=0;i<n;i++)
        {
            if(S[i]=='D')
            {
                st.push(num);
                num++;
            }
            else
            {
                st.push(num);
                num++;
                while(!st.empty())
                {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
        }
        return ans;
    }
};
