class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_not_hold = 0, curr_hold =0,
        next_not_hold = 0, next_hold = 0;
        for(int i = prices.size()-1; i>=0; i--){
            curr_not_hold = max(next_not_hold, 
            -prices[i] + next_hold);
            curr_hold = max(next_hold, prices[i]+
            next_not_hold);
            next_not_hold = curr_not_hold;
            next_hold = curr_hold;
        }
        return next_not_hold;
    }
};