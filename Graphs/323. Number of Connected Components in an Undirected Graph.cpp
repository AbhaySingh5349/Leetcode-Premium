Question Link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/


// Approach 1: O(V+E)     

--> Building the adjacency :O(E) + During the DFS traversal, each vertex will only be visited once O(V)
                                     
class Solution {
public:
    
    void dfs(vector<int> graph[], int src, vector<bool> &visited){
        visited[src]=true;
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false){
                dfs(graph,child,visited);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> visited(n,false);
        
        int c=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                c++;
                dfs(graph,i,visited);
            }
        }
        return c;
    }
};


// Approach 2: O(E·a(n))

--> Iterating over every edge : O(E) + for every operation, we are performing combine method : O(a(n)), where a(n) is the inverse Ackermann function.

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
    
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> rk(n,1), parent(n,-1);
        for(int i=0;i<n;i++) parent[i]=i;
        
        int p=n;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            
            int pu=find(u,parent), pv=find(v,parent);
            if(pu!=pv){
                merge(pu,pv,rk,parent);
                p--;
            }
        }
        return p;
    }
};
