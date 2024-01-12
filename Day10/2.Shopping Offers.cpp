//PROBLEM STATEMENT
/*
In LeetCode Store, there are n items to sell. Each item has a price. However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

You are given an integer array price where price[i] is the price of the ith item, and an integer array needs where needs[i] is the number of pieces of the ith item you want to buy.

You are also given an array special where special[i] is of size n + 1 where special[i][j] is the number of pieces of the jth item in the ith offer and special[i][n] (i.e., the last integer in the array) is the price of the ith offer.

Return the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers. You are not allowed to buy more items than you want, even if that would lower the overall price. You could use any of the special offers as many times as you want.
*/
//CODE
class Solution {
public:
    void find(vector<int>& price, vector<vector<int>>& special, vector<int> &needs, int idx , int &mn_price , int Price){
        mn_price = min(mn_price,Price);
        if(idx==special.size()) return;
        int n = needs.size();
        // not take
        find(price,special,needs,idx+1,mn_price,Price);
        vector<int> needs2 = needs;
        // new price calculation
        for(int i = 0; i<n; i++){
            if(needs2[i]<special[idx][i]) return;
            Price = Price - special[idx][i]*price[i];
            // update our needs
            needs2[i] = needs2[i]-special[idx][i];
        }
        Price+= special[idx][n];
        //take
        find(price,special,needs2,idx,mn_price,Price);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int mn_price = 0;
        int n = price.size();
        for(int i = 0; i<n; i++){
            mn_price+= price[i]*needs[i];
        }
        map<vector<int>,int> mp;
        for(auto &v : special){
            vector<int> temp(v.begin(),v.end()-1);
            if(mp.find(temp)==mp.end()) mp[temp] = v[v.size()-1];
            else{
                if(v[v.size()-1]<mp[temp]){
                    mp[temp] = v[v.size()-1];
                }
            }
        }
        special.clear();
        for(auto &p : mp){
            vector<int> temp = p.first;
            temp.push_back(p.second);
            special.push_back(temp);
        }
        find(price,special,needs,0,mn_price,mn_price);
        return mn_price;
    }
};
