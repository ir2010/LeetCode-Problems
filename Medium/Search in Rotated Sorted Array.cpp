class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int l=0, r=n-1;
        if (n==0)
            return -1;
        
        while(l<=r) {
            int mid = (l+r)/2, k = nums[mid];
            if (k == t)
                return mid;
            
            if (k <= nums[0] && k <= nums[n-1]) {
              // a[k...n-1] is increasing
                if (k > t)
                    r=mid-1;
                else if (k<t && nums[n-1]<t)
                    r=mid-1;
                else if (k<t && nums[n-1]>=t)
                    l=mid+1;
            } else if (k >= nums[0] && k >= nums[n-1]) {
               // a[0...k] is increasing
                if (k > t && nums[0] > t)
                    l=mid+1;
                else if (k > t && nums[0] <= t)
                    r=mid-1;
                else if (k < t)
                    l=mid+1;
            } else if (k < t)
                l=mid+1;
            else if (k>t)
                r=mid-1;        
        }
        return -1;
    }
};
