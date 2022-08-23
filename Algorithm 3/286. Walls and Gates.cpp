Question Link: https://leetcode.com/problems/walls-and-gates/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }
        
        int dxy[4][2]={{-1,0}, {0,1}, {1,0}, {0,-1}};
        int d=1;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                int i=q.front().first, j=q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++){
                    int ni=i+dxy[k][0], nj=j+dxy[k][1];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]>d){
                        q.push({ni,nj});
                        grid[ni][nj] = d;
                    }
                }
            }
            d++;
        }
    }
};
