Question Link: https://leetcode.com/problems/number-of-provinces/


// Approach :                                            
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
    
    int findCircleNum(vector<vector<int>> &grid) {
        int n=grid.size();
        
        vector<int> rk(n,1), parent(n,-1);
        for(int i=0;i<n;i++) parent[i]=i;
        
        int p=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j || grid[i][j]==0) continue;
                
                int pu=find(i,parent), pv=find(j,parent);
                if(pu!=pv){
                    merge(pu,pv,rk,parent);
                    p--;
                }
            }
        }
        return p;
    }
};
