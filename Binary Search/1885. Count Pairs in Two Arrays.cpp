Question Link: https://leetcode.com/problems/count-pairs-in-two-arrays/


// Approach :
class Solution {
public:
    
    int search(vector<int> &diff, int l, int r){
        int val=diff[l-1];
        
        while(l<r){
            int m=l+(r-l)/2;
            
            if(diff[m]+val>0){
                r=m;
            }else{
                l=m+1;
            }
        }
        if(val+diff[l]<=0) l++;
        return l;
    }
    
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        
        // nums1[i]-nums2[i] + nums2[j]-nums1[j] > 0 or
        // diff[i] + diff[j] > 0
        vector<int> diff(n);
        for (int i=0;i<n;i++) diff[i]=nums1[i]-nums2[i];
        
        sort(diff.begin(), diff.end());
        
        long long cnt=0;
        for(int i=0;i<n-1;i++){
            int idx=search(diff,i+1,n-1);
            if(idx<n) cnt += n-idx;
        }
        return cnt;
    }
};
