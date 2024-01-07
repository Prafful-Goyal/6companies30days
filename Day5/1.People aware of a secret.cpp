//PROBLEM STATEMENT
/*
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.
*/
//CODE
/*
T.C = O(N)
S.C = O(N)
*/
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long int>dp(n+1);
        dp[1] = 1;
        const int mod = 1e9 +7;
        long long int numOfPeopleSharingSecret = 0;
        
        for(int i=2;i<=n;i++)
        {
            long long int numOfNewPeopleSharingSecret = dp[max(0,i-delay)];
            long long int numOfPeopleForgettingSecret = dp[max(0,i-forget)];
            
            numOfPeopleSharingSecret = (numOfPeopleSharingSecret + numOfNewPeopleSharingSecret - numOfPeopleForgettingSecret+mod)%mod;
            dp[i] = numOfPeopleSharingSecret%mod;
        }
        long long int ans = 0;
        for(int i=n-forget+1;i<=n;i++)
        {
            ans = (ans+dp[i])%mod;
        }
        return ans%mod;
    }
};
