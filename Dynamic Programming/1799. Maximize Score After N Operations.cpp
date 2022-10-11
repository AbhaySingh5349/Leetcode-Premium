Question Link: https://leetcode.com/problems/maximize-score-after-n-operations/


// Approach :
class Solution {
public:
    
    int g(int a, int b){
        if(b==0) return a;
        
        return gcd(b,a%b);
    }
    
    map<string,int> m;
    int solve(vector<int>& a, int n, int k, int steps, int mask){
        if(steps==k+1) return 0;
        
        string state=to_string(steps)+"$"+to_string(mask);
        if(m.find(state)!=m.end()) return m[state];
        
        int ans=0;
        for(int i=0;i<n;i++){
            if((mask & (1<<i))==0){
                for(int j=i+1;j<n;j++){
                    if((mask & (1<<j))==0){
                        ans=max(ans,steps*g(a[i],a[j])+solve(a,n,k,steps+1,mask | ((1<<i)|(1<<j))));
                    }
                }
            }
        }
        return m[state]=ans;
    }
    int maxScore(vector<int>& a) {
        int n=a.size();
        int k=2*n;
        
        return solve(a,n,k,1,0);
    }
};
