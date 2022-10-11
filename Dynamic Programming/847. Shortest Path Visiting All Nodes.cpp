Question Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/


// Approach :

Time complexity: O(2^N * N^2)
The total possible states that can be put in queue is O(2^N * N), because there are 2^N possibilities for mask, each of which can be paired with one of N nodes.

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) q.push({i, 1<<i});
        
        int final_state = (1<<n)-1;
        
        // reaching on a node with given state of earlier visited nodes
        vector<vector<bool>> visited(n,vector<bool>(final_state+1,false));
        
        int len=0;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                int src=q.front().first, state=q.front().second;
                q.pop();
                
                if(state == final_state) return len;
                
                for(int child : graph[src]){
                    int nxt_state = state | (1<<child);
                    if(visited[child][nxt_state] == false){
                        visited[child][nxt_state]=true;
                        q.push({child,nxt_state});
                    }
                }
            }
            len++;
        }
        return -1;
    }
};
