Question Link: https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/


// Approach :
class Solution {
public:
    
    int firstOccurance(vector<int>& a, int n, int target){
        int idx=-1;
        int l=0, r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(a[m]==target){
                idx=m;
                r=m-1;
            }else if(a[m]>target){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return idx;
    }
    
    int lastOccurance(vector<int>& a, int n, int target){
        int idx=-1;
        int l=0, r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(a[m]==target){
                idx=m;
                l=m+1;
            }else if(a[m]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return idx;
    }
    
    bool isMajorityElement(vector<int>& a, int target) {
        int n=a.size();
        int first=firstOccurance(a,n,target);
        int last=lastOccurance(a,n,target);
        
        return (first!=-1 && last!=-1 && last-first+1 > n/2);
    }
};
