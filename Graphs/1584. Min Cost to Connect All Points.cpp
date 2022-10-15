Question Link: https://leetcode.com/problems/min-cost-to-connect-all-points/


// Approach 1:                                            
class Solution {
public:
    
    struct node{
        int dist;
        int id1, id2;
    };
    
    static bool compare(struct node &a, struct node &b){
        return a.dist < b.dist;
    }
    
    int find(vector<int> &parent, int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent,parent[u]);
    }
    
    void merge(vector<int> &parent, vector<int> &rk, int pu, int pv){
        if(rk[pu]>=rk[pv]){
            rk[pu]+=rk[pv];
            parent[pv]=pu;
        }else{
            rk[pv]+=rk[pu];
            parent[pu]=pv;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<2) return 0;
        
        vector<node> edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x1=points[i][0], y1=points[i][1];
                int x2=points[j][0], y2=points[j][1];
                int d=abs(x1-x2)+abs(y1-y2);
                
                struct node p={d,i,j};
                edges.push_back(p);
            }
        }
        
        sort(edges.begin(),edges.end(),compare);
        vector<int> parent(n), rk(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rk[i]=1;
        }
        
        int ans=0;
        for(int i=0;i<edges.size();i++){
            struct node p=edges[i];
            
            int u=p.id1, v=p.id2;
            int cost=p.dist;
            int pu=find(parent,u), pv=find(parent,v);
            if(pu!=pv){
                ans+=cost;
                merge(parent,rk,pu,pv);
            }
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<2) return 0;
        
        vector<pair<int,int>> graph[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x1=points[i][0], y1=points[i][1];
                int x2=points[j][0], y2=points[j][1];
                int d=abs(x1-x2)+abs(y1-y2);
                
                graph[i].push_back({d,j}), graph[j].push_back({d,i});
            }
        }
        
        set<int> visited;
        visited.insert(0);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto p:graph[0]){
            int wt=p.first, idx=p.second;
            pq.push({wt,idx});
        }
        
        int ans=0;
        
        while(visited.size()!=n && pq.size()>0){
            auto p=pq.top();
            pq.pop();
            
            int wt=p.first, idx=p.second;
            if(visited.find(idx)==visited.end()){
                ans += wt;
                visited.insert(idx);
                
                for(auto cur:graph[idx]) pq.push({cur.first,cur.second});
            }
        }
        return ans;
    }
};
