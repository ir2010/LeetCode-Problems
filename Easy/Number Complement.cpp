class Solution {
public:
    int findComplement(int num) {
        
        vector<int> complements;
        long long n = 1;
     
        long long p = pow(2, 32);
        while(n < p)
        {
            n*=2;
            complements.push_back(n-1);
        }  
        
        int i=0;
        while(i<complements.size() && complements[i] < num)
        {
            i++;
        }
        
        return complements[i] - num;
    }
};