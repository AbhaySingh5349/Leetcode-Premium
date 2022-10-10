Question Link: https://leetcode.com/problems/palindrome-partitioning-iii/


// Approach :
class Solution {
public:
    
    int replaceCount(string s, int i, int j){
        int n=s.length();
        
        if(i>j) return n+1;
        
        int c=0;
        while(i<j){
            if(s[i++] != s[j--]) c++;
        }
        return c;
    }
    
    vector<vector<vector<int>>> memo;
    int solve(string s, int i, int j, int k){
        int n=s.length();
        
        if(i>j){
            return n+1;
        }
        
        if(memo[i][j][k] != -1) return memo[i][j][k];
        
        if(j-i+1 == k) return memo[i][j][k]=0;
        if(j-i+1 < k) return memo[i][j][k]=n+1;
        
        if(k==1) return memo[i][j][k]=replaceCount(s,i,j);
        
        int ans=n+1;
        for(int idx=i;idx<=j;idx++){
            ans=min(ans,solve(s,i,idx,1) + solve(s,idx+1,j,k-1));
        }
        
        return memo[i][j][k]=ans;
    }
    
    int palindromePartition(string s, int k) {
        int n=s.length();
        
        memo.resize(n, vector<vector<int>>(n, vector<int> (k+1,-1)));
        
        return solve(s,0,n-1,k);
    }
};
