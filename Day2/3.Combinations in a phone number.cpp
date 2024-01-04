//PROBLEM STATEMENT
/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/
//APPROACH(Using an array of strings to store each string of corresponding letters of the numbers and backtracking to find combnations of letters based on the mapping.)
class Solution {
public:
    void letterCombinationshelp(string digits,vector<string>&output,string temp,vector<string>&pad,int index)
    {
        if(index==digits.size())
        {
            output.push_back(temp);
            return;
        }
        string value = pad[digits[index]-'0'];
        for(int i=0;i<value.size();i++)
        {
            temp.push_back(value[i]);
            letterCombinationshelp(digits,output,temp,pad,index+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>output;
        if(digits.empty())
        {
            return output;
        }
        vector<string>pad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp = "";
        letterCombinationshelp(digits,output,temp,pad,0);
        return output;
    }
};
