class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {    
        int max_ = 0;
        int start = 0, end;
        map<char, int> m;
        
        for(int i=0; i<s.length(); i++)
        {
            end = i;
            
            if(m.find(s[end]) != m.end())
            {
                start = m[s[end]]+1;
                
                for(auto it = m.cbegin(); it != m.cend();)
                {
                    if(it->second < start)
                    {
                        m.erase(it++);
                    }
                    else
                        ++it;    
                }  
            }
            m[s[end]] = i;
            
            max_ = max(max_, m.size());
        }
        return max_;
    }   
    
    int max(int a, int b)
    {
        return (a>b)?a:b;
    } 
};