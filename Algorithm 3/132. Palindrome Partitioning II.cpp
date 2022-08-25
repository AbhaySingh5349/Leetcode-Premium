Question Link: https://leetcode.com/problems/palindrome-partitioning-ii/

// Approach 1: O(2^N) where N is the length of string s.

--> 2^N in complexity is the number of nodes in the search tree (not the number of substrings)
    a string with sequence of N chars can have max. N-1 partitions
    If you want the partitioning to have 'R' substrings, then you can ask, "how many ways can I select 'R' partitions out of the 'N-1' partitions?" => (n-1)C(r)
    In general a string of length n will have: (n-1)C(0) + (n-1)C(1) + ... + (n-1)C(n-2) = 2^(n-1) = O(2^n) partitionings
    
eg. If you want the partitioning to have 4 substrings from "abcde", then you can ask, "how many ways can I select 3 pipes out of the 4 partitions?"
    answer is 4 choose 3, i.e. 4C3 = 4. The 4 ways to partition are: { {"a", "b", "c", "de"}, {"a", "b", "cd", "e"}, {"a", "bc", "d", "e"}, {"ab", "c", "d", "e"}

class Solution {
public:
    
    vector<vector<bool>> dp;
    
    int solve(string s, int idx){
        int n=s.length();
        if(idx==n) return -1; // because we added '+1' in previous call even when there was nothing to divide in end
        
        int ans=n-1;
        for(int i=idx;i<n;i++){
            if(dp[idx][i]==true){
                ans = min(ans,1+solve(s,i+1));
            }
        }
        return ans;
    }
    
    int minCut(string s) {
        int n=s.length();
        
        dp.resize(n,vector<bool> (n,false));
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                
                if(s[i]==s[j]) dp[i][j] = (j-i<2 || dp[i+1][j-1]);
            }
        }
        
        return solve(s,0);
    }
};
