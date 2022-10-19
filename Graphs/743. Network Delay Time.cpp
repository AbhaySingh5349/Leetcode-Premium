Question Link: https://leetcode.com/problems/network-delay-time/


// Approach 1 (Dijkstra's Algorithm): O(N+ElogN)   

--> N is the number of nodes and EE is the number of total edges in the given network.
--> Dijkstra's Algorithm : O(ElogN) + Finding the minimum time required in vector<int> time : O(N)
--> maximum number of vertices that could be added to priority queue is E. Thus, push and pop operations on priority queue O(logE) time.
--> value of E can be at most : N·(N-1) , Therefore, O(logE) is equivalent to O(log N^2)
--> Although number of vertices in the priority queue could be equal to E, we will only visit each vertex only once.
	If we encounter a vertex for the second time,
                                    
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        
        vector<pair<int,int>> graph[n+1];
        
        for(int i=0;i<times.size();i++){
            int u=times[i][0], v=times[i][1], w=times[i][2];
            
            graph[u].push_back({v,w});
        }
        
        vector<int> time(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,src});
        time[src]=0;
        while(pq.size()>0){
            pair<int,int> p=pq.top();
            pq.pop();
            
            int t=p.first, u=p.second;
            
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i].first, w=graph[u][i].second;
                
                if(time[v]>t+w){
                    time[v]=t+w;
                    pq.push({time[v],v});
                }
            }
        }
        
        int minTime=INT_MIN;
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX) return -1;
            minTime = max(minTime,time[i]);
        }
        return minTime;
    }
};



// Approach 2: O(N + N·E)

--> Each of N nodes can be added to the queue for all the edges connected to it, hence in a complete graph, the total number of operations would be O(NE)
--> Finding the minimum time required in vector<int> time : O(N)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        
        vector<pair<int,int>> graph[n+1];
        
        for(int i=0;i<times.size();i++){
            int u=times[i][0], v=times[i][1], w=times[i][2];
            
            graph[u].push_back({v,w});
        }
        
        vector<int> time(n+1,INT_MAX);
        queue<pair<int,int>> q;
        
        q.push({0,src});
        time[src]=0;
        while(q.size()>0){
            pair<int,int> p=q.front();
            q.pop();
            
            int t=p.first, u=p.second;
            
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i].first, w=graph[u][i].second;
                
                if(time[v]>t+w){
                    time[v]=t+w;
                    q.push({time[v],v});
                }
            }
        }
        
        int minTime=INT_MIN;
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX) return -1;
            minTime = max(minTime,time[i]);
        }
        return minTime;
    }
};
