Question Link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/


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
    
    static bool compare(const vector<int> &a, const vector<int> &b){
        return a[2]<b[2];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int> rk(n,1), parent(n,-1);
        for(int i=0;i<n;i++) parent[i]=i;
        
        // sorting queries on basis of [limit] so that only nodes with edge wt < limit are grouped
        for(int i=0;i<queries.size();i++) queries[i].push_back(i);
        sort(queries.begin(),queries.end(),compare);
        
        sort(edges.begin(),edges.end(),compare);
        
        int m=queries.size();
        vector<bool> ans(m);
        
        int edge_idx=0;
        for(vector<int> q:queries){
            int q_u=q[0], q_v=q[1], q_wt=q[2], q_idx=q[3];
            
            while(edge_idx<edges.size() && edges[edge_idx][2]<q_wt){
                int u=edges[edge_idx][0], v=edges[edge_idx][1];
                int pu=find(u,parent), pv=find(v,parent);
                if(pu != pv) merge(pu,pv,rk,parent);
                edge_idx++;
            }
            
            ans[q_idx]= (find(q_u,parent)==find(q_v,parent));
        }
        return ans;
    }
};
