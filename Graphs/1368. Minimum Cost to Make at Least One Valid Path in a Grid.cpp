Question Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/


// Approach :                                            
class Solution {
public:
    
    struct node{
        int cost;
        int i, j;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.cost > b.cost; // min. heap
        }
    };
    
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int dxy[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        
        vector<vector<int>> cost(n,vector<int>(m,n*m+1));
        cost[0][0]=0;
        
        priority_queue<node,vector<node>,compare> pq;
        pq.push({0,0,0});
        while(pq.size()>0){
            struct node p = pq.top();
            pq.pop();
            
            int i=p.i, j=p.j;
            
            if(i==n-1 && j==m-1){
                return p.cost;
            } 
            for(int k=0;k<4;k++){
                int x=i+dxy[k][0], y=j+dxy[k][1];
                if(x>=0 && y>=0 && x<n && y<m){
                    int dir=k+1;
                    if(dir==grid[i][j] && cost[x][y]>cost[i][j]){
                        cost[x][y]=cost[i][j];
                        pq.push({cost[x][y],x,y});
                    }else if(cost[i][j]+1<cost[x][y]){
                        cost[x][y]=cost[i][j]+1;
                        pq.push({cost[x][y],x,y});
                    }
                }
            }
        }
        return -1; 
    }
};
