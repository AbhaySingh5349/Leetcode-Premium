Question Link: https://leetcode.com/problems/course-schedule-ii/

// Approach 1:
class Solution {
public:
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> graph[n], indegree(n,0);
        
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
        vector<int> ans(n);
        while(q.size()>0){
            int src=q.front();
            q.pop();
            ans[c]=src;
            c++;
            
            for(int i=0;i<graph[src].size();i++){
                int child=graph[src][i];
                indegree[child]--;
                if(indegree[child]==0) q.push(child);
            }
        }
        if(c<n) return {};
        return ans; 
    }
};

// Approach 2:
class Solution {
public:
    
    bool hasCycle(vector<int> graph[], int src, int parent, vector<bool> &visited, vector<bool> &dfsVisited){
        visited[src]=true;
        dfsVisited[src]=true;
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false){
                if(hasCycle(graph,child,src,visited,dfsVisited)) return true;
            }else{
                if(dfsVisited[child]==true) return true;
            }
        }
        dfsVisited[src]=false;
        return false;
    }
    
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
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<bool> visited(n,false), dfsVisited(n,false);
        vector<int> graph[n];
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0], v=pre[i][1];
            graph[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(hasCycle(graph,i,-1,visited,dfsVisited)) return {};
            }
        }
        for(int i=0;i<n;i++) visited[i]=false;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(graph,i,visited,st);
            }
        }
        vector<int> ans;
        if(st.size()==n){
            while(st.size()>0){
                int x=st.top();
                st.pop();
                ans.push_back(x);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};
