Question Link: https://leetcode.com/problems/number-of-distinct-islands/


// Approach :    
class Solution {
public:
    
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    map<int,string> mp;
    
    string computePath(vector<vector<int>>& grid, int i, int j, string direction){
        int n=grid.size(), m=grid[0].size();
        
        if(i<0 || j<0 || i==n || j==m || grid[i][j]==0) return "o";
        
        grid[i][j]=0;
        string path="";
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            
            path += computePath(grid,x,y,mp[k]);
        }
        
        return direction+path;
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        mp[0]="u", mp[1]="r", mp[2]="d", mp[3]="l";
        
        set<string> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    string path=computePath(grid,i,j,"x");
                    st.insert(path);
                }
            }
        }
        return (st.size());
    }
};
