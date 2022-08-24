Question Link: https://leetcode.com/problems/maximal-square/

class Solution {
public:
    
    int dxy[3][2]={{0,1},{1,1},{1,0}};
    
    int getSide(vector<vector<char>>& grid, int n, int m, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0'){
            return 0;
        }
        int ans=max(n,m);
        for(int k=0;k<3;k++){
            int x=i+dxy[k][0];
            int y=j+dxy[k][1];
            ans=min(ans,getSide(grid,n,m,x,y));
        } 
        return ans+1;
    }
    int maximalSquare(vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans=max(ans,getSide(grid,n,m,i,j));
                }
            }
        }
        return ans*ans;
    }
};
