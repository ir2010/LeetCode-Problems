class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        //Longest proper prefix that is also a proper suffix ending at index i
        vector<int> lps(s.length());
        lps[0] = 0;
        
        int len = 0;
        int i = 1;
        
        while(i < s.length())
        {
            if(s[i] == s[len])
            {
                lps[i] = len+1;
                i++;
                len++;
            }
            else
            {
                if(len != 0)
                {
                    len = lps[len-1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        if(lps[s.length()-1] == 0)
            return false;
        
        int lengthOfRepeatedSubstring = s.length() - lps[s.length()-1];
        
        return s.length()%lengthOfRepeatedSubstring == 0;        
    }
};