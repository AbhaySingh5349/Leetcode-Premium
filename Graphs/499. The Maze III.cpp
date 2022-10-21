Question Link: https://leetcode.com/problems/the-maze-iii/


// Approach :                                            
class Solution {
public:
    
    struct node{
        int steps;
        string path;
        int i, j;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            if(a.steps == b.steps) return a.path > b.path;
            return a.steps > b.steps; // min. heap
        }
    };
    
    string findShortestWay(vector<vector<int>>& grid, vector<int>& start, vector<int>& destination) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>> steps(n,vector<int>(m,INT_MAX/2));
        steps[start[0]][start[1]]=0;
        
        priority_queue<node,vector<node>,compare> pq;
        pq.push({0,"",start[0],start[1]});
        
        int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        
        map<int,char> mp;
        mp[0]='u', mp[1]='r', mp[2]='d', mp[3]='l';
        
        while(pq.size()>0){
            struct node p=pq.top();
            pq.pop();
            
            int i=p.i, j=p.j, st=p.steps;
            string path=p.path;
            
            if(i==destination[0] && j==destination[1]) return path;
            
            for(int k=0;k<4;k++){
                int x=i+dxy[k][0], y=j+dxy[k][1];

                string new_path = path+mp[k];
                
                int c=0;
                bool found=false;
                while(x>=0 && y>=0 && x<n && y<m && grid[x][y]==0){
                    c++;
                    if(x==destination[0] && y==destination[1]){
                        found=true;
                        break;
                    }
                    x += dxy[k][0];
                    y += dxy[k][1];
                }
                
                if(found==false) x -= dxy[k][0], y -= dxy[k][1];
                
                if(x==i && y==j) continue;
                
                if(steps[x][y]>=c+st){
                    steps[x][y]=c+st;
                    pq.push({steps[x][y],new_path,x,y});
                }
            }
        }
        return "impossible";
    }
};
