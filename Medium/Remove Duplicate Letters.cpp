class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<char> order;                //for lexicographical order
        vector<int> lastIndexOf(26);      //to check if we can remove this character and add at a later position or not
        string res = "";
        
        for(int i=0; i<s.length(); i++)
            lastIndexOf[s[i]-'a'] = i;
        
        vector<bool>included(26, false);  //to check if this character is already included in final string or not
        
        for(int i=0; i<s.length(); i++)
        {
            if(!included[s[i]-'a'])
            {
                //pop all elements greater than curr elem to maintain lexical order
                while(!order.empty() && order.top() >= s[i] && lastIndexOf[order.top()-'a'] > i)  
                {
                    included[order.top()-'a'] = false;
                    res.erase(res.end()-1);
                    order.pop();
                }
                order.push(s[i]);
                res+=s[i];
                included[s[i]-'a'] = true;
            }    
        }
        return res;
    }
};