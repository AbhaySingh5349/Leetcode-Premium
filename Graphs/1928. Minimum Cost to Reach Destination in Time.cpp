Question Link: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/


// Approach :                                            
class Solution {
public:
    struct path{
        int cost;
        int node;
        int time;
    };
    
    struct compare{
        bool operator()(path p1, path p2){
            return p1.cost>p2.cost;
        }
    };
   
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n=fees.size();
        
        vector<pair<int,int>> graph[n];
        int totalTime=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1], time=edges[i][2];
            graph[u].push_back({v,time});
            graph[v].push_back({u,time});
        }
        
        priority_queue<path,vector<path>,compare> pq;
        path p={fees[0],0,0};
        pq.push(p);
        
        vector<int> amount(n,INT_MAX), timeTaken(n,INT_MAX);
        amount[0]=fees[0], timeTaken[0]=0;
        
        while(pq.size()>0){
            struct path tp=pq.top();
            pq.pop();
            int mincost=tp.cost, u=tp.node, t=tp.time;
            
            if(u==n-1) return mincost;
            
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i].first, time=graph[u][i].second;
                int cost=fees[v];
                
                if(time+t<=maxTime){
                    if(amount[v]>mincost+cost){
                        amount[v]=mincost+cost;
                        timeTaken[v]=t+time;
                        p={amount[v],v,t+time};
                        pq.push(p);
                    }else if(t+time<timeTaken[v]){
                        timeTaken[v]=t+time;
                        p={mincost+cost,v,timeTaken[v]};
                        pq.push(p);
                    }
                }
            }
        }
        return -1;
    }
};
