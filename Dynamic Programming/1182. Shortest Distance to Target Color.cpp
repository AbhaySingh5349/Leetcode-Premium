Question Link: https://leetcode.com/problems/shortest-distance-to-target-color/


// Approach :
class Solution {
public:
    
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n=colors.size();
        
        vector<vector<int>> left(3, vector<int> (n,-1));
        for(int c=0;c<3;c++){
            for(int i=0;i<n;i++){
                int curColor=colors[i]-1;
                if(c==curColor){
                    left[c][i]=i;
                }else{
                    if(i>0) left[c][i]=left[c][i-1];
                }
            }
        }
        
        vector<vector<int>> right(3, vector<int> (n,n));
        for(int c=0;c<3;c++){
            for(int i=n-1;i>=0;i--){
                int curColor=colors[i]-1;
                if(c==curColor){
                    right[c][i]=i;
                }else{
                    if(i<n-1) right[c][i]=right[c][i+1];
                }
            }
        }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int idx=queries[i][0], c=queries[i][1]-1;
            
            int d=n+1;
            if(left[c][idx] != -1) d=min(d,idx-left[c][idx]);
            if(right[c][idx] != n) d=min(d,right[c][idx]-idx);
            
            ans.push_back((d==n+1 ? -1:d));
        }
        return ans;
    }
};
