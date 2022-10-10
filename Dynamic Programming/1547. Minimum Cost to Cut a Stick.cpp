Question Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/


// Approach 1:
class Solution {
public:
    map<pair<int,int>,int> m;
    
    int solve(vector<int>& cuts, int start, int end){
        if(m.find({start,end})!=m.end()) return m[{start,end}];
        
        bool can_cut=false;
        int ans=INT_MAX;
        for(int i=0;i<cuts.size();i++){
            if(cuts[i]>start && cuts[i]<end){
                can_cut=true;
                ans = min(ans, solve(cuts,start,cuts[i]) + solve(cuts,cuts[i],end) + end-start);
            }
        }
        if(!can_cut) return m[{start,end}]=0;
        
        return m[{start,end}]=ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        return solve(cuts,0,n);
    }
};


// Approach 2:
class Solution {
public:
    
    vector<vector<int>> memo;
    
    int solve(vector<int>& cuts, int i, int j){
        if(i>j) return 0;
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1]+solve(cuts,i,k-1)+solve(cuts,k+1,j);
            ans=min(ans,cost);
        }
        return memo[i][j]=ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        
        sort(cuts.begin(),cuts.end());
        
        int c=cuts.size();
        memo.resize(c,vector<int>(c,-1));
        return solve(cuts, 1, cuts.size()-2);
    }
};
