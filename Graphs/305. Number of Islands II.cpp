Question Link: https://leetcode.com/problems/number-of-islands-ii/


// Approach 1:                                            
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
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
            
        vector<int> rk(n*m,1), parent(n*m,-1);
        
        int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        
        set<pair<int,int>> st;
        for(int k=0;k<positions.size();k++){
            int i=positions[k][0], j=positions[k][1];
            parent[i*n+j]=i*n+j;
            
            st.insert({i,j});
            
            for(int dir=0;dir<4;dir++){
                int x=i+dxy[dir][0], y=j+dxy[dir][1];
                
                if(x>=0 && y>=0 && x<m && y<n && st.find({x,y}) != st.end()){
                    int pu=find(i*n+j,parent), pv=find(x*n+y,parent);
                    if(pu!=pv) merge(pu,pv,rk,parent);
                }
            } 
            
            int c=0;
            for(int idx=0;idx<n*m;idx++) c += parent[idx]==idx;
            
            ans.push_back(c);
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    
    int find(int n, vector<int> &parent){
        if(parent[n]==n) return n;
        return parent[n]=find(parent[n],parent);
    }
    
    // merging incoming island with its neighbour
    void merge(int u, int v, vector<int> &rk, vector<int> &parent, int &c){
        c -= rk[v];
        rk[u]=0;
        parent[u]=v;
    }
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
            
        vector<int> rk(n*m,0), parent(n*m,-1);
        
        int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        
        set<pair<int,int>> st;
        int c=0;
        for(int k=0;k<positions.size();k++){
            int i=positions[k][0], j=positions[k][1];
            
            if(st.find({i,j}) == st.end()){
                c++;
                st.insert({i,j});
                
                int id=i*n+j;
                rk[id]=1, parent[id]=id;
            }
            
            for(int dir=0;dir<4;dir++){
                int x=i+dxy[dir][0], y=j+dxy[dir][1];
                
                if(x>=0 && y>=0 && x<m && y<n && st.find({x,y}) != st.end()){
                    int pu=find(i*n+j,parent), pv=find(x*n+y,parent);
                    if(pu!=pv) merge(pu,pv,rk,parent,c);
                }
            } 
            ans.push_back(c);
        }
        return ans;
    }
};
