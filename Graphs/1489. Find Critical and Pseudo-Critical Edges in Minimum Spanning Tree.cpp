Question Link: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/


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
    
    int minimumCost(int n, vector<vector<int>>& edges, vector<int> include, vector<int> exclude) {
        vector<int> rk(n,1), parent(n,-1);
        for(int i=0;i<n;i++) parent[i]=i;
        
        int ans=0, groups=n;
        
        if(include[0] != -1){
            int u=include[0], v=include[1], cost=include[2];
            merge(find(u,parent),find(v,parent),rk,parent);
            ans += cost;
            groups--;
        }
        
        for(vector<int> edge:edges){
            if(edge == exclude) continue;
            
            int u=edge[0], v=edge[1], cost=edge[2];
            int pu=find(u,parent), pv=find(v,parent);
            if(pu!=pv){
                merge(pu,pv,rk,parent);
                ans += cost;
                groups--;
            }
        }
        return (groups==1 ? ans:INT_MAX/2);
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        map<vector<int>,int> mp;
        for(int i=0;i<edges.size();i++) mp[edges[i]]=i;
        
        sort(edges.begin(), edges.end(), compare);
        
        int minCost = minimumCost(n,edges,{-1,-1,-1},{-1,-1,-1});
        
        vector<int> critical, pseudo;
        
        for(vector<int> edge:edges){
            int excludeCost = minimumCost(n,edges,{-1,-1,-1},edge);
            if(excludeCost > minCost){
                critical.push_back(mp[edge]);
            }else{
                int includeCost = minimumCost(n,edges,edge,{-1,-1,-1});
                if(includeCost == minCost){
                    pseudo.push_back(mp[edge]);
                }
            }
        }
        
        return {critical,pseudo};
    }
};
