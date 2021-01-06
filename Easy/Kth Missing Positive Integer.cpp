class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int numOfMissed = arr[0] - 1;
        if(numOfMissed >= k)
            return k;
        
        for(int i=1; i<arr.size(); i++)
        {
            numOfMissed += arr[i] - arr[i-1] - 1;
            if(numOfMissed >= k)
                return arr[i] - (numOfMissed - k + 1);
        }
        
        return arr[arr.size()-1] + k - numOfMissed;
    }
};