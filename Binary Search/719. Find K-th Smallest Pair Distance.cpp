Question Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/


// Approach :
class Solution {
public:
    
    bool possible(vector<int>& a, int k, int maxd){
        int n=a.size();
        int i=0, j=1;
        int c=0;
        while(j<n){
            while(i<=j && a[j]-a[i]>maxd) i++;
            c+=j-i;
            j++;
        }
        return (c>=k);
    }
    
    int smallestDistancePair(vector<int>& a, int k) {
        int n=a.size();
        sort(a.begin(),a.end());
        
        int l=0, r=a[n-1]-a[0];
        while(l<r){
            int m=l+(r-l)/2;
            if(possible(a,k,m)){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};
