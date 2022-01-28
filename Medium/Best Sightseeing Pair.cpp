class Solution {
public:
    // dp [i] = max score when the pair is (k,i) : k<i
    // dp[i] = max (dp[i-1] - nums[i-1] + nums[i] - 1, nums[i] + nums[i-1] -1)
    
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, n = values.size(), prevMax = 0;
        
        for (int i=1; i<n; i++) {
            prevMax = max (prevMax - values[i-1] + values[i] - 1, values[i] + values[i-1] - 1);
            ans = max (ans, prevMax);
        }
        
        return ans;
    }
};
