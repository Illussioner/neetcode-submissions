class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return rec(prices,0,0,dp);
    }
private:
    int rec(vector<int>& prices, int i, int status,
    vector<vector<int>>& dp){
        if(i == prices.size()){
            return 0;
        }
        if(dp[i][status] != -1){
            return dp[i][status]; // already the result
            // is precomputed
        }
        int res = rec(prices, i+1, status, dp);
        if(status==1){
            res = max(res, prices[i] + rec(prices,i+1,0
            ,dp)); 
        }
        else{
            res = max(res, -prices[i] + rec(prices, i+1,1,
            dp));
        }
        dp[i][status] = res;
        return res;
    }
};