Question Link: https://leetcode.com/problems/jump-game-iv/


// Approach : O(N)     
class Solution {
public:
    int minJumps(vector<int>& a) {
        int n=a.size();
        if(n==1) return 0;
        
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[a[i]].push_back(i);
        }
        
        vector<bool> visited(n,false);
        
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int steps=0;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                int i=q.front();
                q.pop();
                
                if(i==n-1) return steps;
                
                int pos1=i+1;
                if(pos1<n && visited[pos1]==false){
                    q.push(pos1);
                    visited[pos1]=true;
                }
                int pos2=i-1;
                if(pos2>=0 && visited[pos2]==false){
                    q.push(pos2);
                    visited[pos2]=true;
                }
                
                if(mp.find(a[i]) == mp.end()) continue;
                
                vector<int> v=mp[a[i]];
                for(int j=0;j<v.size();j++){
                    if(v[j]==i) continue;
                    if(visited[v[j]]==false){
                        visited[v[j]]=true;
                        q.push(v[j]);
                    }
                }
                mp.erase(a[i]);
            }
            if(q.size()>0) steps++;
        }
        return steps; 
    }
};
