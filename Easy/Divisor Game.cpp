//O(n)
class Solution {
public:
    bool divisorGame(int n) {
        
        //vector<int> dp(n+1, -1);
        
        return play(n, 1);      
    }
    
    int play(int n, int turn) //turn = 1 for alice
    {
        if(n==1)
            return !turn;
        
//         if(dp[n] != -1)
//             return dp[n];
        
        // for(int x=1; x<n; x++)
        // {
        //     if(n%x == 0)
        //     {
        //         return play(n-x, !turn);
        //     }
        // }
        return play(n-1, !turn);
    }
};
