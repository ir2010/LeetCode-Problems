class Solution {
public:
    map <pair<int, int>, bool> dp;
    set<pair<int, int>> visited;
    
    bool canMeasureWater(int c1, int c2, int t) {
        if (t > c1+c2)
            return false;
        if (c1 == 0 && c2 == 0)
            return t==0;
        
        // bfs O(c1*c2) ..?
        // return bfs (c1, c2, t);
        
        // dfs O(c1*c2) ..?
        // return dfs (c1, c2, t, 0, 0);
        
        // O(1)
        return t % __gcd (c1, c2) == 0;
        
    } 
    
    bool bfs (int c1, int c2, int t) {
        queue<pair<int, int>> q;
        q.push ({0,0});
        set<pair<int,int>> visited;
        visited.insert ({0, 0});
        
        while (!q.empty()) {
            pair<int, int> conf = q.front();
            q.pop();
            
            if (conf.first == t || conf.second ==t || conf.first + conf.second == t)
                return true;
            
            vector<pair<int, int>> v {{0, conf.second}, {conf.first, 0}, {c1, conf.second}, {conf.first, c2}, {c1, conf.second - (c1-conf.first)}, {conf.first - (c2-conf.second), c2}, {0, conf.second + conf.first}, {conf.second + conf.first, 0}};
            
            for (int i=0; i<8; i++) {
                int new_x = v[i].first;
                int new_y = v[i].second;
                
                if (new_x >= 0 && new_y >=0 && new_x <= c1 && new_y <= c2 && 
                    visited.find({new_x, new_y}) == visited.end()) {
                    q.push({new_x, new_y});
                    visited.insert ({new_x, new_y});
                }
            }
        }
        return false;
    }
    
    
    bool dfs (int c1, int c2, int t, int x, int y) {
        // cout<<x<<" "<<y<<"\n";
        visited.insert ({x,y});
        if (dp.find ({x, y}) != dp.end())
            return dp[{x,y}];
        
        if (x == t || y ==t || x+y ==t)
            return dp[{x,y}] = true;
        
        // empty one
        if (visited.find ({x,0}) == visited.end())
            if (dfs (c1, c2, t, x, 0))
                return dp[{x,y}] = true;
        if (visited.find ({0,y}) == visited.end())
            if (dfs (c1, c2, t, 0, y))
                return dp[{x,y}] = true;
        
        // fill one
        if (visited.find ({c1,y}) == visited.end())
            if (dfs (c1, c2, t, c1, y))
                return dp[{x,y}] = true;
        if (visited.find ({x,c2}) == visited.end())
            if (dfs (c1, c2, t, x, c2))
                return dp[{x,y}] = true;
        
        // transfer from 1 to 2 until 2 is full
        if (x-(c2-y) >= 0 && visited.find ({x-(c2-y),c2}) == visited.end())
            if (dfs (c1, c2, t, x-(c2-y), c2))
                return dp[{x,y}] = true;
        // transfer from 1 to 2 until 1 is empty
        if (x+y <= c2 && visited.find ({0,x+y}) == visited.end())
            if (dfs (c1, c2, t, 0, x+y))
                return dp[{x,y}] = true;
        
        // transfer from 2 to 1 until 1 is full
        if (y-(c1-x) >= 0 && visited.find ({c1,y-(c1-x)}) == visited.end())
            if (dfs (c1, c2, t, c1, y -(c1-x)))
                return dp[{x,y}] = true;
        // transfer from 2 to 1 until 2 is empty
        if (x+y <= c2 && visited.find ({x+y,0}) == visited.end())
            if (dfs (c1, c2, t, x+y, 0))
                return dp[{x,y}] = true;
        return dp[{x,y}] = false;
    }
};
