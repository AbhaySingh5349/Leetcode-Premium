Question Link: https://leetcode.com/problems/find-a-peak-element-ii/

class Solution {
public:
    
    int getMaxElementIdxOfRow(vector<vector<int>>& grid, int row){
        int idx=0;
        for(int j=1;j<grid[row].size();j++){
            if(grid[row][j] > grid[row][idx]) idx=j;
        }
        return idx;
    }
    
    bool isPeak(vector<vector<int>>& grid, int i, int j){
        int n=grid.size(), m=grid[0].size();
        
        int up=(i>0 ? grid[i-1][j]:-1);
        int down=(i<n-1 ? grid[i+1][j]:-1);
        
        if(grid[i][j]>up && grid[i][j]>down) return true;
        return false;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(n==1 && m==1) return {0,0};
        
        int rowmin=0, rowmax=n-1;
        while(rowmin <= rowmax){
            int row = (rowmax+rowmin)/2;
            
            int idx = getMaxElementIdxOfRow(grid, row);
            
            if(isPeak(grid, row, idx)) return {row,idx};
            
            if(row>0 && grid[row-1][idx] > grid[row][idx]){
                rowmax=row-1;
            }else{
                rowmin=row+1;
            }
        }
        return {-1,-1};
    }
};
