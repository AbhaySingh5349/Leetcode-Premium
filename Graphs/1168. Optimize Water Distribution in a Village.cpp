Question Link: https://leetcode.com/problems/optimize-water-distribution-in-a-village/


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
    
    int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes) {
        vector<vector<int>> graph;
        
        for(int i=0;i<wells.size();i++){
            int u=0, v=i+1, cost=wells[i];
            graph.push_back({cost,u,v});
        }
        
        for(int i=0;i<pipes.size();i++){
            int u=pipes[i][0], v=pipes[i][1], cost=pipes[i][2];
            graph.push_back({cost,u,v});
        }
        
        sort(graph.begin(),graph.end());
        
        vector<int> rk(n+1,1), parent(n+1,-1);
        for(int i=0;i<n+1;i++) parent[i]=i;
        
        
        int ans=0;
        for(int i=0;i<graph.size();i++){
            int cost=graph[i][0], u=graph[i][1], v=graph[i][2];
            
            int pu=find(u,parent), pv=find(v,parent);
            if(pu!=pv){
                ans += cost;
                merge(pu,pv,rk,parent);
            }
        }
        
        return ans;
    }
};
