Question Link: https://leetcode.com/problems/knight-probability-in-chessboard/


// Approach 1:
class Solution {
public:
    
    double memo[26][26][101];
    int dxy[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    
    double prob(int n, int k, int r, int c){
        if(memo[r][c][k]!=0) return memo[r][c][k];
        
        if(k==0) return 1;
        
        double ans=0;
        for(int d=0;d<8;d++){
            int x=r+dxy[d][0], y=c+dxy[d][1];
            
            if(x>=0 && y>=0 && x<n && y<n) ans+=0.125*prob(n,k-1,x,y);
        }
        return memo[r][c][k]=ans;
    }
    
    double knightProbability(int n, int k, int r, int c) {
       return prob(n,k,r,c);
    }
};


// Approach 2:
class Solution {
public:
    
    double knightProbability(int n, int k, int r, int c) {
        double dp[26][26][101];
        dp[r][c][0]=1;
        
        for(int steps=1;steps<k+1;steps++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int d=0;d<8;d++){
                        int x=i+dxy[d][0];
                        int y=j+dxy[d][1];

                        if(x>=0 && y>=0 && x<n && y<n){
                            dp[i][j][steps]+=0.125*dp[x][y][steps-1];
                        }
                    }
                }
            }
        }
        double ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=dp[i][j][k];
            }
        }
        return ans; 
    }
};
