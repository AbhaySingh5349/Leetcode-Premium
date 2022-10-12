Question Link: https://leetcode.com/problems/paint-house-iii/


// Approach :                                            
class Solution {
public:
    int memo[101][101][21];
    
    int solve(vector<int>& houses, int idx, int preColor, int neighbours, int target, vector<vector<int>>& cost){
        int n=cost.size(), m=cost[0].size();
        if(idx==n){
            if(neighbours!=target) return INT_MAX/2;
            return 0;    
        } 
        if(neighbours>target) return INT_MAX/2;
        
        if(memo[idx][neighbours][preColor]!=-1) return memo[idx][neighbours][preColor];
        
        int ans=INT_MAX/2;
        
        int color=houses[idx];
        if(color==0){
            for(int j=0;j<m;j++){
                int newPaint=cost[idx][j]+solve(houses,idx+1,j+1,(preColor==j+1 ? neighbours:neighbours+1),target,cost);
                ans=min(ans,newPaint);
            }
        }else{
            if(color==preColor){
                ans=min(ans,solve(houses,idx+1,preColor,neighbours,target,cost));
            }else{
                ans=min(ans,solve(houses,idx+1,color,neighbours+1,target,cost));
            }
        }
        return memo[idx][neighbours][preColor]=ans;
    } 
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(memo,-1,sizeof(memo));
        int ans=solve(houses,0,0,0,target,cost);
        return (ans<INT_MAX/2 ? ans:-1);
    }
};
