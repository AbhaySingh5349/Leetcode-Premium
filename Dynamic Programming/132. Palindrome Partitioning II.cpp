Question Link: https://leetcode.com/problems/palindrome-partitioning-ii/


// Approach 1:
class Solution {
public:
    
    int minCut(string s) {
        int n=s.length();
        
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(s[i]==s[j]) dp[i][j]=(j-i<2 || dp[i+1][j-1]);
            }
        }
        
        int count[n][n];
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(dp[i][j]){
                    count[i][j]=0;
                }else{
                    int cuts=n+1;
                    for(int k=i;k<j;k++){
                        int pre=count[i][k];
                        int suf=count[k+1][j];
                        
                        cuts = min(cuts,pre+suf+1);
                    }
                    count[i][j]=cuts;
                }
            }
        } 
        
        return count[0][n-1];
    }
};


// Approach 2:
class Solution {
public:
    
    int minCut(string s) {
        int n=s.length();
        
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(s[i]==s[j]) dp[i][j]=(j-i<2 || dp[i+1][j-1]);
            }
        }
        
        int count[n];
        for(int i=0;i<n;i++){
            if(dp[0][i]){
                count[i]=0;
            }else{
                count[i]=n-1;
                for(int j=0;j<=i;j++){
                    if(dp[j][i]){
                        count[i]=min(count[i],1+count[j-1]);
                    }
                }
            }
        }
        return count[n-1];
    }
};
