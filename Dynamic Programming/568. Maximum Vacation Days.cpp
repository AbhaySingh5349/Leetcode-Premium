Question Link: https://leetcode.com/problems/maximum-vacation-days/


// Approach :
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
                if(flights[i][j]) mp[i].push_back(j);
            }
        }
        
        int m=days[0].size(); // no. of weeks
        memo.resize(n,vector<int>(m,-1));
        
        return solve(mp,0,0,days);
    }
};
