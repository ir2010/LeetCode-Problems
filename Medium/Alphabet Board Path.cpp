// https://leetcode.com/problems/alphabet-board-path/

class Solution {
public:
    vector<vector<char>> board;
    string alphabetBoardPath(string target) {
        
        map<char, pair<int, int>> board;
        
        int k=0;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                board['a'+(k++)] = make_pair(i, j);
            }
        }
        board['z'] = make_pair(5, 0);
        
        string output = "";
        int index = 0, curr_r = 0, curr_c = 0;
        
        while(index < target.length())
        {
            int r = board[target[index]].first - curr_r;
            int c = board[target[index]].second - curr_c;
            
            if(r < 0)           //keeping 'U' as the first is imp bcoz 'z' is a corner case, e.g. from 'z' to 'd'
            {
                for(int i=0; i<abs(r); i++)
                    output+='U';
            }
            if(c < 0)          //keeping 'L' at top is imp for any transition from an element to 'z', e.g. from 'd' to 'z'
            {
                for(int i=0; i<abs(c); i++)
                    output+='L';
            }
            
            if(r > 0)
            {
                for(int i=0; i<r; i++)
                    output+='D';
            }
            
            if(c > 0)
            {
                for(int i=0; i<c; i++)
                    output+='R';
            }
            
            output+='!';
            curr_r+=r;
            curr_c+=c;
            index++;
        }
    
        return output;
    }
};
