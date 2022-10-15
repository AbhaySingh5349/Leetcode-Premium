Question Link: https://leetcode.com/problems/connecting-cities-with-minimum-cost/


// Approach :                                            
class Solution {
public:
    
    int find(int n, vector<int> &parent){
        if(parent[n]==n) return n;
        return parent[n]=find(parent[n],parent);
    }
    
    void merge(int u, int v, vector<int> &rk, vector<int> &parent){
        if(rk[u]>=rk[v]){
            rk[u] += rk[v];
            rk[v]=0;
            parent[v]=u;
        }else{
            rk[v] +=rk[u];
            rk[u]=0;
            parent[u]=v;
        }
    }
    
    static bool compare(const vector<int> &a, const vector<int> &b){
        return (a[2]<b[2]);
    }
    
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), compare);
        
        vector<int> rk(n+1,1), parent(n+1,-1);
        for(int i=1;i<n+1;i++) parent[i]=i;
        
        int ans=0;
        int groups=n;
        for(vector<int> edge:connections){
            int u=edge[0], v=edge[1], cost=edge[2];
            int pu=find(u,parent), pv=find(v,parent);
            if(pu!=pv){
                merge(pu,pv,rk,parent);
                ans += cost;
                groups--;
            }
        }
        return (groups==1 ? ans:-1);
    }
};
