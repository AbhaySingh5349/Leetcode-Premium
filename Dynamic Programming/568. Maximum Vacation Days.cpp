Question Link: https://leetcode.com/problems/maximum-vacation-days/


// Approach 1:
class Solution {
public:
    
    vector<vector<int>> memo;
    int solve(map<int,vector<int>> &mp, int city, int week, vector<vector<int>> &days){
        
        if(week == days[0].size()) return 0;
        
        if(memo[city][week]!=-1) return memo[city][week];
        
        // stay in current city
        int ans = days[city][week] + solve(mp,city,week+1,days);
        
        // move to other city
        for(int nxt_city : mp[city]){
            ans = max(ans, days[nxt_city][week] + solve(mp,nxt_city,week+1,days));
        }
        
        return memo[city][week]=ans;
    }
    
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n=flights.size(); // no. if cities
        map<int,vector<int>> mp; 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(flights[i][j]) mp[i].push_back(j); // (nxt cities can reach from current)
            } 
        }
        
        int m=days[0].size(); // no. of weeks
        memo.resize(n,vector<int>(m,-1));
        
        return solve(mp,0,0,days);
    }
};


// Approach 2:
class Solution {
public:
    
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n=flights.size(); // no. if cities
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(flights[i][j]) mp[j].push_back(i); // (prev cities that can make us reach current city)
            }
        }
        
        int m=days[0].size(); // no. of weeks
        
        vector<vector<int>> dp(n,vector<int>(m+1)); // dp[i,j] = max vacation days when i'm in the city i after j weeks
        for(int i=0;i<n;i++) dp[i][0]=INT_MIN;
        dp[0][0]=0;
        
        for(int week=1;week<m+1;week++){
            for(int city=0;city<n;city++){
                dp[city][week]=days[city][week-1]+dp[city][week-1]; // was already in current city
                
                for(int prev_city : mp[city]){
                    dp[city][week] = max(dp[city][week], days[city][week-1] + dp[prev_city][week-1]);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++) ans=max(ans, dp[i][m]);
        return ans;
    }
};
