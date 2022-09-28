Question Link: https://leetcode.com/problems/number-of-corner-rectangles/


// Approach 1:
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans= 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if (grid[i][j] == 0) continue;

                for(int p=i+1;p<n;p++) {
                    for(int q=j+1;q<m;q++) {
                        if(grid[p][q] == 0) continue;
                        
                        ans += grid[i][q] & grid[p][j];
                    }
                }
            }
        }

        return ans;
    }
};


// Approach 2:
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans= 0;
        
        for(int i=0;i<n;i++){
            for(int p=i+1;p<n;p++){
                int c=0;
                for(int k=0;k<m;k++) c += grid[i][k] & grid[p][k];
                
                ans += (c*(c-1))/2;
            }
        }

        return ans;
    }
};
