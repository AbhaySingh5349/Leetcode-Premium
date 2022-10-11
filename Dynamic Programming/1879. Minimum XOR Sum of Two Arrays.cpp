Question Link: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/


// Approach :
class Solution {
public:
    
    map<string,int> m;
    int solve(vector<int>& a1, vector<int>& a2, int n, int idx, int mask){
        if(idx==n) return 0;
        
        string state=to_string(idx)+"$"+to_string(mask);
        if(m.find(state)!=m.end()) return m[state];
        
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            if((mask & (1<<j))==0) ans=min(ans,(a1[idx]^a2[j]) + solve(a1,a2,n,idx+1,mask | (1<<j)));
        }
        return m[state]=ans;
    }
    
    int minimumXORSum(vector<int>& a1, vector<int>& a2) {
        int n=a1.size();
        return solve(a1,a2,n,0,0);
    }
};
