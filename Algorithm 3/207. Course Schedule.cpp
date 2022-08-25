Question Link: https://leetcode.com/problems/course-schedule/

// Approach 1: (Topo-sort)
class Solution {
public:
    
    void dfs(vector<int> graph[], int src, vector<bool> &visited, stack<int> &st){
        visited[src]=true;
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false){
                dfs(graph,child,visited,st);
            }
        }
        st.push(src);
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool> visited(n,false);
        vector<int> graph[n], indegree(n,0);
        
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0], v=pre[i][1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        
        stack<int> st;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(graph,i,visited,st);
            }
        }
        return (st.size()==n);
    }
};

// Approach 2: (Topo-sort)
class Solution {
public:
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool> visited(n,false);
        vector<int> graph[n];
        vector<int> indegree(n,0);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0], v=pre[i][1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int c=0;
        while(q.size()>0){
            int src=q.front();
            q.pop();
            c++;
            
            for(int i=0;i<graph[src].size();i++){
                int child=graph[src][i];
                indegree[child]--;
                if(indegree[child]==0) q.push(child);
            }
        }
        return (c==n);
    }
};

// Approach 3: (cycle detection in directed graph)
class Solution {
public:
    
    bool hasCycle(vector<int> graph[], int src, vector<bool> &visited, vector<bool> &dfsVisited){
        visited[src]=true, dfsVisited[src]=true;
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false){
                if(hasCycle(graph,child,visited,dfsVisited)) return true;
            }else{
                if(dfsVisited[child]) return true;
            }
        }
        dfsVisited[src]=false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool> visited(n,false), dfsVisited(n,false);
        vector<int> graph[n];
        
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0], v=pre[i][1];
            graph[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(hasCycle(graph,i,visited,dfsVisited)) return false;
            }
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};
