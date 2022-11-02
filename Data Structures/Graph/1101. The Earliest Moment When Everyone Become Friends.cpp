Question Link: https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/


// Approach :                                            
class Solution {
public:
    
    int find(int n, vector<int> &parent){
        if(parent[n]==n) return n;
        return parent[n]=find(parent[n],parent);
    }
    
    void merge(int u, int v, vector<int> &rk, vector<int> &parent){
        if(rk[u]>=rk[v]){
            rk[u]++;
            parent[v]=u;
        }else{
            rk[v]++;
            parent[u]=v;
        }
    }
    
    int earliestAcq(vector<vector<int>> &logs, int n) {
        sort(logs.begin(),logs.end());
        
        vector<int> rk(n,1), parent(n,-1);
        for(int i=0;i<n;i++) parent[i]=i;
        
        int groups=n;
        
        int time=-1;
        for(int i=0;i<logs.size();i++){
            int t=logs[i][0], u=logs[i][1], v=logs[i][2];
            
            int pu=find(u,parent), pv=find(v,parent);
            if(pu!=pv){
                merge(pu,pv,rk,parent);
                groups--;
                
                time = max(time,t);
            }
        }
        
        return (groups==1 ? time:-1);
    }
};
