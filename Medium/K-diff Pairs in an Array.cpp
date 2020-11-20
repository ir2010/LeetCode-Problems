class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        set<int> s;
        int c=0;
        set<int> dups;  //for tracking duplicates in k=0 case
      
        for(int i=0; i<nums.size(); i++)
        {
            if(s.find(nums[i]) != s.end())    //for dealing with duplicate pairs
            {
                if(k==0)
                {
                    if(dups.find(nums[i]) == dups.end())
                    {
                        dups.insert(nums[i]);
                        c++;
                    }    
                }
                continue;
            }
            
            if(s.find(nums[i] - k) != s.end())
            {
                cout<<nums[i] - k<<" "<<nums[i]<<" "<<i<<"\n";
                c++;
            }
            if(s.find(nums[i] + k) != s.end())
            {
                cout<<nums[i] + k<<" "<<nums[i]<<" "<<i<<"\n";
                c++;
            }
            s.insert(nums[i]);
        }
        return c;
    }
};


    