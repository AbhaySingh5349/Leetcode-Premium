Question Link: https://leetcode.com/problems/swim-in-rising-water/


// Approach 1:                                            
class Solution {
public:
    
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    bool possible(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited, int maxval){
        int n=grid.size(), m=grid[0].size();
        if(i<0 || j<0 || i==n || j==m || visited[i][j]==true || grid[i][j]>maxval) return false;
        
        if(i==n-1 && j==m-1) return true;
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            if(possible(grid,x,y,visited,maxval)) return true;
        }
        return false;
    } 
    
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        int l=INT_MAX, r=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) r=max(r,grid[i][j]), l=min(l,grid[i][j]);
        }
        while(l<r){
            int m=l+(r-l)/2;
            vector<vector<bool>> visited(n,vector<bool>(m,false));
            if(possible(grid,0,0,visited,m)){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l; 
    }
};


// Approach 2:
class Solution {
public:
    
    struct node{
        int u;
        int v;
        int wt;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.wt>b.wt;
        }
    }; 
    
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        priority_queue<node,vector<node>,compare> pq;
        pq.push({0,0,grid[0][0]});
        vector<vector<int>> visited(n,vector<int>(m,n*n));
        while(pq.size()>0){
            struct node p=pq.top();
            pq.pop();
            
            int i=p.u, j=p.v, w=p.wt;
            if(i==n-1 && j==m-1) return max(w,grid[n-1][m-1]);
            
            for(int k=0;k<4;k++){
                int x=i+dxy[k][0], y=j+dxy[k][1];
                if(x>=0 &&y>=0 && x<n && y<m && visited[x][y]>w){
                    visited[x][y]=max(w,grid[x][y]);
                    pq.push({x,y,max(w,grid[x][y])});
                }
            }
        }
        return -1; 
    }
};
