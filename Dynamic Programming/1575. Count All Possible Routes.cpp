Question Link: https://leetcode.com/problems/count-all-possible-routes/


// Approach :
class Solution {
public:
    
    int memo[101][201];
    #define mod 1000000007
    
    int count(vector<int>& locations, int n, int start, int finish, int fuel){
        if(fuel<0) return 0;
        
        if(memo[start][fuel]!=-1) return memo[start][fuel];
        
        int ans=0;
        if(start==finish) ans+=1;
        
        for(int i=0;i<n;i++){
            if(i!=start){
                ans+=count(locations,n,i,finish,fuel-abs(locations[start]-locations[i]));
                ans%=mod;
            }
        }
        
        return memo[start][fuel]=ans%mod;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(memo,-1,sizeof(memo));
        int n=locations.size();
        return count(locations,n,start,finish,fuel);
    }
};
