Question Link: https://leetcode.com/problems/beautiful-arrangement/


// Approach :
class Solution {
public:
    
    map<string,int> mp;
    int solve(int n, int i, int mask){
        
        string state=to_string(i)+"$"+to_string(mask);
        if(mp.find(state)!=mp.end()) return mp[state];
        
        if(i==n+1 ) return 1;
        
        int ans=0;
        for(int num=1;num<=n;num++){
            if((mask & (1<<num))==0){
                if((num)%(i)==0 || (i)%(num)==0){
                    ans+=solve(n,i+1,mask | (1<<num));
                }
            }
        }
        return mp[state]=ans;
    }
    
    int countArrangement(int n) {
        
        return solve(n,1,0);
    }
};
