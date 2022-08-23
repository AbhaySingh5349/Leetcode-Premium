Question Link: https://leetcode.com/problems/kill-process/

class Solution {
public:
    vector<int> killProcess(vector<int>& id, vector<int>& pid, int kill) {
        map<int,vector<int>> mp; // parent --> childrens
        for(int i=0;i<id.size();i++){
            int p=pid[i], c=id[i];
            mp[p].push_back(c);
        }
        
        queue<int> q;
        q.push(kill);
        
        vector<int> ans;
        while(q.size()){
            int p=q.front();
            q.pop();
            
            ans.push_back(p);
            
            for(int c:mp[p]) q.push(c);
        }
        return ans;
    }
};
