class RecentCounter 
{
    set<int> times;
public:
    RecentCounter() {
    }
    
    int ping(int t) 
    {    
        if(times.empty())
        {
            times.insert(t);
            return 1;
        }
        
        auto it = times.begin();
        
        while(it != times.end() && t - *it > 3000)
        {
            times.erase(it);  
            it++;
        }
       
        times.insert(t);
        
        return times.size();
    }
};

//space O(1)
//time O(1)