Question Link: https://leetcode.com/problems/possible-bipartition/


// Approach : 
class Solution {
public:
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n+1];
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0], v=dislikes[i][1];
            graph[u].push_back(v), graph[v].push_back(u);
        }
        
        vector<int> color(n+1,-1);
        for(int i=1;i<n+1;i++){
            if(color[i]==-1){
                color[i]=0;
                
                queue<int> q;
                q.push(i);
                while(q.size()>0){
                    int parent=q.front();
                    q.pop();
                    
                    for(int child:graph[parent]){
                        if(color[child] == -1){
                            if(color[parent] == 0){
                                color[child]=1;
                            }else{
                                color[child]=0;
                            }
                            q.push(child);
                        }else{
                            if(color[child] == color[parent]) return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
