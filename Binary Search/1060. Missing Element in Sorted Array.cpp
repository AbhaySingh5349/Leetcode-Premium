Question Link: https://leetcode.com/problems/missing-element-in-sorted-array/


// Approach 1:
class Solution {
public:
    int missingElement(vector<int>& a, int k) {
        int n=a.size();
        
        // leftmost element such that number of missing numbers until this element is less or equal to k.
        for(int i=1;i<n;i++){
            int missingBetween = a[i]-a[i-1]-1;
            if(missingBetween >= k) return a[i-1]+k;
            k -= missingBetween;
        }
        return a[n-1]+k;
    }
};


// Approach 2:
class Solution {
public:
    int missingElement(vector<int>& a, int k) {
        int n=a.size();
        
        int l=0, r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            
            int expectedIdx = a[m]-a[0];
            int missingCount = expectedIdx-m; // count of missing between a[0] --> a[m]
            
            if(missingCount>=k){
                r=m;
            }else{
                l=m+1;
            }
        }
        
        int expectedIdx = a[l]-a[0];
        int missingCount = expectedIdx-l;
        
        if(missingCount < k){
            return a[l]+(k-missingCount);
        }
        return a[l]+(k-missingCount-1);
    }
};
