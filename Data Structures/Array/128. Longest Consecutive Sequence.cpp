Question Link: https://leetcode.com/problems/longest-consecutive-sequence/


// Approach :    
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n=a.size();
        if(n==0) return 0;
        
        int ans=1;
        
        map<int,bool> mp;
        for(int i=0;i<n;i++) mp[a[i]]=true;
        
        map<int,bool> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            int val=it->first;
            if(mp.find(val-1)!=mp.end()) mp[val]=false;
        }
        
        for(it=mp.begin();it!=mp.end();it++){
            int val=it->first;
            if(mp[val]==false) continue;
            int len=0;
            
            while(mp.find(val)!=mp.end()){
                len++;
                val++;
            }
            ans=max(ans,len);
        }
        
        return ans;
    }
};
