Question Link: https://leetcode.com/problems/path-with-maximum-probability/


// Approach 1:                                            
class Solution {
public:
    
    #define N 100001
    vector<pair<int,double>> graph[N];
    bool visited[N];
    double maxp=0.0;
    
    void dfs(int src, int dst, double &cur, double prev){
        cur*=prev;
        if(src==dst){
            if(cur>maxp) maxp=cur;
            cur/=prev;
            
            return;
        }
        visited[src]=true;
        for(int i=0;i<graph[src].size();i++){
            int v=graph[src][i].first;
            double p=graph[src][i].second;
            
            if(visited[v]==false) dfs(v,dst,cur,p);
        }
        cur/=prev;
        visited[src]=false;
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            
            graph[u].push_back({v,succProb[i]});
            graph[v].push_back({u,succProb[i]});
        }
        
        double cur=1.0;
        dfs(start,end,cur,1.0);
        
        return maxp;
    }
};


// Approach 2:
class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> graph[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            
            graph[u].push_back({v,succProb[i]});
            graph[v].push_back({u,succProb[i]});
        }
        
        vector<double> prob(n+1,0);
        prob[start]=1;
        
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        
        while(pq.size()>0){
            pair<double,int> pr = pq.top();
            pq.pop();
            
            double p=pr.first;
            int u=pr.second;
            
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i].first;
                double p=graph[u][i].second;
                
                if(prob[v]<prob[u]*p){
                    prob[v]=prob[u]*p;
                    pq.push({prob[v],v});
                }
            }
        }
        
        return prob[end];
    }
};
