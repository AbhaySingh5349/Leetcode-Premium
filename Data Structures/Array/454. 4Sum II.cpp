Question Link: https://leetcode.com/problems/4sum-ii/


// Approach :    
class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        vector<int> v;
        int n=a.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=a[i]+b[j];
                v.push_back(sum);
            }
        }
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=c[i]+d[j];
                mp[sum]++;
            }
        }
        
        int ans=0;
        for(int i=0;i<v.size();i++){
            int target=-v[i];
            if(mp.find(target)!=mp.end()) ans+=mp[target];
        } 
        return ans;
    }
};
