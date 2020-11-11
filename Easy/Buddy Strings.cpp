class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        int prob=-1;
        bool swapDone = false;
        map<char, int> freq;
        
        if(A.length() != B.length())
            return false;
        
        for(int i=0; i<A.length(); i++)
        {
            freq[A[i]]++;
            
            if(A[i] != B[i] && prob == -1)
                prob = i;
            
            else if(A[i] != B[i] && A[i] == B[prob] && swapDone)
                return false;
            
            else if(A[i] != B[i] && A[i] == B[prob] && B[i] == A[prob])
                swapDone = true;
            
            else if(A[i] != B[i] && A[i] != B[prob])
                return false;
        }
        if(A == B)
        {
            for(auto it: freq)
                if(it.second > 1)
                    return true;
        }
        return swapDone;
    }
};