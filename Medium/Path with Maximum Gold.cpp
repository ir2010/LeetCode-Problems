class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid)
    {    
        int m = grid.size();
        int n = grid[0].size();
        
        int max_sum = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j])
                    findMaxGold(grid, i, j, grid[i][j], max_sum, visited);
        
        return max_sum;
    }
    
    void findMaxGold(vector<vector<int>> grid, int r, int c, int sum, int& max_sum, vector<vector<bool>>& visited)
    {
        //cout<<r<<" "<<c<<"\n";
        visited[r][c] = true;
        max_sum = max(max_sum, sum);
        
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        
        for(int i=0; i<4; i++)
        {
            int new_r = r + row[i];
            int new_c = c + col[i];
            
            if(new_r >=0 && new_r < grid.size() && new_c >=0 && new_c < grid[0].size()
              && !visited[new_r][new_c] && grid[new_r][new_c])
            {
                sum+=grid[new_r][new_c];
                findMaxGold(grid, new_r, new_c, sum, max_sum, visited);
                sum-=grid[new_r][new_c];
            }
        }
        //cout<<"sum="<<sum<<"\n";
        visited[r][c] = false;
    }
};