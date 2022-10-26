Question Link: https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/


// Approach :    
class Solution {
public:
    
    #define ll long long
    
    int maxSubArrayLen(vector<int>& a, int k) {
        int n=a.size();
        
        map<ll int,int> mp;
        mp[0]=-1;
        
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum += a[i];
            ll int target=(ll)sum-(ll)k;
            
            if(mp.find(target)!=mp.end()) ans=max(ans,i-mp[target]);
            
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return ans;
    }
};
