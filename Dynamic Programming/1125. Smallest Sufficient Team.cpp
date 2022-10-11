Question Link: https://leetcode.com/problems/smallest-sufficient-team/


// Approach :
class Solution {
public:
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        map<string,int> skill_mask;
        for(int i=0;i<n;i++) skill_mask[req_skills[i]] = (1<<i);
        
        // dp[cur_skills] = min. set of people that can cover all skills represented in 'cur_skills'
        // transition: dp[cur_skills] = {min. set of people that can cover [cur_skills skills(cur_p)]} + cur_p 
        // base case: dp[all combinations of of skills(p)] = {p}
        
        vector<vector<int>> dp(1 << n);
        dp[0]={};
        
        vector<int> person_skills(people.size(),0); // skill mask of each person
        
        for(int i=0;i<people.size();i++){
            
            for(int j=0;j<people[i].size();j++){
                string cur_skill=people[i][j];
                person_skills[i] |= skill_mask[cur_skill];
            }
            
            // going through all possible combinations of required skills
            for(int j=0;j<(1<<n);j++){
                // check if set of skills 'j' is covered by person or not
                if((j & person_skills[i]) == j){
                    if(dp[j].size() == 0){
                        dp[j]={i};
                    }else{
                        int prev_person = dp[j][0];
                        if(person_skills[prev_person] > person_skills[i]) dp[j]={i};
                    } 
                }
            }
            
        }
        
        for(int i=0;i<(1<<n);i++){
            if(dp[i].size() > 0) continue; // 1 person can cover the required skills
            
            int best_new_p = -1;
            int min_num=people.size(); // minimum people required to cover 'i' skills combination
            for(int j=0;j<people.size();j++){
                int rem_skills = (i & ~person_skills[j]);
                int rem_num = dp[rem_skills].size();
                if(rem_num>0 && rem_num < min_num){
                    min_num = rem_num;
                    best_new_p = j;
                }
            }
            dp[i]=dp[(i & ~person_skills[best_new_p])];
            dp[i].push_back(best_new_p);
        }
        
        return dp[(1<<n)-1];
    }
};
