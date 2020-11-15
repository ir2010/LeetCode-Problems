class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        list<int>* adj = new list<int>[numCourses];
        
        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> recursionStack(numCourses, false);
        
        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
                if(!topologicalSort(i, adj, visited, recursionStack))
                    return false;
        }
        return true;
    }
    
    bool topologicalSort(int v, list<int>* adj, vector<bool>& visited, vector<bool> rec)
    {
        visited[v] = true;
        rec[v] = true;
        
        for(auto it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if(!visited[*it])
                if(!topologicalSort(*it, adj, visited, rec))
                    return false;
            
            if(rec[*it])  //cycle exists
            {
                return false;
            }    
        }

        rec[v] = false;
        return true;
    }
};