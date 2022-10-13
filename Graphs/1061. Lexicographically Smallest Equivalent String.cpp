Question Link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/


// Approach :                                            
class Solution {
public:
    
    int find(int n, vector<int> &parent){
        if(parent[n]==n) return n;
        return parent[n]=find(parent[n],parent);
    }
    
    void merge(int u, int v, vector<int> &parent){
        parent[u]=min(parent[u],parent[v]);
        parent[v]=parent[u];
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for(int i=0;i<26;i++) parent[i]=i;
        
        int n=s1.length();
        for(int i=0;i<n;i++){
            int u=s1[i]-'a', v=s2[i]-'a';
            int pu=find(u,parent), pv=find(v,parent);
            if(pu!=pv) merge(pu,pv,parent);
        }
        
        string ans="";
        for(int i=0;i<baseStr.length();i++){
            int pu=find(baseStr[i]-'a',parent);
            ans += (char)(pu+'a');
        }
        return ans;
    }
};
