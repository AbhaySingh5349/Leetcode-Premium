Question Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/


// Approach :
class Solution {
public:
    
    int solve(vector<int>& a, int l, int r, int k){
        if(l>r) return -1;
        while(l<r){
            int m=l+(r-l)/2;
            
            if(a[m]>=k){
                r=m;
            }else{
                l=m+1;
            }
        }
        return (a[l]==k ? l:-1);
    }
    
    int findPairs(vector<int>& a, int k) {
        int n=a.size();
        
        sort(a.begin(),a.end());
        
        int c=0;
        int i=0;
        while(i<n){
            int idx=solve(a,i+1,n-1,a[i]+k);
            if(idx!=-1) c++;
            i++;
            while(i<n && a[i]==a[i-1]) i++;
        }
        return c;
    }
};
