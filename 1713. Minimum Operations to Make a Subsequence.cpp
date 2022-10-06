Question Link: https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/


// Approach :
class Solution {
public:
    
    int ceil(vector<int>& lis, int x){
        int l=0, r=lis.size()-1;
        while(l<r){
            int m=l+(r-l)/2;
            
            if(lis[m]>=x){
                r=m;
            }else{
                l=m+1;
            }
        }
        return (lis[l]>=x ? l:-1);
    }
    
    int minOperations(vector<int>& target, vector<int>& a) {
        int n=target.size(), m=a.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[target[i]]=i;
        
        vector<int> v;
        for(int i=0;i<m;i++){
            if(mp.find(a[i])!=mp.end()){
                v.push_back(mp[a[i]]);
            }
        }
        
        vector<int> lis;
        if(v.size()>0){
            lis.push_back(v[0]);
            for(int i=1;i<v.size();i++){
                int x=v[i], t=lis.back();

                if(x>t){
                    lis.push_back(x);
                }else{
                    int idx=ceil(lis,x);
                    if(idx!=-1) lis[idx]=x;
                }
            }
        }
        return n-lis.size();
    }
};
