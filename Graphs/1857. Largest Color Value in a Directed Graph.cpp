Question Link: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/


// Approach :                                            
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        
        vector<int> graph[n], indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        // consider longest path from 'src -> node' (so 'src' = node without parent) 
        // dp[node][color]: max. frequency of each color from all valid paths ending at 'node'
        vector<vector<int>> dp(n,vector<int>(26,0));
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                
                int c=colors[i]-'a';
                dp[i][c]++;
            }
        }
        
        int visited=0;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            
            visited++;
            
            for(int v:graph[u]){
                
                for(int c=0;c<26;c++){
                    dp[v][c] = max(dp[v][c], dp[u][c] + (c == colors[v]-'a'));
                }
                
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        
        if(visited<n) return -1;
        
        int ans=0;
        for(int node=0;node<n;node++){
            for(int c=0;c<26;c++) ans=max(ans,dp[node][c]);
        }
        return ans;
    }
};
