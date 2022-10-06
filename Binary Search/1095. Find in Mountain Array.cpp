Question Link: https://leetcode.com/problems/find-in-mountain-array/


// Approach :

/*
 // This is the MountainArray's API interface.
 class MountainArray {
    public:
    int get(int index);
    int length();
 };
*/

class Solution {
public:
    
    bool isPeak(MountainArray &a, int idx, int n){
        if(idx>0 && idx<n-1 && a.get(idx)>a.get(idx+1) && a.get(idx)>a.get(idx-1)) return true;
        return false;
    }
    
    int findPeakIndex(MountainArray &a, int n){
        int l=0, r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(isPeak(a,m,n)) return m;
            
            if(a.get(m)<a.get(m+1)){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return -1;
    }
    
    // increasing array
    int leftSearch(MountainArray &a, int k, int l, int r){
        while(l<=r){
            int m=l+(r-l)/2;
            
            int cur=a.get(m);
            if(cur>k){
                r=m-1;
            }else if(cur<k){
                l=m+1;
            }else{
                return m;
            }
        }
        return -1;
    }
    
    // decreasing array
    int rightSearch(MountainArray &a, int k, int l, int r){
        while(l<=r){
            int m=l+(r-l)/2;
            
            int cur=a.get(m);
            if(cur>k){
                l=m+1;
            }else if(cur<k){
                r=m-1;
            }else{
                return m;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int k, MountainArray &a) {
        int n=a.length();
        int mid=findPeakIndex(a,n);
        
        int lb=leftSearch(a,k,0,mid);
        if(lb!=-1) return lb;
        
        int rb=rightSearch(a,k,mid+1,n-1);
        if(rb!=-1) return rb;
        
        return -1;
    }
};
