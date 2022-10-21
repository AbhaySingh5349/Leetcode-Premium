Question Link: https://leetcode.com/problems/course-schedule-iv/


// Approach :                                            
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX/2));
        for(vector<int> edge:prerequisites){
            int u=edge[0], v=edge[1];
            distance[u][v]=1;
        }
        
        for(int i=0;i<n;i++) distance[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++) distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
        
        vector<bool> ans;
        for(vector<int> edge:queries){
            int u=edge[0], v=edge[1];
            ans.push_back((distance[u][v] < INT_MAX/2));
        }
        
        return ans;
    }
};
