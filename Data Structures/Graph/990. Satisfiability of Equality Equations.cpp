Question Link: https://leetcode.com/problems/satisfiability-of-equality-equations/


// Approach :                                            
class Solution {
public:
    
    int find(vector<int> &parent, int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent,parent[u]);
    }
    void merge(vector<int> &parent, vector<int> &rk, int pu, int pv){
        if(rk[pu]>=rk[pv]){
            rk[pu]+=rk[pv];
            parent[pu]=pv;
        }else{
            rk[pv]+=rk[pu];
            parent[pv]=pu;
        }
    }
    
    bool equationsPossible(vector<string>& v) {
        int n=v.size();
        
        vector<int> parent(26,0), rk(26,1);
        for(int i=0;i<26;i++) parent[i]=i;
        
        vector<pair<int,int>> dif;
        for(int i=0;i<n;i++){
            string s=v[i];
            int u=s[0]-'a', v=s[3]-'a';
            if(s[1]=='='){
                int pu=find(parent,u), pv=find(parent,v);
                if(pu!=pv) merge(parent,rk,pu,pv);
            }else{
                dif.push_back({u,v});
            }
        }
        for(int i=0;i<dif.size();i++){
            int u=dif[i].first, v=dif[i].second;
            int pu=find(parent,u), pv=find(parent,v);
            if(pu==pv) return false;
        }
        return true;
    }
};
