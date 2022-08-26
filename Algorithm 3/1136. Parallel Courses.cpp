Question Link: https://leetcode.com/problems/parallel-courses/

// Approach 1: Depth-First Search: Check for Cycles + Find Longest Path
class Solution {
public:
    
    bool hasCycle(vector<int> graph[], int src, vector<bool> &visited, vector<bool> &dfsVisited){
        visited[src]=true, dfsVisited[src]=true;
        
        for(int child:graph[src]){
            if(visited[child]==false){
                if(hasCycle(graph,child,visited,dfsVisited)) return true;
            }else{
                if(dfsVisited[child]==true) return true;
            }
        }
        dfsVisited[src]=false;
        return false;
    }
    
    int getLength(vector<int> graph[], int src, vector<int> &len){
        if(len[src]!=0) return len[src];
        
        int maxlen=1;
        for(int child:graph[src]){
            int curLen=getLength(graph,child,len);
            maxlen=max(maxlen,1+curLen);
        }
        return len[src]=maxlen;
    }
    
    int minimumSemesters(int n, vector<vector<int>> &edges) {
        vector<int> graph[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u-1].push_back(v-1);
        }
        
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                vector<bool> dfsVisited(n,false);
                if(hasCycle(graph,i,visited,dfsVisited)) return -1;
            }
        }
        
        vector<int> len(n,0);
        int ans=1;
        for(int i=0;i<n;i++){
            if(len[i]==0){
                int curLen=getLength(graph,i,len);
                ans=max(ans,curLen);
            }
        }
        return ans;
    }
};

// Approach 2: Topo-sort
class Solution {
public:
    
    int minimumSemesters(int n, vector<vector<int>> &edges) {
        vector<int> graph[n];
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u-1].push_back(v-1);
            indegree[v-1]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int c=0;
        while(q.size()>0){
            int size=q.size();
            n-=size;
            while(size--){
                int u=q.front();
                q.pop();
                
                for(int v:graph[u]){
                    indegree[v]--;
                    if(indegree[v]==0) q.push(v);
                }
            }
            c++;
        }
        return (n==0 ? c:-1);
    }
};
