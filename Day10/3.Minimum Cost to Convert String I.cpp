//PROBLEM STATEMENT
/*
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].
*/
//CODE
#pragma GCC optimize("O3", "unroll-loops")
// Use Floyd Warshall's algorithm
class Solution {
public:
    vector<char> original, changed;
    vector<int> cost;
    int D[26][26];
    void FW(){
        fill(&D[0][0], &D[0][0]+26*26, INT_MAX);//Use C++ fill
        int sz=original.size();
        for (int i=0; i<sz; i++){
            int row=original[i]-'a';
            int col=changed[i]-'a';
            D[row][col]=min(D[row][col], cost[i]);
        }
        for (int i=0; i<26; i++) D[i][i]=0;

        for(int k=0; k<26; k++)
            for(int i=0; i<26; i++)
                for(int j=0; j<26; j++)
                    D[i][j]=min((long long)D[i][j], (long long)D[i][k]+D[k][j]);

    }
    long long minimumCost(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        this->original=original;
        this->changed=changed;
        this->cost=cost;
        FW();
        int n=source.size();
        long long ans=0;
        for(int i=0; i<n; i++){
            int row=source[i]-'a';
            int col=target[i]-'a';
            if (D[row][col]==INT_MAX) return -1;
            ans+=D[row][col];
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
