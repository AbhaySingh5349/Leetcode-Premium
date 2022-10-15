Question Link: https://leetcode.com/problems/minimum-height-trees/


// Approach 1:                                            
class Solution {
public:
    
    void dfs(vector<int> graph[], int src, int d, vector<bool> &visited, int &maxd, int &node){
        visited[src]=true;
        if(d>maxd){
            maxd=d;
            node=src;
        }
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false) dfs(graph,child,d+1,visited,maxd,node);
        }
    }
    
    void longestPath(vector<int> graph[], vector<bool> &visited, int src, int dst, vector<int> &cur, vector<int> &path){
        cur.push_back(src);
        if(src==dst){
            if(cur.size()>path.size()) path=cur;
            cur.pop_back();
            return;
        }
        visited[src]=true;
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false){
                longestPath(graph,visited,child,dst,cur,path);
            }
        }
        visited[src]=false;
        cur.pop_back();
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        
        if(n<2){
            for(int i=0;i<n;i++) ans.push_back(i);
            return ans;
        }
        
        vector<int> graph[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            
            graph[u].push_back(v), graph[v].push_back(u);
        }
        
        vector<bool> visited(n,false);
        int maxd=-1, node=-1;
        dfs(graph,1,0,visited,maxd,node);

        int src=node;
        for(int i=0;i<n;i++) visited[i]=false;
        
        maxd=-1, node=-1;
        dfs(graph,src,0,visited,maxd,node);
        int dst=node;

        for(int i=0;i<n;i++) visited[i]=false;
        
        vector<int> cur,path;
        longestPath(graph,visited,src,dst,cur,path);
        
        int size=path.size();
        
        ans.push_back(path[size/2]);
        if(size%2==0) ans.push_back(path[size/2 - 1]);
        
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        
        if(n<2){
            for(int i=0;i<n;i++) ans.push_back(i);
            return ans;
        }
        
        vector<int> graph[n], indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            
            graph[u].push_back(v), graph[v].push_back(u);
            indegree[v]++, indegree[u]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i]==1) q.push(i);
        
        int node=n;
        while(node>2){
            int size=q.size();
            node-=size;
            while(size--){
                int u=q.front();
                q.pop();

                for(int v : graph[u]){
                    indegree[v]--;
                    if(indegree[v]==1) q.push(v);
                }
            }
        }
        
        while(q.size()>0){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
