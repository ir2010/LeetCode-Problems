//very very awesome question 
//must do quesions

class Solution {
public:
    int dp[50001];
    int fp[50001];
  
    int fin(vector<tuple<int,int,int>>& v, int cur){
        
        // O(n) search
        //to total algo runs in O(N*N)
        if(fp[cur]!=-1) return fp[cur];
        for (int next = cur + 1; next < v.size(); next++) {
            if (get<0>(v[next]) >= get<1>(v[cur])) {
                return fp[cur]= next;   
            }
        }
        //Binary search sol O(log n) search
        //so total algorithm works in O(nlogn)
        
//         int n=v.size();
//         int s=cur+1,e=n-1,ans=-1;
//         while(s<=e){
//             int mid=(s+e)/2;
//             if(get<0>(v[mid])>=get<1>(v[cur]))ans=mid,e=mid-1;
//             else s=mid+1;
//         }
       
        
        return fp[cur]=-1;
    }
    int sol(vector<tuple<int,int,int>>& v, int i){
        if(i==v.size() || i==-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int x=0, y=0;
       
        
        
        //if we schedule this
        int next = fin(v,i);
   
        x = get<2>(v[i]) + sol(v,next);
        
        
        //if we dont schedule this
        y = sol(v,i+1);
        
        
        return dp[i]= max(x,y);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        memset(dp,-1,sizeof(dp));
        memset(fp,-1,sizeof(fp));
        int n = profit.size();
        vector<tuple<int,int,int>> v;
        
        for(int i=0; i<n; i++){
            v.push_back({startTime[i],endTime[i], profit[i]});  
        }
        
        sort(v.begin(), v.end());
        
        
        return sol(v, 0);
    }
};
