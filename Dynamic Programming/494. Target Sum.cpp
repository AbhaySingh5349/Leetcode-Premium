Question Link: https://leetcode.com/problems/target-sum/


// Approach 1:
class Solution {
public:
    // add +ve n -ve signs is equivalent to dividing array in 2 subsets: s1+s2=sum, s1-s2=target
    int findTargetSumWays(vector<int>& a, int target) {
        int n=a.size();
        int sum=accumulate(a.begin(),a.end(),0);
        
        if(sum<target || (sum+target)%2==1) return 0;
        
        sum=abs(sum+target)/2;
        
        int dp[n+1][sum+1];
	    
	    for(int i=0;i<n+1;i++) dp[i][0]=1;
	    for(int j=1;j<sum+1;j++) dp[0][j]=0;
	    
	    for(int i=1;i<n+1;i++){
	        for(int j=0;j<sum+1;j++){
	            dp[i][j]=dp[i-1][j];
	            if(j>=a[i-1]) dp[i][j] += dp[i-1][j-a[i-1]];
	        }
	    }
        return dp[n][sum];
    }
};


// Approach 2:
class Solution {
public:
    // add +ve n -ve signs is equivalent to dividing array in 2 subsets: s1+s2=sum, s1-s2=target
    int findTargetSumWays(vector<int>& a, int target) {
        int n=a.size();
        int sum=accumulate(a.begin(),a.end(),0);
        
        if(sum<target || (sum+target)%2==1) return 0;
        
        sum=abs(sum+target)/2;
        
        vector<vector<int>> dp(2,vector<int> (sum+1,0));
        dp[0][0] = 1;
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                dp[i%2][j] = dp[!(i%2)][j];
                if(j>=a[i-1]) dp[i%2][j] += dp[!(i%2)][j-a[i-1]];
            }
        }
        
        return dp[n%2][sum]; 
    }
};


// Approach 3:
class Solution {
public:
    // add +ve n -ve signs is equivalent to dividing array in 2 subsets: s1+s2=sum, s1-s2=target
    int findTargetSumWays(vector<int>& a, int target) {
        int n=a.size();
        int sum=accumulate(a.begin(),a.end(),0);
        
        if(sum<target || (sum+target)%2==1) return 0;
        
        sum=abs(sum+target)/2;
        
        vector<int> dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=a[i];j<=k;j++){
                dp[j] += dp[j-a[i]];
            }
        }
        return dp[sum];
    }
};
