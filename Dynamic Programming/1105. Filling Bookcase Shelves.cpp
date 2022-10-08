Question Link: https://leetcode.com/problems/filling-bookcase-shelves/


// Approach :
class Solution {
public:
    
    vector<vector<int>> memo;
    
    int solve(vector<vector<int>>& books, int n, int shelfWidth, int idx, int remaining, int maxh){
        
        if(idx==n) return maxh;
        
        if(memo[idx][remaining]!=-1) return memo[idx][remaining];
        
        int w=books[idx][0], h=books[idx][1];
        
        // put on next level
        int ans=solve(books,n,shelfWidth,idx+1,shelfWidth-w,h)+maxh;
        
        // put on current level
        if(w<=remaining) ans=min(ans,solve(books,n,shelfWidth,idx+1,remaining-w,max(h,maxh)));
        
        return memo[idx][remaining]=ans;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        memo.resize(n,vector<int>(shelfWidth+1,-1));
        
        return solve(books,n,shelfWidth,0,shelfWidth,0);
    }
};
