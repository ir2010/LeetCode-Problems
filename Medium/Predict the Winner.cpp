class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
       map<pair<int, int>, int> dp;
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
            sum+=nums[i];
        
        int maxProfitBy1 = maxProfit(nums, 0, nums.size()-1, dp);
        
        int maxProfitBy2 = sum - maxProfitBy1;
        for(auto it: dp)
            cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<"\n";
        return maxProfitBy1 >= maxProfitBy2;
    }
    
    int maxProfit(vector<int> nums, int l, int r, map<pair<int, int>, int>& dp)
    {
        if(l>r)
            return 0;
        
        if(dp[{l, r}])
            return dp[{l, r}];
        
        //Player 1 picks the left score
        int l_profit = nums[l] + min(maxProfit(nums, l+2, r, dp), maxProfit(nums, l+1, r-1, dp));
        
        //Player 1 picks the right score
        int r_profit = nums[r] + min(maxProfit(nums, l+1, r-1, dp), maxProfit(nums, l, r-2, dp));
        
        return dp[{l, r}] = max(l_profit, r_profit);
    }
};