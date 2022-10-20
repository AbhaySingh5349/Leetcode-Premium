Question Link: https://leetcode.com/problems/the-maze-ii/


// Approach :                                            
class Solution {
public:
    
    struct node{
        int steps;
        int i, j;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.steps > b.steps; // min. heap
        }
    };
    
    int shortestDistance(vector<vector<int>>& grid, vector<int>& start, vector<int>& destination) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>> steps(n,vector<int>(m,INT_MAX/2));
        steps[start[0]][start[1]]=0;
        
        priority_queue<node,vector<node>,compare> pq;
        pq.push({0,start[0],start[1]});
        
        int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        while(pq.size()>0){
            struct node p=pq.top();
            pq.pop();
            
            int i=p.i, j=p.j, st=p.steps;
            
            if(i==destination[0] && j==destination[1]) return st;
            
            for(int k=0;k<4;k++){
                int x=i+dxy[k][0], y=j+dxy[k][1];

                int c=0;
                while(x>=0 && y>=0 && x<n && y<m && grid[x][y]==0){
                    c++;
                    x += dxy[k][0];
                    y += dxy[k][1];
                }
                
                x -= dxy[k][0], y -= dxy[k][1];
                if(steps[x][y]>c+st){
                    steps[x][y]=c+st;
                    pq.push({steps[x][y],x,y});
                }
            }
        }
        return -1;
    }
};
