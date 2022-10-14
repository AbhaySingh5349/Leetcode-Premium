Question Link: https://leetcode.com/problems/similar-string-groups/


// Approach 1:                                            
class Solution {
public: 
    
    int find(int u, vector<int> &parent){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u],parent);
    }
    
    void merge(int pu, int pv, vector<int> &parent, vector<int> &rk){
        if(rk[pu]>rk[pv]){
            rk[pu]+=rk[pv];
            parent[pv]=pu;
        }else{
            rk[pv]+=rk[pu];
            parent[pu]=pv;
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        
        vector<int> parent(n), rk(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
        
        map<string,int> mp;
        int mergedCount=n;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mp.find(email)==mp.end()){
                    mp[email]=i;
                }else{
                    int u=mp[email], v=i;
                    int pu=find(u,parent), pv=find(v,parent);
                    if(pu!=pv){
                        merge(pu,pv,parent,rk);
                        mergedCount--;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++) cout<<parent[i]<<" ";
        
        vector<vector<string>> ans(mergedCount);
        map<string,int> :: iterator it;
        int newGroup=0;
        map<int,int> id;
        for(it=mp.begin();it!=mp.end();it++){
            string email=it->first;
            int idx=it->second;
            
            int groupId=find(idx,parent);
            
            if(id.find(groupId)!=id.end()){
                int ansIdx=id[groupId];
                ans[ansIdx].push_back(email);
            }else{
                string name=accounts[groupId][0];
                ans[newGroup].push_back(name);
                ans[newGroup].push_back(email);
                id[groupId]=newGroup++;
            }
        }
        
        for(int i=0;i<mergedCount;i++){
            vector<string> v=ans[i];
            sort(v.begin()+1,v.end());
            ans[i]=v;
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    
    bool isSimilar(string s1, string s2){
        int c=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) c++;
        }
        return (c<=2);
    }
    
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
    
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<int> rk(n,1), parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i], strs[j])){
                    int pu=find(i,parent), pv=find(j,parent);
                    if(pu!=pv) merge(pu,pv,rk,parent);
                }
            }
        }
        
        int c=0;
        
        for(int i=0;i<n;i++) c += (parent[i] == i);
        
        return c;
    }
};
