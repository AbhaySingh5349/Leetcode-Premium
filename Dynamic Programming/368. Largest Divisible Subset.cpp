Question Link: https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    
    struct info{
        int idx, len, val;
    };
    
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        
        sort(a.begin(),a.end());
        
        vector<int> dp(n);
        int maxlen=0;
        
        struct info node;
        for(int i=0;i<n;i++){
            int len=1;
            for(int j=i-1;j>=0;j--){
                if(a[i]%a[j]==0){
                    len=max(len,dp[j]+1);
                }
            }
            dp[i]=len;
            if(len>maxlen){
                maxlen=len;
                node={i,len,a[i]};
            }
        }
        
        queue<info> q;
        q.push(node);
        
        vector<int> ans;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                node = q.front();
                q.pop();
                
                int i=node.idx, lis=node.len, val=node.val;
                ans.push_back(val);
                
                for(int j=i-1;j>=0;j--){
                    if(dp[j]==lis-1 && val%a[j]==0){
                        q.push({j,lis-1,a[j]});
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
