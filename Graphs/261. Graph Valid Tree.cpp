Question Link: https://leetcode.com/problems/graph-valid-tree/


// Approach 1:                                            
class Solution {
public:
    
    bool cycle(vector<int> graph[], int src, int par, vector<bool> &visited){
        visited[src]=true;
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false){
                if(cycle(graph,child,src,visited)) return true;
            }else{
                if(child!=par) return true;
            }
        }
        return false;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> visited(n,false);
        
        if(cycle(graph,0,-1,visited)) return false;
        
        // more than 1 group exists
        for(int i=0;i<n;i++) if(visited[i]==false) return false;
        
        return true;
    }
};


// Approach 2:
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
    
    bool validTree(int n, vector<vector<int>> &edges) {
        
        vector<int> rk(n,1), parent(n,-1);
        for(int i=0;i<n;i++) parent[i]=i;
        
        int p=n;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            
            int pu=find(u,parent), pv=find(v,parent);
            if(pu!=pv){
                merge(pu,pv,rk,parent);
                p--;
            }else{
                return false; // cycle exists
            }
        }
        return (p==1);
    }
};
