//PROBLEM STATEMENT
/*
Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.
*/
//CODE
/*
T.C = O(N)
S.C = O(1)
*/
string encode(string src)
{     
  //Your code here
  int n = src.size();
  string ans = "";
  int count = 1;
  char ch;
  for(int i=0;i<n-1;i++)
  {
      if(src[i]==src[i+1])
      {
          count++;
          ch = src[i];
      }
      else
      {
          ans += src[i]+to_string(count);
          count = 1;
      }
  }
  if(ch!=src[n-1])
  {
      ans += src[n-1]+to_string(1);
  }
  else
  {
      ans += src[n-1]+to_string(count);
  }
  return ans;
}     
