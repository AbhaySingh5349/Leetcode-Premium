Question Link: https://leetcode.com/problems/smallest-string-with-swaps/


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
    
    string smallestStringWithSwaps(string s, vector<vector<int>> &edges) {
        
        int n=s.length();
        
        vector<int> rk(n,1), parent(n,-1);
        for(int i=0;i<n;i++) parent[i]=i;
        
        set<int> st; // keep track of index that can be swapped
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            
            int pu=find(u,parent), pv=find(v,parent);
            if(pu!=pv) merge(pu,pv,rk,parent);
            
            st.insert(u), st.insert(v);
        }
        
        map<int,vector<char>> character;
        map<int,vector<int>> index;
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end()) continue;
            
            int par=find(i,parent);
            character[par].push_back(s[i]);
            index[par].push_back(i);
        }
        
        map<int,vector<char>> :: iterator it;
        for(it=character.begin();it!=character.end();it++){
            int par=it->first;
            
            vector<char> v=character[par];
            vector<int> id=index[par];
            
            sort(v.begin(),v.end());
            sort(id.begin(),id.end());
            
            for(int i=0;i<v.size();i++){
                char ch=v[i];
                int idx=id[i];
                
                s[idx]=ch;
            }
        }
        return s;
    }
};
