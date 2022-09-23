Question Link: https://leetcode.com/problems/paint-house-ii/

class Solution {
public:
    
    int minCostII(vector<vector<int>> &a) {
        int n=a.size(), k=a[0].size();
        
        int dp[n][k];
        for(int j=0;j<k;j++) dp[0][j]=a[0][j]; // painting 0th house with j colours
        
        for(int i=1;i<n;i++){
            for(int j=0;j<k;j++){
                int prevMinCost=INT_MAX;
                for(int prev=0;prev<k;prev++){
                    if(j==prev) continue;
                    prevMinCost = min(prevMinCost,dp[i-1][prev]);
                }
                dp[i][j]=a[i][j]+prevMinCost;
            }
        }
        
        int ans=INT_MAX;
        for(int j=0;j<k;j++) ans=min(ans,dp[n-1][j]);
        
        return ans; 
    }
};

// Approach 2:
class Solution {
public:
    
    // top 2 min values 
    void update(int val, int &min1, int &min2, int &c1, int &c2, int j){
        if(val<min1){
            min2=min1;
            c2=c1;
            min1=val;
            c1=j;
        }else if(val<min2){
            min2=val;
            c2=j;
        }
    }
    
    int minCostII(vector<vector<int>> &a) {
        int n=a.size(), k=a[0].size();
        
        int dp[n][k];
        int min1=INT_MAX, min2=INT_MAX, c1=-1, c2=-1;
        for(int j=0;j<k;j++){
            dp[0][j]=a[0][j];
            update(a[0][j],min1,min2,c1,c2,j);
        }
        
        for(int i=1;i<n;i++){
            int curmin1=INT_MAX, curmin2=INT_MAX, curc1=-1, curc2=-1;
            for(int j=0;j<k;j++){
                dp[i][j]=a[i][j] + (j==c1 ? min2:min1);
                update(dp[i][j],curmin1,curmin2,curc1,curc2,j);
            }
            min1=curmin1, min2=curmin2, c1=curc1, c2=curc2;
        }
        
        int ans=INT_MAX;
        for(int j=0;j<k;j++) ans=min(ans,dp[n-1][j]);
        
        return ans; 
    }
};
