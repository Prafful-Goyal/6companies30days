//PROBLEM STATEMENT
/*
You are given an array of non-negative integers nums and an integer k. In one operation, you may choose any element from nums and increment it by 1.
Return the maximum product of nums after at most k operations. Since the answer may be very large, return it modulo 109 + 7. Note that you should maximize the product before taking the modulo.
*/
//CODE
class Solution {
    using ll = long long;
    int mod = 1e9 + 7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k>0){
            int ans = pq.top();
            pq.pop();
            ans++;
            pq.push(ans);
            k--;
        }
        ll pro = 1;
        while(pq.empty() == false){
            pro*=pq.top();
            pro=pro%mod;
            pq.pop();
        }
        return pro;
    }
};
