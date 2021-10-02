class Solution {
public:
    
    int ans(string w1, string w2){
        string s=w1+w2;
        string t=s;
        reverse(t.begin(),t.end());
        int n=(int)s.size();
        int dp[n+1][n+1];
        
        memset(dp,0,sizeof(dp));     
        int f=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        return dp[n][n];
    }
    
    int longestPalindrome(string w1, string w2) {
        int m=0,mr=0;
        vector<bool> v(26,0);
        for(int i=0;i<w1.size();i++){
            if(v[w1[i]-'a']){
                continue;
            }
            v[w1[i]-'a']=1;
            for(int j=w2.size()-1;j>=0;j--){
                if(w1[i]==w2[j]){
                    if(mr>j){
                        break;
                    }
                    if(m>(w1.size()-i+1+j)){
                        break;
                    }
                    // v[i]=1;
                    m=max(m,ans(w1.substr(i,w1.size()-i),w2.substr(0,j+1)));
                    mr=j;
                    break;
                }
            }
        }
        return m;
    }
};