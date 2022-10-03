Question Link: https://leetcode.com/problems/ugly-number-ii/


// Approach :
class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        dp[1]=1;
        int p2=1, p3=1, p5=1;
        
        for(int i=2;i<=n;i++){
            int c1=2*dp[p2];
            int c2=3*dp[p3];
            int c3=5*dp[p5];
            
            int cur=min(c1,min(c2,c3));
            dp[i]=cur;
            
            if(cur==c1) p2++;
            if(cur==c2) p3++;
            if(cur==c3) p5++;
        }
        
        return dp[n];
    }
};
