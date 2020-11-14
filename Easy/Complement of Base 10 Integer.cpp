//A binary number plus its complement will equal 111....111 in binary.

class Solution {
public:
    int bitwiseComplement(int N) 
    {
        vector<int> complements;
        int n = 1;
        
        while(n < 1000000000)
        {
            n*=2;
            complements.push_back(n-1);
        }  
        
        int i=0;
        while(complements[i] < N)
        {
            i++;
        }
        
        return complements[i]-N;
    }
};