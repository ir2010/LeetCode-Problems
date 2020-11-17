class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        list<int>* adj = new list<int>[numCourses];
        
        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> ans;
        
        vector<bool> visited(numCourses, false);
        vector<bool> recursionStack(numCourses, false);
        
        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
                if(!topologicalSort(i, adj, visited, recursionStack, ans))
                    return vector<int>();
        }
        return ans;
    }
    
    bool topologicalSort(int v, list<int>* adj, vector<bool>& visited, vector<bool> rec, vector<int>& ans)
    {
        visited[v] = true;
        rec[v] = true;
        
        for(auto it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if(!visited[*it])
                if(!topologicalSort(*it, adj, visited, rec, ans))
                    return false;
            
            if(rec[*it])  //cycle exists
            {
                return false;
            }    
        }
        
        ans.push_back(v);
        rec[v] = false;
        return true;
    }
};