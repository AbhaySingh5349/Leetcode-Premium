Question Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    
    int find(vector<int> &parent, int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent,parent[u]);
    }
    
    void merge(vector<int> &parent, vector<int> &rk, int pu, int pv){
        if(rk[pu]>=rk[pv]){
            rk[pu]+=rk[pv];
            parent[pv]=pu;
        }else{
            rk[pv]+=rk[pu];
            parent[pu]=pv;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& edges) {
        if(edges.size()<n-1) return -1;
        
        vector<int> parent(n), rk(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rk[i]=1;
        }
        
        int cc=n;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            int pu=find(parent,u), pv=find(parent,v);
            
            if(pu!=pv){
                cc--;
                merge(parent,rk,pu,pv);
            }
        }
        
        return (cc-1);
    }
};
