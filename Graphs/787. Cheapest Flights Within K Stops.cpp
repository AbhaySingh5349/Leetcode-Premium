Question Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/


// Approach :                                            
class Solution {
public:
    
    struct node{
        int cost;
        int u;
        int curStops;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.cost > b.cost;
        }
    };
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int vertices=n, edges=flights.size();
        vector<pair<int,int>> graph[n];
        int i,j;
        for(i=0;i<flights.size();i++){
            int u=flights[i][0], v=flights[i][1], w=flights[i][2];
            graph[u].push_back(make_pair(v,w));
        }
         
        priority_queue<node,vector<node>,compare> pq;
        struct node p={0,src,0};
        pq.push(p);
        
        vector<int> price(n,INT_MAX), stops(n,INT_MAX);
        price[src]=0, stops[src]=0;
        
        while(pq.size()>0){ // O(V^2 .log V)
            p=pq.top();
            pq.pop();
            int curCost=p.cost, u=p.u, curStops=p.curStops;
            
            if(u==dst) return curCost;
            if(curStops>k) continue;
            
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i].first, cost=graph[u][i].second;
                if(price[v]>curCost+cost){
                    price[v]=curCost+cost;
                    stops[v]=curStops+1;
                    p={price[v],v,stops[v]};
                    pq.push(p);
                }else if(stops[v]>curStops+1){
                    price[v]=curCost+cost;
                    stops[v]=curStops+1;
                    p={price[v],v,stops[v]};
                    pq.push(p);
                }
            }
        }
        return -1;
    }
};
