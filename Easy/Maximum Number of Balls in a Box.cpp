class Solution {
public:
    int countBalls(int ll, int hl) {
        
        vector<int> box(46, 0);      //largest sum is of 99999
        
        while(ll <= hl)
        {
            int k = ll;
            int sum = 0;
            
            while(k)
            {
                sum += k%10;
                k/=10;
            }
            box[sum]++;
            sum=0;
            ll++;
        }
        int maxm=0;
        for(int i=0; i<46; i++)
        {
            maxm = max(box[i],maxm);
        }
        return maxm;
    }
   
};

//Use hash-vector instead of map to count freq if max freq is known, coz it takes lesser time for traversal??
