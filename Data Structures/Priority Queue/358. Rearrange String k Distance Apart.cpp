Question Link: https://leetcode.com/problems/rearrange-string-k-distance-apart/


// Approach :   
class Solution {
public:
    string rearrangeString(string s, int k) {
        
        if(k==0) return s;
        
        map<char,int> mp;
        for(int i=0;i<s.length();i++) mp[s[i]]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto it=mp.begin();it!=mp.end();it++) pq.push({it->second,it->first});
        
        string ans="";
        while(pq.size()>0){
            
            if(pq.size()<k && pq.top().first>1) return "";
            
            int size=pq.size();
            
            map<char,int> taken;
            
            for(int i=0;i<min(size,k);i++){
                pair<int,char> p=pq.top();
                pq.pop();
                
                int f=p.first;
                char ch=p.second;
                
                ans += ch;
    
                if(f>1) taken[ch]=f-1;
            }
            
            for(auto it=taken.begin();it!=taken.end();it++) pq.push({it->second,it->first});
        }
        return ans;
    }
};
