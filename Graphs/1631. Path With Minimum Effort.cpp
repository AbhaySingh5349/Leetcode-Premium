Question Link: https://leetcode.com/problems/path-with-minimum-effort/


// Approach 1:                                            
class Solution {
public:
    
    bool isPossible(vector<vector<int>>& heights, int mid){
        int n=heights.size(), m=heights[0].size();
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
        bool visited[n][m];
        memset(visited,false,sizeof(visited));
        
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=true;
        
        while(q.size()>0){
            pair<int,int> t=q.front();
            q.pop();
            int i=t.first, j=t.second;
            
            if(i==n-1 && j==m-1) return true;
            
            for(int k=0;k<4;k++){
                int x=dx[k]+i, y=dy[k]+j;
                
                if(x>=0 && y>=0 && x<n && y<m && visited[x][y]==false){
                    int maxEfforts = abs(heights[i][j]-heights[x][y]);
                    
                    if(maxEfforts<=mid){
                        q.push({x,y});
                        visited[x][y]=true;
                    }
                }
            }
        }
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int left=0;
        int right=1e6;
        
        while(left<right){
            int mid=left+(right-left)/2;
            if(isPossible(heights,mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};


// Approach 2:
class Solution {
public:
    
    struct node{
        int efforts;
        int i, j;
    };
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.efforts > b.efforts;
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=0;
        
        int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        
        priority_queue<node,vector<node>,compare> pq;
        pq.push({0,0,0});
        
        while(pq.size()>0){
            struct node p=pq.top();
            pq.pop();
            int efforts=p.efforts, i=p.i, j=p.j;
            
            if(i==n-1 && j==m-1) return efforts;
            
            for(int k=0;k<4;k++){
                int x=dxy[k][0]+i, y=dxy[k][1]+j;
                
                if(x>=0 && y>=0 && x<n && y<m){
                    int maxEfforts = max(abs(heights[i][j]-heights[x][y]),efforts);
                    
                    if(maxEfforts<dp[x][y]){
                        pq.push({maxEfforts,x,y});
                        dp[x][y]=maxEfforts;
                    }
                }
            }
        }
        return 0;
    }
};


// Approach 3:
class Solution {
public:
    
    int find(int n, vector<int> &parent){
        if(parent[n]==n) return n;
        return parent[n]=find(parent[n],parent);
    }
    
    void merge(int u, int v, vector<int> &rk, vector<int> &parent){
        if(rk[u]>=rk[v]){
            rk[u]++;
            parent[v]=u;
        }else{
            rk[v]++;
            parent[u]=v;
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        
        vector<int> parent(n*m), rk(n*m,1);
        for(int i=0;i<n*m;i++) parent[i]=i;
        
        int dxy[2][2]={{0,1},{1,0}};
        
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int u=i*m+j;
                
                for(int k=0;k<2;k++){
                    int x=i+dxy[k][0], y=j+dxy[k][1];
                    
                    if(x>=0 && y>=0 && x<n && y<m){
                        int v=x*m+y;
                        
                        int efforts=abs(heights[i][j]-heights[x][y]);
                        edges.push_back({efforts,u,v});
                    }
                }
            }
        }
        
        sort(edges.begin(),edges.end());
        
        for(vector<int> edge:edges){
            int efforts=edge[0], u=edge[1], v=edge[2];
            
            merge(find(u,parent),find(v,parent),rk,parent);
            
            if(find(0,parent) == find(n*m-1,parent)) return efforts;
        }
        return 0;
    }
};
