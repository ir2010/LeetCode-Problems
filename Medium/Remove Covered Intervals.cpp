class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        //sort in descending order of end, and ascending order of start
        //making sure that the elements being covered by i lies on its right side only(from i+1 to n)
        //desc order bcoz erase() works better 
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y){if(x[1]==y[1]) return x[0]<y[0]; return x[1] > y[1];} );  
        for(int i=0; i<intervals.size(); i++)
        {
            for(int j=i+1; j<intervals.size(); j++)
            {
                if(intervals[i][0] <= intervals[j][0])            //intervals[j] is covered
                {
                    intervals.erase(intervals.begin()+j);
                    j--;                                          //shifting happens after erase
                }   
            }
        }
        return intervals.size();
    }
};