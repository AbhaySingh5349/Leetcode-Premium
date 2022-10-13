Question Link: https://leetcode.com/problems/redundant-connection/


// Approach 1:                                            
class Solution {
public:
    
    void dfs(vector<int> graph[], map<pair<int,int>,bool> &cycles, int src, int parent, vector<bool> &visited){
        visited[src]=true;
        for(int child:graph[src]){
            if(visited[child]==false){
                dfs(graph,cycles,child,src,visited);
            }else{
                if(child!=parent){
                    cycles[{src,child}]=true;
                    cycles[{child,src}]=true;
                }
            }
        }
    }
        
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> graph[n+1];
        
        for(int i=0;i<n;i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        map<pair<int,int>,bool> cycles;
        for(int i=1;i<=n;i++){
            vector<bool> visited(n,false);
            dfs(graph,cycles,i,-1,visited);
        }
        
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            pair<int,int> p={edges[i][0],edges[i][1]};
            if(cycles.find(p)!=cycles.end()){
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                break;
            }
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    
    int find(int u, vector<int> parent){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u],parent);
    }
    
    void merge(int pu, int pv, vector<int> &parent, vector<int> &rk){
        if(rk[pu]>rk[pv]){
            rk[pu]+=rk[pv];
            parent[pu]=pv;
        }else{
            rk[pv]+=rk[pu];
            parent[pv]=pu;
        }
    }
        
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        vector<int> parent(n+1), rk(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rk[i]=1;
        }
        
        for(int i=0;i<n;i++){
            int u=edges[i][0], v=edges[i][1];
            int pu=find(u,parent), pv=find(v,parent);
            
            if(pu!=pv){
                merge(pu,pv,parent,rk);
            }else{
                return edges[i];
            }
        } 
        return {}; 
    }
};
