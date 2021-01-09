class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0)
            return false;
        
        if(x < 10)
            return true;
        
        if(x%10 == 0 && x)
            return false;
        
        int n = 0;    //lower half of the number
        
        while(x > n)
        {
            n = (x%10) + n*10;
           
            x/=10;
        }
     
        return x==n || x==n/10;
    }
};