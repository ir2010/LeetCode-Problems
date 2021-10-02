class Solution {
public:
    vector<vector<char>> v;
    bool check(vector<vector<char>>& a,int n,int m){
        int x=(n/3)*3,y=(m/3)*3;
        unordered_map<int,int> mp;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(a[i][j]!='.'){
                    mp[a[i][j]]++;
                    if(mp[a[i][j]]>1) return 0;
                }
            }
        }
        
        mp.clear();
        for(int i=0;i<9;i++){
            if(a[i][m]!='.'){
                mp[a[i][m]]++;
                if(mp[a[i][m]]>1) return 0;
            }
        }
        mp.clear();
        for(int i=0;i<9;i++){
            if(a[n][i]!='.'){
                mp[a[n][i]]++;
                if(mp[a[n][i]]>1) return 0;
            }
        }
        return 1;
    }
    
    bool fill(vector<vector<char>>& a,int n,int m){
        
        if(n>8 || m>8) return 0;
        
        if(v[n][m]!='.'){
            if(n==8 && m==8) return 1;
            
            if(m==8){
                return fill(a,n+1,0);
            }
            else return fill(a,n,m+1);
            
        }
        
        for(int i=0;i<9;i++){
            a[n][m]=(char)('1'+i);
            if(check(a,n,m)){
                if(n==8 && m==8) return 1;
                
                if(m==8 && fill(a,n+1,0)){
                    return 1;
                }
                else if(fill(a,n,m+1)){
                    return 1;
                }
            }
        }
        a[n][m]='.';
        return 0;
    }
    
    void solveSudoku(vector<vector<char>>& a) {
        v=a;
        fill(a,0,0);
    }
};