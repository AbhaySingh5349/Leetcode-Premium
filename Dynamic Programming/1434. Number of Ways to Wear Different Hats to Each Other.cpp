Question Link: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/


// Approach :
class Solution {
public:
    map<pair<int,int>,int> mp;
    
    #define mod 1000000007
    
    int count(vector<int> hats[], int n, int h, int mask){
        if(mp.find({h,mask})!=mp.end()) return mp[{h,mask}];
        
        if(mask == ((1<<n)-1)) return 1;
        
        if(h>40) return 0;
        
        int ans=count(hats,n,h+1,mask);
        ans%=mod;
        
        if(hats[h].size()>0){
            vector<int> people=hats[h];
            for(int i=0;i<people.size();i++){
                int p=people[i];
                if((mask & (1<<p))==0){
                    ans+=count(hats,n,h+1,mask | (1<<p));
                    ans%=mod;
                }
            }
        }
        return mp[{h,mask}]=ans%mod;
    }
    
    int numberWays(vector<vector<int>>& person) {
        int n=person.size();
        vector<int> hats[41];
        for(int i=0;i<n;i++){
            for(int j=0;j<person[i].size();j++){
                hats[person[i][j]].push_back(i);
            }
        }
        return count(hats,n,0,0);
    }
};
