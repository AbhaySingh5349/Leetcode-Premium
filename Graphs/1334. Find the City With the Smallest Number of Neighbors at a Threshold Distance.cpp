Question Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/


// Approach 1 (Floyd–Warshall algorithm):                                            
class Solution {
public:
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX/2));
        
        for(vector<int> edge:edges){
            int u=edge[0], v=edge[1], d=edge[2];
            distance[u][v] = distance[v][u] = d;
        }
        
        for(int i=0;i<n;i++) distance[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++) distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
        
        int neighbour=n, node=-1;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(i!=j && distance[i][j] <= distanceThreshold) c++;
            }

            if(c<=neighbour){
                neighbour=c;
                node=i;
            }
        } 
        
        return node;
    }
};


// Approach 2:
class Solution {
public:
    
    struct node{
        int vertex;
        int dist;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.dist > b.dist; // min. heap
        }
    };
    
    int count(int n, vector<pair<int,int>> graph[], int distanceThreshold, int src){
        
        vector<int> distance(n,INT_MAX/2);
        distance[src]=0;
        
        priority_queue<node,vector<node>,compare> pq;
        pq.push({src,0});
        
        while(pq.size()>0){
            struct node p=pq.top();
            pq.pop();
            
            int u=p.vertex, cur_d=p.dist;
            
            for(pair<int,int> edge:graph[u]){
                int v=edge.first, d=edge.second;
                
                if(distance[v]>d+cur_d){
                    distance[v]=d+cur_d;
                    pq.push({v,distance[v]});
                }
            }
        }
        
        int c=0;
        for(int i=0;i<n;i++){
            if(i == src) continue;
            if(distance[i] <= distanceThreshold) c++;
        }
        return c;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> graph[n];
        for(vector<int> edge:edges){
            int u=edge[0], v=edge[1], d=edge[2];
            graph[u].push_back({v,d});
            graph[v].push_back({u,d});
        }
        
        int neighbour=n, node=-1;
        for(int i=0;i<n;i++){
            int c=count(n,graph,distanceThreshold,i);
            if(c<=neighbour){
                neighbour=c;
                node=i;
            }
        } 
        
        return node;
    }
};
