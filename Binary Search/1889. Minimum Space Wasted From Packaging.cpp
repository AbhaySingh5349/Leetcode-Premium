Question Link: https://leetcode.com/problems/minimum-space-wasted-from-packaging/


// Approach :
class Solution {
public:
    
    #define ll long long
    
    // max. index in 'packages' which can be packed with current box size
    int search(vector<int>& packages, int l, int r, int maxSize){
        while(l<r){
            int m=l+(r-l+1)/2;
            
            if(packages[m] <= maxSize){
                l=m;
            }else{
                r=m-1;
            }
        }
        return (packages[l] <= maxSize ? l:-1);
    }
    
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        
        int n=packages.size();
        vector<ll int> pre(n);
        pre[0]=packages[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1]+packages[i];
        
        ll int ans=LONG_MAX;
        
        for(vector<int> box:boxes){
            sort(box.begin(),box.end());
            
            // largest box cannot pack largest package
            if(box.back() < packages.back()) continue;
            
            int preIdx=-1; // index in packages who have been packed yet
            ll int wastedSpace=0;
            
            for(int size : box){
                int idx = search(packages,preIdx+1,n-1,size);
                if(idx==-1) continue;
                
                ll int spaceRequired = pre[idx] - (preIdx!=-1 ? pre[preIdx]:0);
                wastedSpace += (ll)(idx-preIdx)*(ll)size - (ll)spaceRequired;
                
                preIdx=idx;
                
                if(idx+1 == n) break;
            }
            if(ans>wastedSpace) ans=wastedSpace;
        }
        
        int mod=1e9+7;
        return (ans==LONG_MAX ? -1:ans%mod);
    }
};
