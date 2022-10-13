Question Link: https://leetcode.com/problems/redundant-connection-ii/


// Approach :                                            
class Solution {
public: 
    
    int find(int u, vector<int> parent){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u],parent);
    }
    
    void merge(int pu, int pv, vector<int> &parent, vector<int> &rk){
        if(rk[pu]>rk[pv]){
            rk[pu]+=rk[pv];
            parent[pv]=pu;
        }else{
            rk[pv]+=rk[pu];
            parent[pu]=pv;
        }
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        vector<int> indegree(n+1,-1);
        int e1=-1, e2=-1;
        for(int i=0;i<n;i++){
            int u=edges[i][0], v=edges[i][1];
            
            if(indegree[v]==-1){
                indegree[v]=i;
            }else{
                e1=i;
                e2=indegree[v];
                break;
            }
        }
        
        vector<int> parent(n+1), rk(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rk[i]=1;
        }
        for(int i=0;i<n;i++){
            if(i==e1) continue; // we check if without this cycle exists or not
            
            int u=edges[i][0], v=edges[i][1];
            int pu=find(u,parent), pv=find(v,parent);
            if(pu!=pv){
                merge(pu,pv,parent,rk);
            }else{
                if(e1==-1) return edges[i]; // indegree never became 2
                return edges[e2];
            }
        }
        return edges[e1];; 
    }
};
